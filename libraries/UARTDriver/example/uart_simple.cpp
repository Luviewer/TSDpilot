#include <TP_UARTDriver.hpp>

#ifdef LIBS_UART_SIMPLE_TEST

#define SAMPLE_UART_NAME "uart3" /* 串口设备名称 */
static rt_device_t serial; /* 串口设备句柄 */
struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT; /* 初始化配置参数 */

int main(void)
{
    TP_UARTDriver serial1("uart3");

    serial1.setup();

    while (1) {
        serial1.write("ada\r\n");

        rt_thread_mdelay(1000);
    }
}

#endif