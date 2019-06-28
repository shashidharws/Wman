#include <stdio.h>
#include "earnings.h"

#define INVALID_PTR 1
#define CONDITION_FAIL 2
#define WNC(condition) \
{\
    if(condition) {\
        printf("ERR: %s:%d\n", __func__, __LINE__);\
        err = CONDITION_FAIL;
        goto Finally;\
    }\
}

#define WNC_PTR(ptr) \
{\
    if(ptr == NULL) {\
        printf("ERR: %s:%d [INVALID PTR]\n", __func__, __LINE__);\
        err = INVALID_PTR;\
        goto Finally;\
    }\
}

#define ASSIGN_STR(ptr, str) \
{\
    WNC_PTR(str);\
    ptr = (char *) calloc(strlen(str) + 1, 1);\
    strncpy(ptr, str, strlen(str));\
}


int addSalary(salary *s, uint64_t amount)
{
    int err = 0;
    WNC_PTR(s);
    s.amount = amount;
    fillDate(s->date);

Finally:
    return err;
}

int addBonus(bonus *b, uint64_t amount)
{
    int err = 0;
    WNC_PTR();
    b.amount = amount;
    fillDate(b->date);
Finally:
    return err;
}

int addOthEarns(othEarns *o, char *src, uint64_t amount)
{
    int err = 0;
    WNC_PTR(o);
    WNC_PTR(type);
    ASSIGN_STR(o->src, src);
    o->amount = amount; 
Finally:
    return err;
}
