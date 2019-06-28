#include <stdio.h>
#include "earnings.h"

#define INVALID_PTR 1
#define CONDITION_FAIL 2
#define RET_FAIL 2
#define WMC_RET(call) \
{\
    if(call) {\
        printf("ERR: %s:%d\n", __func__, __LINE__);\
        err = RET_FAIL;\
        goto Finally;\
    }\
}

#define WMC_PTR(ptr) \
{\
    if(ptr == NULL) {\
        printf("ERR: %s:%d [INVALID PTR]\n", __func__, __LINE__);\
        err = INVALID_PTR;\
        goto Finally;\
    }\
}

#define ASSIGN_STR(ptr, str) \
{\
    WMC_PTR(str);\
    ptr = (char *) calloc(strlen(str) + 1, 1);\
    strncpy(ptr, str, strlen(str));\
}

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

int addSalary(salary *s, uint64_t amount)
{
    int err = 0;
    WMC_PTR(s);
    s.amount = amount;
    fillDate(&s->date);

Finally:
    return err;
}

int addBonus(bonus *b, uint64_t amount)
{
    int err = 0;
    WMC_PTR();
    b.amount = amount;
    fillDate(&b->date);
Finally:
    return err;
}

int addOthEarns(othEarns *o, char *src, uint64_t amount)
{
    int err = 0;
    WMC_PTR(o);
    WMC_PTR(type);
    ASSIGN_STR(o->src, src);
    o->amount = amount; 
    fillDate(&o->date);
Finally:
    return err;
}
