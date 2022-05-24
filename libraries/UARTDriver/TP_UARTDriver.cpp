#include <TP_UARTDriver.hpp>

void TP_UARTDriver::setup()
{
    /* step1：查找串口设备 */
    serial = rt_device_find(name);

    /* step2：修改串口配置参数 */
    config.baud_rate = BAUD_RATE_9600; //修改波特率为 9600
    config.data_bits = DATA_BITS_8; //数据位 8
    config.stop_bits = STOP_BITS_1; //停止位 1
    config.bufsz = 128; //修改缓冲区 buff size 为 128
    config.parity = PARITY_NONE; //无奇偶校验位

    /* step3：控制串口设备。通过控制接口传入命令控制字，与控制参数 */
    rt_device_control(serial, RT_DEVICE_CTRL_CONFIG, &config);

    /* step4：打开串口设备。以中断接收及轮询发送模式打开串口设备 */
    rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
}

void TP_UARTDriver::write(const char* str)
{
    rt_device_write(serial, 0, str, (sizeof(str) - 1));
}

int main(void)
{
    TP_UARTDriver serial1("uart2");

    serial1.write("ada\r\n");
}