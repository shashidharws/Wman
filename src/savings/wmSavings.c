#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "savings.h"
#include "misc.h"
#define MAX_SCHEME_LEN 100

int addSavingsScheme(Savings *s, char *scheme, uint64_t investment)
{
    int err = 0;
    WMC_PTR(s);
    WMC_PTR(scheme);
    ASSIGN_STR(s->scheme, scheme);
    s->investment = investment;
    fillDate(&s->date);
Finally:
    return err;
}

uint64_t fetchSavingsFromCli(Savings *s)
{
    int err = 0;
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
    if(fgets(investment, 100, stdin) == NULL)
        perror("investment");
    else
        s->investment = atoi(investment);

    fillDate(&s->date);
Finally:
    return s->investment;
}

uint64_t addSavings(Savings *s)
{
    printf("Adding Savings\n");
    return fetchSavingsFromCli(s);
}

void printSavings(Savings s)
{
    printDate(s.date);
    printf(" : %s\b \t\t %lu \n", s.scheme, s.investment);
}

