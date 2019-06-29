#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "savings.h"
#include "misc.h"

int addSavings(savings *s, char *scheme, uint64_t monthly_invested)
{
    int err = 0;
    WMC_PTR(s);
    WMC_PTR(scheme);
    ASSIGN_STR(s->scheme, scheme);
    o->monthly_invested = monthly_invested;
    fillDate(&s->date);
Finally:
    return err;
}
