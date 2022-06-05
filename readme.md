 > TSDPilot以rt-thread为操作系统，支持多种不同的硬件平台，也可以根据实际情况添加硬件平台，在`platform`文件夹下面，目前支持的平台有：cubeorange、cuavv5plus    

# 1. 下载源码
`git clone https://gitee.com/Luviewer/TSDpilot.git --recursive ` or  `git clone https://github.com/Luviewer/TSDpilot.git --recursive`        

# 2. 编译（以cubeorange为例）

1. `cd platform`    
2. `cd cubeorange`   
3. `scons -j4`

# 3. 下载（支持命令行下载、QGC下载、MISSIONPLANNER下载）
1. 命令行下载：`python upload`

# 4. 高级配置（以cubeorange为例）
TSDPilot支持高级配置，可以根据实际硬件和需求调整外设，通过menuconfig进行配置
1. `cd platform`    
2. `cd cubeorange`   
3. `scons --menuconfig`

* menuconfig需要有kconfig的配置基础，可参考rt-thread文档进行学习
