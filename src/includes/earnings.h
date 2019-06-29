#ifndef __EARNINGS_H__
#define __EARNINGS_H__
#include <inttypes.h>
#include <sys/types.h>
#include "misc.h"
#define MAX_OTHE_EARNINGS 10

typedef struct _salary {
    uint64_t amount;
    Date date;
}Salary;

typedef struct _bonus {
    uint64_t amount;
    Date date;
}Bonus;

typedef struct _othEarns {
    char *src;
    uint64_t amount;
    Date date;
}OthEarns;


/**
  * s : salary earned
  * b : bonus earned
  * o : other earnings
  */
typedef struct _earnings {
    Salary s;
    Bonus b;
    OthEarns o[MAX_OTHE_EARNINGS];
    int nOthEarns;
}Earnings;

#endif
