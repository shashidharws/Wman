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
    src[strlen(src) - 1] = '\0';
    ASSIGN_STR(o->src, src);
    o->amount = amount; 
    fillDate(&o->date);
Finally:
    return err;
}

uint64_t fetchEarnsFromCli(Earnings *e)
{
    char c;
    char buf[100];
    int err = 0;
    uint64_t totalEarns = 0;
    printf("Type of earnings (s - salary, b - bonus, o - others):");
    c = getchar();
    getchar();
    switch (c) {
        case 's':
                printf("Enter salary amount:");
                if (fgets(buf, 100, stdin) == NULL)
                    perror("Salary");
                else
                    WMC_RET(addSalary(&e->s, atoi(buf)));
                totalEarns = atoi(buf);
                break;
        case 'b':
                printf("Enter bonus amount:");
                if (fgets(buf, 100, stdin) == NULL)
                    perror("Bonus");
                else
                    WMC_RET(addBonus(&e->b, atoi(buf)));
                totalEarns = atoi(buf);
                break;
        case 'o':
                {
                    char src[MAX_STR_LEN];
                    printf("Enter other Earning source:");
                    if (fgets(src, 100, stdin) == NULL) {
                        perror("other Earnings source");
                        break;
                    }
                    printf("Enter amount:");
                    if (fgets(buf, 100, stdin) == NULL) {
                        perror("other Earnings amount");
                        break;
                    }
                    WMC_RET(addOthEarns(&e->o[e->nOthEarns], src, atoi(buf)));
                    e->nOthEarns++;
                    totalEarns = atoi(buf);
                }
                break;
        default :
            printf("Invalid option %c!!! \t supported options <s, b, o>\n", c);
    }
Finally:
    if(err) {
        printf("Unable to add earnings");
    }
    return totalEarns;
}

uint64_t addEarnings(Earnings *e)
{
    printf("Adding Earnings\n");
    return fetchEarnsFromCli(e);

}

void printSalary(Salary s)
{
    if(s.date.year != 0) {
        printDate(s.date);
        printf(" : Salary Amount \t\t:%lu\n", s.amount);
    }
}

void printBonus(Bonus b)
{
    if(b.date.year != 0) {
        printDate(b.date);
        printf(" : Bonus amount \t\t:%lu\n", b.amount);
    }
}

void printOtherEarnings(OthEarns o)
{
    printDate(o.date);
    printf(" : %s\b \t\t %lu \n", o.src, o.amount);
}

void printAllMyEarnings(Earnings e)
{
    int i = 0;
    printSalary(e.s);
    printBonus(e.b);
    for(i = 0; i < e.nOthEarns; i++)
        printOtherEarnings(e.o[i]);
}
