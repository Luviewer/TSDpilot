#include <rtdevice.h>
#include <rthw.h>
#include <rtthread.h>

using namespace rtthread;

class TP_UARTDriver {
public:
    TP_UARTDriver(const char* _name, bool useDMA = false)
        : config(RT_SERIAL_CONFIG_DEFAULT)
        , name(_name)
    {
    }

    /* 串口接收消息结构*/
    struct rx_msg {
        rt_device_t dev;
        rt_size_t size;
    };

    void setup();

    void write(const char* str);

    void open();

    void close();

    void setBuad(uint32_t buad);

    rt_err_t uart_cb(rt_device_t dev, rt_size_t size);

protected:
    rt_device_t serial; /* 串口设备句柄 */

    const char* name; /* 串口设备名称 */

    struct serial_configure config; /* 配置参数 */

    bool useDMA;

    char msg_pool[256];

    struct rt_messagequeue rx_mq; /* 消息队列控制块 */

    char rx_buffer[RT_SERIAL_RB_BUFSZ + 1];
};