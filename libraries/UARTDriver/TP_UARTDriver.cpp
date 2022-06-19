#include <TP_UARTDriver.hpp>

void TP_UARTDriver::setup()
{
    /* step1：查找串口设备 */
    serial = rt_device_find(name);

    /* step2：修改串口配置参数 */
    config.baud_rate = BAUD_RATE_115200; //修改波特率为 115200
    config.data_bits = DATA_BITS_8; //数据位 8
    config.stop_bits = STOP_BITS_1; //停止位 1
    config.bufsz = 128; //修改缓冲区 buff size 为 128
    config.parity = PARITY_NONE; //无奇偶校验位

    /* step3：控制串口设备。通过控制接口传入命令控制字，与控制参数 */
    rt_device_control(serial, RT_DEVICE_CTRL_CONFIG, &config);

    /* step4：打开串口设备。以中断接收及轮询发送模式打开串口设备 */
    rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
}

// void TP_UARTDriver::setup()
// {
//     /* 初始化消息队列 */
//     rt_mq_init(&rx_mq, "rx_mq",
//         msg_pool, /* 存放消息的缓冲区 */
//         sizeof(struct rx_msg), /* 一条消息的最大长度 */
//         sizeof(msg_pool), /* 存放消息的缓冲区大小 */
//         RT_IPC_FLAG_FIFO); /* 如果有多个线程等待，按照先来先得到的方法分配消息 */

//     /* 以 DMA 接收及轮询发送方式打开串口设备 */
//     rt_device_open(serial, RT_DEVICE_FLAG_DMA_RX);
//     /* 设置接收回调函数 */
//     rt_device_set_rx_indicate(serial, (this->uart_cb));
// }

void TP_UARTDriver::write(const char* str)
{
    rt_device_write(serial, 0, str, rt_strlen(str));
}

void TP_UARTDriver::open()
{
    rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
}

void TP_UARTDriver::close()
{
    rt_device_close(serial);
}

void TP_UARTDriver::setBuad(uint32_t buad)
{
    config.baud_rate = buad; //修改波特率为 115200

    rt_device_control(serial, RT_DEVICE_CTRL_CONFIG, &config);
}

/* 接收数据回调函数 */
rt_err_t TP_UARTDriver::uart_cb(rt_device_t dev, rt_size_t size)
{
    struct rx_msg msg;
    rt_err_t result;
    msg.dev = dev;
    msg.size = size;

    result = rt_mq_send(&rx_mq, &msg, sizeof(msg));
    if (result == -RT_EFULL) {
        /* 消息队列满 */
        rt_kprintf("message queue full！\n");
    }
    return result;
}
