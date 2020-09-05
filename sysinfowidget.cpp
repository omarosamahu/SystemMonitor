#include "sysinfowidget.h"
// QT
#include <QVBoxLayout>



SysInfoWidget::SysInfoWidget(QWidget *parent
                             ,int startDelay
                             ,int upDateDelay):QWidget(parent),mChartView(this)
{
       // Timer
       mRefresh.setInterval(upDateDelay);
       connect(&mRefresh,&QTimer::timeout,this,&SysInfoWidget::updateSeries);
       // Start timer after a specific delay
       QTimer::singleShot(startDelay,[this]{
           return mRefresh.start();
       });
       // Widget
       mChartView.setRenderHint(QPainter::Antialiasing);
       mChartView.chart()->legend()->setVisible(false);

       QVBoxLayout* layout = new QVBoxLayout(this);
       layout->addWidget(&mChartView);
       setLayout(layout);
}



QChartView& SysInfoWidget::chartView(){
    return mChartView;
}
