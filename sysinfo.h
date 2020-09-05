#ifndef SYSINFO_H
#define SYSINFO_H


class SysInfo
{

public:
    virtual void init() = 0;
    virtual double memoryUsed() = 0;
    virtual double cpuAvgLoad() = 0;

    virtual ~SysInfo();

    static SysInfo& instatnce();
protected:
    explicit SysInfo();
private:
    SysInfo(const SysInfo& rhs);
    SysInfo& operator=(const SysInfo& rhs);

};

#endif // SYSINFO_H
