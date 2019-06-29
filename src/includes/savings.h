#ifndef __SAVINGS_H__
#define __SAVINGS_H__

typedef struct _savings {
    char *scheme;
    uint64_t investment;
    uint64_t totalInvestments;
    int interestEarned;
    Date date;
}Savings;


#endif
