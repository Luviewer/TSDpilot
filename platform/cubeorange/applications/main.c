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

#include "vconsole.h"

/* defined the LED0 pin: PB1 */
#define LED0_PIN GET_PIN(E, 12)

int main(void) {

  while (1) {

    rt_pin_write(LED0_PIN, PIN_HIGH);
    rt_thread_mdelay(500);
    rt_pin_write(LED0_PIN, PIN_LOW);
    rt_thread_mdelay(500);
  }
}


