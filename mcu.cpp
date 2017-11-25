#include "mcu.h"

#include "samd21.h"

void mcu::reset()
{
    NVIC_SystemReset();
    while (1) {}
}

void mcu::breakpoint()
{
#ifndef NDEBUG
    asm("BKPT #0");
#endif
}
