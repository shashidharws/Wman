#ifndef __EARNINGS_H__
#define __EARNINGS_H__

#define MAX_OTHE_EARNINGS 10

typedef struct date {
    uint32_t day;
    uint32_t month;
    uint32_t year;
}Date;

typedef struct _salary {
    uint64_t amount;
    struct date date;
}Salary;

typedef struct _bonus {
    uint64_t amount;
    struct date date;
}Bonus;

typedef struct _othEarns {
    char *src;
    uint64_t amount;
    struct date date;
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
}Earnings;

#endif
