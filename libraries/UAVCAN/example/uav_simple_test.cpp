#include <TP_UARTDriver.hpp>

// #include "libcanard/canard.h"

#ifdef LIBS_UAVCAN_SIMPLE_TEST

int main(void)
{
    TP_UARTDriver serial1("uart3");

    serial1.setup();

    serial1.write("uavcan test!!!\r\n");

    rt_thread_mdelay(1000);

    while (1) {
    }
}

#endif