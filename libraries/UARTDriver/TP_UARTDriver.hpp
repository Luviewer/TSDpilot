#include <rtdevice.h>
#include <rthw.h>
#include <rtthread.h>

using namespace rtthread;

class TP_UARTDriver {
public:
    TP_UARTDriver(const char* _name)
        : config(RT_SERIAL_CONFIG_DEFAULT)
        , name(_name)
    {
    }

    void setup();

    void write(const char* str);

protected:
    rt_device_t serial; /* 串口设备句柄 */
    const char* name; /* 串口设备名称 */
    struct serial_configure config; /* 配置参数 */
};