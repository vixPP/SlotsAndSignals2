#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class StopWatch : public QObject
{
    Q_OBJECT

public:
    StopWatch(QObject *parent = nullptr);
    void start();
    void stop();
    void reset();
    int getMinutes() const;
    int getSeconds() const;
    int getMilliseconds() const;

signals:
    void timeUpdated();

private:
    QTimer *timer;
    int m, s, ms;
};

#endif
