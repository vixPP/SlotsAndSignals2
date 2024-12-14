#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lapTime = 0;
    lapCount = 0;
    stopWatch = new StopWatch(this);

    connect(stopWatch, &StopWatch::timeUpdated, this, [this]()
    {
        ui->label_m->setText(QString::number(stopWatch->getMinutes()) + "   :");
        ui->label_S->setText(QString::number(stopWatch->getSeconds()) + "   :");
        ui->label_ms->setText(QString::number(stopWatch->getMilliseconds()));
    });

    ui->pushButton_start->setText("СТАРТ");
    ui->pushButton_reset->setText("СБРОС");
    ui->pushButton->setText("КРУГ");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_start_clicked()
{
    flag = !flag;
    if(flag)
    {
        ui->pushButton_start->setText("СТАРТ");
        stopWatch->stop();
    }
    else
    {
        ui->pushButton_start->setText("СТОП");
        stopWatch->start();
    }
}

void MainWindow::on_pushButton_reset_clicked()
{
    stopWatch->reset();

    ui->label_m->setText(QString::number(stopWatch->getMinutes()) + "   :");
    ui->label_S->setText(QString::number(stopWatch->getSeconds()) + "   :");
    ui->label_ms->setText(QString::number(stopWatch->getMilliseconds()));

    ui->textBrowser->clear();
}

void MainWindow::on_pushButton_clicked()
{
    lapCount++;
    lapTime = stopWatch->getMinutes() * 60 + stopWatch->getSeconds() + stopWatch->getMilliseconds() / 1000.0;


    if (lapCount == 1)
    {
        timeSinceLastLap = lapTime;
    } else
    {
        timeSinceLastLap = lapTime - previousLapTime;
    }

    previousLapTime = lapTime;
    ui->textBrowser->append(QString("Круг %1, время: %2 сек").arg(lapCount).arg(timeSinceLastLap));
}

