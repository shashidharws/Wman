#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include "misc.h"

void fillDate(Date *d)
{
    struct timeval tv;
    struct tm *now;
    gettimeofday(&tv, NULL);
    now = gmtime(&tv.tv_sec);
    d->month = now->tm_mon;
    d->year = now->tm_year + 1900;
    d->day = now->tm_wday;
}


