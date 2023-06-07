#include "app.h"

void AfterOsInitDone(void)
{
    // TODO
}

TaskDefineEx("main task", Task_Main, 256, 0, NULL)
{
    while (1) {
        OSTimeDly(500);
    }
}

TaskDefine(Task_WorkIndicator, 1, NULL)
{
    while (1) {
        LED_WorkIndicator_Toggle();
        OSTimeDly(500);
    }
}
