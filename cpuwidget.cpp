#include "cpuwidget.h"

CpuWidget::CpuWidget(QWidget *parent):
    SysInfoWidget(parent),
    mSeries(new QtCharts::QPieSeries(this))
{

    mSeries->setHoleSize(0.35);
    mSeries->append("CPU Load", 30.0);
    mSeries->append("CPU Free", 70.0);

    QChart* chart = chartView().chart();
    chart->addSeries(mSeries);
    chart->setTitle("CPU Average Load");
}

void CpuWidget::updateSeries(){

}
