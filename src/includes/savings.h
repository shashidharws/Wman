#ifndef __SAVINGS_H__
#define __SAVINGS_H__

#include "misc.h"
#define MAX_SAVINGS 10
typedef struct _savings {
    char *scheme;
    uint64_t investment;
    uint64_t totalInvestments;
    int interestEarned;
    Date date;
}Savings;

uint64_t addSavings(Savings *s);
void printSavings(Savings s);
#endif
