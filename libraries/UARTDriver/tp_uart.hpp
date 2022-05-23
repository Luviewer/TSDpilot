#include <rthw.h>
#include <rtthread.h>
#include <rtdevice.h>

using namespace rtthread;

class TP_UARTDriver {
public:
  TP_UARTDriver(const char *_name) {}

  void setup();

protected:
  rt_device_t serial;             /* 串口设备句柄 */
  char *name;                     /* 串口设备名称 */
  struct serial_configure config; /* 配置参数 */
};