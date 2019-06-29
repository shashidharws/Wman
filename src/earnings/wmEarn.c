#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "earnings.h"
#include "misc.h"

int addSalary(Salary *s, uint64_t amount)
{
    int err = 0;
    WMC_PTR(s);
    s->amount = amount;
    fillDate(&s->date);

Finally:
    return err;
}

int addBonus(Bonus *b, uint64_t amount)
{
    int err = 0;
    WMC_PTR(b);
    b->amount = amount;
    fillDate(&b->date);
Finally:
    return err;
}

int addOthEarns(OthEarns *o, char *src, uint64_t amount)
{
    int err = 0;
    WMC_PTR(o);
    WMC_PTR(src);
    ASSIGN_STR(o->src, src);
    o->amount = amount; 
    fillDate(&o->date);
Finally:
    return err;
}

int createEarns(Earnings *e)
{
    e->nOthEarns = 0;
}
