#ifndef __SAVINGS_H__
#define __SAVINGS_H__

typedef struct _savings {
    char *scheme;
    uint64_t yearly_invested;
    uint64_t monthly_invested;
    uint64_t total_investments;
    int interest_earned;
    Date date;
}Savings;


#endif
