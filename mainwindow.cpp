#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mCpuwidget(this)
{
    ui->setupUi(this);
    SysInfo::instatnce().init();
    ui->cpulayout->layout()->addWidget(&mCpuwidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}
