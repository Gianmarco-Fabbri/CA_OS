#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TASK_PERIOD_MS     500
#define DEADLINE_TIMER_ID  1

TaskHandle_t xTaskHandle = NULL;
TimerHandle_t xDeadlineTimer = NULL;

void vDeadlineCallback(TimerHandle_t xTimer) {
    if ((uint32_t)pvTimerGetTimerID(xTimer) == DEADLINE_TIMER_ID) {
        printf("⚠️  Deadline missed by task!\n");
    }
}

void vPeriodicTask(void *pvParameters) {
    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xTaskPeriod = pdMS_TO_TICKS(TASK_PERIOD_MS);

    while (1) {
        // Restart the deadline timer
        xTimerStart(xDeadlineTimer, 0);

        // Generate random duration between 1 and 600 ms
        int wait_time = (rand() % 600) + 1;
        printf("Task started, busy waiting for %d ms\n", wait_time);

        TickType_t wait_ticks = pdMS_TO_TICKS(wait_time);
        TickType_t start = xTaskGetTickCount();
        while ((xTaskGetTickCount() - start) < wait_ticks) {
            // Busy wait
        }

        // If task completed within deadline, stop the timer
        xTimerStop(xDeadlineTimer, 0);
        printf("Task completed\n");

        vTaskDelayUntil(&xLastWakeTime, xTaskPeriod);
    }
}

int main(void) {
    srand((unsigned int)time(NULL)); // Seed random number generator

    xDeadlineTimer = xTimerCreate("DeadlineTimer",
                                  pdMS_TO_TICKS(TASK_PERIOD_MS),
                                  pdFALSE,
                                  (void *)DEADLINE_TIMER_ID,
                                  vDeadlineCallback);

    if (xDeadlineTimer == NULL) {
        printf("Failed to create deadline timer\n");
        while (1);
    }

    BaseType_t res = xTaskCreate(vPeriodicTask, "PeriodicTask", configMINIMAL_STACK_SIZE + 100, NULL, 1, &xTaskHandle);
    if (res != pdPASS) {
        printf("Task creation failed\n");
        while (1);
    }

    vTaskStartScheduler();

    for (;;); // Should never reach here
    return 0;
}
