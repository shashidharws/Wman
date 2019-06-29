#ifndef __PROFILE_H__
#define __PROFILE_H__
#define MAX_FAMILY_MEMEBERS 10

#include "profile.h"
#include "earnings.h"

typedef struct _user {
    char *name;
    Earnings earns;
    //Savings s;
    //Expenses exps;
}User;

typedef struct _family {
    User *u[MAX_FAMILY_MEMEBERS];
    int nMembers;
    int club;
}Family;

#endif
