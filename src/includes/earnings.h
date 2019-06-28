#ifndef __EARNINGS_H__
#define __EARNINGS_H__

#define MAX_OTHE_EARNINGS 10

struct date {
    uint32_t day;
    uint32_t month;
    uint32_t year;
};

typedef struct _salary {
    uint64_t amount;
    struct date date;
}salary;

typedef struct _bonus {
    uint64_t amount;
    struct date date;
}bonus;

typedef struct _othEarns {
    char *src;
    uint64_t amount;
    struct date date;
}othEarns;


/**
  * s : salary earned
  * b : bonus earned
  * o : other earnings
  */
typedef struct _earnings {
    salary s;
    bonus b;
    othEarns o[MAX_OTHE_EARNINGS];
}earnings;

#endif
