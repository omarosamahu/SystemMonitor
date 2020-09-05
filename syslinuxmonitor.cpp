#include "syslinuxmonitor.h"
#include <sys/sysinfo.h>
#include <sys/types.h>
SysLinuxMonitor::SysLinuxMonitor()
    :SysInfo(),cpuLastLoad()
{

}

void SysLinuxMonitor::init(){
    cpuLastLoad = cpuRawData();
}

double SysLinuxMonitor::memoryUsed(){
    struct sysinfo memInfo;
    sysinfo(&memInfo);

    auto totalMemory = (memInfo.totalram +  memInfo.totalswap) * memInfo.mem_unit;
    auto freeMemory  =  (memInfo.freeram  +  memInfo.freeswap) * memInfo.mem_unit;
    auto memoryUsage = totalMemory - freeMemory;
    auto percent = (double)memoryUsage / (double)totalMemory * 100.0;

    return qBound(0.0,percent,100.0);
}


QVector<qulonglong> SysLinuxMonitor::cpuRawData(){
    QFile file("/proc/stat");
    file.open(QIODevice::ReadOnly);
    QByteArray line = file.readLine();
    file.close();
    qulonglong usernormal = 0,usernice = 0,idle = 0,kernel = 0;
    std::sscanf(line.data(),"cpu %llu %llu %llu %llu",&usernormal,&usernice,&kernel,&idle);


    QVector<qulonglong> rawData;

    rawData.append(usernormal);
    rawData.append(usernice);
    rawData.append(kernel);
    rawData.append(idle);

    return rawData;
}

double SysLinuxMonitor::cpuAvgLoad(){
    auto firstSample = cpuLastLoad;
    auto seconedSample = cpuRawData();

    auto a0 = seconedSample[0] - firstSample[0];
    auto a1 = seconedSample[1] - firstSample[1];
    auto a2 = seconedSample[2] - firstSample[2];
    auto a3 = seconedSample[3] - firstSample[3];

    auto overAll = a0 + a1 + a2;
    auto total = overAll + a3;

    double percent = (double)overAll / (double)total * 100.0;

    return qBound(0.0,percent,100.0);
}
