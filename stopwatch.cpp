#include "stopwatch.h"

StopWatch::StopWatch(QObject *parent)
    : QObject(parent), m(0), s(0), ms(0)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this]()
    {
        ms++;
        if (ms >= 1000)
        {
            ms = 0;
            s++;
        }
        if (s >= 60)
        {
            s = 0;
            m++;
        }
        emit timeUpdated();
    });
}

void StopWatch::start()
{
    timer->start(1);
}

void StopWatch::stop()
{
    timer->stop();
}

void StopWatch::reset()
{
    m = 0;
    s = 0;
    ms = 0;
}

int StopWatch::getMinutes() const { return m; }
int StopWatch::getSeconds() const { return s; }
int StopWatch::getMilliseconds() const { return ms; }
