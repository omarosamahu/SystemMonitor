#include "sysinfo.h"

//#ifdef Q_OS_LINUX
//#endif

#include "syslinuxmonitor.h"

SysInfo::SysInfo()
{

}

SysInfo::~SysInfo(){

}
SysInfo& SysInfo::instatnce(){

    static SysLinuxMonitor singelton;

    return singelton;
}
