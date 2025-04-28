// https://github.com/keenigithub/SimpleCppDelay

#ifndef DELAY
#define DELAY

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;
using namespace chrono;

void delayms(int msec)
{
    sleep_for(milliseconds(msec));
}

void delaysc(int sec)
{
    sleep_for(seconds(sec));
}

void delaymn(int min)
{
    sleep_for(minutes(min));
}

void delayhr(int hour)
{
    sleep_for(hours(hour));
}

#endif