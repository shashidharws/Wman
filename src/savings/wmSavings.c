#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "savings.h"
#include "misc.h"
#define MAX_SCHEME_LEN 100

int addSavings(Savings *s, char *scheme, uint64_t investment)
{
    int err = 0;
    WMC_PTR(s);
    WMC_PTR(scheme);
    ASSIGN_STR(s->scheme, scheme);
    o->investment = investment;
    fillDate(&s->date);
Finally:
    return err;
}

int fetchSavingsFromCli(Savings *s)
{
    char scheme[MAX_SCHEME_LEN];
    char investment[10];
    printf("Enter saving scheme");
    printf("###################################\n");
    printf("Scheme Name:");
    if (fgets(scheme, 100, stdin) == NULL)
        perror("Scheme name");
    else
        ASSIGN_STR(s->scheme, scheme);

    printf("Investment:");
    if (fgets(investment, 100, stdin) == NULL)
        perror("investment");
    else
        s->investment = atoi(investment);
    return s->investment;
}

addSavings(Savings *s)
{
    Printf("Adding Savings\n");
    fetchSavingsFromCli(s);

}


