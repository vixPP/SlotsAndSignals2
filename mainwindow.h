#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "stopwatch.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    StopWatch *stopWatch;
    bool flag = true;
    int lapTime, lapCount, previousLapTime, timeSinceLastLap;

private slots:

    void on_pushButton_start_clicked();
    void on_pushButton_reset_clicked();
    void on_pushButton_clicked();
};
#endif
