#ifndef SYSINFOWIDGET_H
#define SYSINFOWIDGET_H

// Qt
#include <QWidget>
#include <QTimer>
#include <QtCharts/QChartView>


using namespace QtCharts;

class SysInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SysInfoWidget(QWidget *parent = nullptr
            ,int startDelay = 500
            ,int updateSeriesDelay = 500);

protected:
    QChartView& chartView();

protected slots:
       virtual void updateSeries() = 0;

private:
    QTimer mRefresh;
    QChartView mChartView;
};

#endif // SYSINFOWIDGET_H
