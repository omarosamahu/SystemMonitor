#ifndef SYSLINUXMONITOR_H
#define SYSLINUXMONITOR_H

#include "sysinfo.h"
// QT
#include <QtGlobal>
#include <QVector>
#include <QFile>
#include <QString>

class SysLinuxMonitor : public SysInfo
{
public:
    SysLinuxMonitor();
    //~SysLinuxMonitor();
    // SysInfo interface
public:
    void init() override;
    double memoryUsed() override;
    double cpuAvgLoad() override;
private:
    QVector<qulonglong> cpuRawData();
private:
    QVector<qulonglong> cpuLastLoad;
};

#endif // SYSLINUXMONITOR_H
