#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt
#include <QMainWindow>
// Internal
#include "cpuwidget.h"
#include "sysinfo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CpuWidget mCpuwidget;
    //CpuWidget CpuWidget;
};

#endif // MAINWINDOW_H
