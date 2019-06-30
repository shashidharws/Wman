#ifndef __PROFILE_H__
#define __PROFILE_H__
#define MAX_FAMILY_MEMEBERS 10

#include "misc.h"
#include "profile.h"
#include "earnings.h"
#include "savings.h"
#include "expenses.h"


typedef struct _user {
    char *name;
    Earnings earns;
    Savings s[MAX_SAVINGS];
    int nSavings;
    Expenses exps;
    uint64_t balance;
}User;

typedef struct _family {
    User *u[MAX_FAMILY_MEMEBERS];
    int nMembers;
    int club;
}Family;

User *createUser(char *name);
int addUserEarnings(User *u);
int addUserSavings(User *u);
int addUserExpenses(User *u);
void printAllMySavings(User *u);
#endif
