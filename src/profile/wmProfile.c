#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "profile.h"
#include "misc.h"
#include "earnings.h"
#include "savings.h"

User *createUser(char *name)
{
    int err = 0;
    User *u = calloc(sizeof(User), 1);
    ASSIGN_STR(u->name, name);
Finally:
    return u;
}

int createFamily(Family *f)
{
    f->nMembers = 0;
}

int addUserToFamily(Family *f, char *name)
{
    f->u[f->nMembers] = createUser(name);
}

int addUserEarnings(User *u)
{
    u->balance += addEarnings(&u->earns);
}

int addUserSavings(User *u)
{
    u->balance -= addSavings(&u->s[u->nSavings]);
    u->nSavings++;
}

int addUserExpenses(User *u)
{
    u->balance -= addExpenses(&u->exps); 
}
