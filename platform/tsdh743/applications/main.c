/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-03-05     whj4674672   first version
 */

#include <board.h>
#include <rtdevice.h>
#include <rtthread.h>

/* defined the LED0 pin: PB1 */
#define LED0_PIN GET_PIN(B, 12)
#define LED1_PIN GET_PIN(B, 13)

int main(void)
{
    rt_device_t dev = RT_NULL;
    char buf[] = "hello rt-thread!\r\n";

    dev = rt_device_find("vcom");

    if (dev)
        rt_device_open(dev, RT_DEVICE_FLAG_RDWR);
    else
        return -RT_ERROR;

    /* set LED0 pin mode to output */
    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LED1_PIN, PIN_MODE_OUTPUT);

    while (1) {
        rt_device_write(dev, 0, buf, rt_strlen(buf));

        rt_pin_write(LED0_PIN, PIN_HIGH);
        rt_pin_write(LED1_PIN, PIN_LOW);
        rt_thread_mdelay(500);
        rt_pin_write(LED0_PIN, PIN_LOW);
        rt_pin_write(LED1_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
    }
}
