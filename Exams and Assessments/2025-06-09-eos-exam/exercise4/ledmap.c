#include <linux/cdev.h> 
#include <linux/fs.h> 
#include <linux/init.h> 
#include <linux/ioctl.h> 
#include <linux/module.h> 
#include <linux/slab.h> 
#include <linux/uaccess.h> 
#include <linux/version.h> 

#define LEDMAP_BASE_ADDRESS  0x00080000

uint32_t bit_reg = 0x0;

//function to control the device
static long ledmap_ioctl(struct file *filp, unsigned int cmd, 
                             unsigned long arg) 
{ 
    struct test_ioctl_data *ioctl_data = filp->private_data; 
    int retval = 0; 
    unsigned char val; 
    struct ioctl_arg data; 
    memset(&data, 0, sizeof(data)); 
 
    switch (cmd) { 
    case LEDMAP_ENABLE: 
        //copy from user space to kernel space
        if (copy_from_user(&data, (int __user *)arg, sizeof(data))) { 
            retval = -EFAULT; 
            goto done; 
        } 
 
        if(arg==0){
          pr_alert("disable bit\n", data.val); 
          //disable bit
          bit_reg &= 0x11111110;
        }
        else{
           pr_alert("enable bit\n", data.val); 

          //enable bit
          bit_reg |= 0x00000001;
        }
        break; 
 
    case LEDMAP_SETCOLOUR: 
        if (copy_from_user(&data, (int __user *)arg, sizeof(data))) { 
            retval = -EFAULT; 
            goto done; 
        } 
        pr_alert("set colour %i", arg);
        bit_reg = (bit_reg & 0xFF9) | (arg<<1) //set colour value on the bits 1 and 2
 
        break; 
 
    case LEDMAP_SETBLINK: 
        if (copy_from_user(&data, (int __user *)arg, sizeof(data))) { 
            retval = -EFAULT; 
            goto done; 
        } 
        if(arg==0){
          pr_alert("disable blink\n", data.val); 
          //disable bit 3
          bit_reg &= 0x11111117;
        }
        else{
           pr_alert("enable blink\n", data.val); 

          //enable bit 3
          bit_reg |= 0x00000008;
        }
        break; 
 
    case LEDMAP_BLINKRATE: 
        if (copy_from_user(&data, (int __user *)arg, sizeof(data))) { 
            retval = -EFAULT; 
            goto done; 
        } 
         bit_reg = (bit_reg & 0x1E0) | arg<<5;
        break; 
 
    case LEDMAP_INTENSITY: 
        if (copy_from_user(&data, (int __user *)arg, sizeof(data))) { 
            retval = -EFAULT; 
            goto done; 
        } 
        bit_reg = (bit_reg & 0xF00) | arg<<9;
        break; 
    default: 
        retval = -ENOTTY; 
    } 
 
done: 
    return retval; 
} 


static ssize_t ledmap_read(struct file *filp, char __user *buf, 
                               size_t count, loff_t *f_pos) 
{ 
    struct test_ioctl_data *ioctl_data = filp->private_data; 
    unsigned char val; 
    int retval; 
    int i = 0; 
 
    read_lock(&ioctl_data->lock); 
    val = ioctl_data->val; 
    read_unlock(&ioctl_data->lock); 
 
    for (; i < count; i++) { 
        if (copy_to_user(&buf[i], &val, 1)) { 
            retval = -EFAULT; 
            goto out; 
        } 
    } 
 
    retval = count; 
out: 
    return retval; 
} 
 
static int ledmap_close(struct inode *inode, struct file *filp) 
{ 
    pr_alert("%s call.\n", __func__); 
 
    if (filp->private_data) { 
        kfree(filp->private_data); 
        filp->private_data = NULL; 
    } 
 
    return 0; 
} 
 
static int ledmap_open(struct inode *inode, struct file *filp) 
{ 
    struct test_ioctl_data *ioctl_data; 
 
    pr_alert("%s call.\n", __func__); 
    ioctl_data = kmalloc(sizeof(struct test_ioctl_data), GFP_KERNEL); 
 
    if (ioctl_data == NULL) 
        return -ENOMEM; 
 
    rwlock_init(&ioctl_data->lock); 
    ioctl_data->val = 0xFF; 
    filp->private_data = ioctl_data; 
 
    return 0; 
} 
 
static struct file_operations fops = { 
#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 4, 0) 
    .owner = THIS_MODULE, 
#endif 
    .open = ledmap_open, 
    .release = ledmap_close, 
    .read = ledmap_read, 
    .unlocked_ioctl = ledmap_ioctl, 
}; 
 
static int __init ledmap_init(void) 
{ 
    dev_t dev; 
    int alloc_ret = -1; 
    int cdev_ret = -1; 
    alloc_ret = alloc_chrdev_region(&dev, 0, num_of_dev, DRIVER_NAME); 
 
    if (alloc_ret) 
        goto error; 
 
    test_ioctl_major = MAJOR(dev); 
    cdev_init(&test_ioctl_cdev, &fops); 
    cdev_ret = cdev_add(&test_ioctl_cdev, dev, num_of_dev); 
 
    if (cdev_ret) 
        goto error; 
 
    pr_alert("%s driver(major: %d) installed.\n", DRIVER_NAME, 
             test_ioctl_major); 
    return 0; 
error: 
    if (cdev_ret == 0) 
        cdev_del(&test_ioctl_cdev); 
    if (alloc_ret == 0) 
        unregister_chrdev_region(dev, num_of_dev); 
    return -1; 
} 
 
static void __exit ledmap_exit(void) 
{ 
    dev_t dev = MKDEV(test_ioctl_major, 0); 
 
    cdev_del(&test_ioctl_cdev); 
    unregister_chrdev_region(dev, num_of_dev); 
    pr_alert("%s driver removed.\n", DRIVER_NAME); 
} 
 
module_init(ledmap_init); 
module_exit(ledmap_exit); 
 
MODULE_LICENSE("GPL");
