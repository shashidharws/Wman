#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "expenses.h"
#include "misc.h"

int addEmis(Emis *e, char *name, uint64_t amount)
{
    int err = 0;
    WMC_PTR(e);
    WMC_PTR(name);
    ASSIGN_STR(e->name, name);
    e->amount = amount;
    fillDate(&e->date);
Finally:
    return err;
}

int addBills(Bills *b, char *name, uint64_t amount)
{
    int err = 0;
    WMC_PTR(b);
    WMC_PTR(name);
    ASSIGN_STR(b->name, name);
    b->amount = amount;
    fillDate(&b->date);
Finally:
    return err;
}

int addGroceryWithItems(Grocery *g)
{
    int err = 0;
    int i;
    int totalAmount = 0;
    WMC_PTR(g);
    g->totalItems = addItems(g->items);
    for(i = 0; i < g->totalItems; i++)
    {
        g->totalAmount += g->items[i].amount;
    }    
    fillDate(&g->date);
Finally:
    return err;
}

int addGrocery(Grocery *g, uint64_t amount)
{
    int err = 0;
    WMC_PTR(g);
    g->totalAmount = amount;
    fillDate(&g->date);
Finally:
    return err;
}

int addTravel(Travel *t)
{
    int err = 0;
    int i;
    int totalAmount = 0;
    WMC_PTR(t);
    for(i = 0; i < t->totalItems; i++)
    {
        t->totalAmount += t->items[i].amount;
    }
    fillDate(&t->date);
Finally:
    return err;
}

int addShoppingWithItems(Shopping *s)
{
    int err = 0;
    int i;
    int totalAmount = 0;
    WMC_PTR(s);
    s->totalItems = addItems(s->items);
    for(i = 0; i < s->totalItems; i++)
    {
        s->totalAmount += s->items[i].amount;
    }
    fillDate(&s->date);
Finally:
    return err;
}

int addShopping(Shopping *s, uint64_t amount)
{
    int err = 0;
    WMC_PTR(s);
    s->totalAmount = amount;
    fillDate(&s->date);
Finally:
    return err;
}

int addDining(Dining *d, char *summary, uint64_t amount)
{
    int err = 0;
    WMC_PTR(d);
    WMC_PTR(summary);
    ASSIGN_STR(d->summary, summary);
    d->amount = amount;
    fillDate(&d->date);
Finally:
    return err;
}

int addVehicle(Vehicle *v)
{
    int err = 0;
    int i;
    int totalAmount = 0;
    WMC_PTR(v);
    for(i = 0; i < v->totalItems; i++)
    {
        v->totalAmount += v->items[i].amount;
    }
    fillDate(&v->date);
Finally:
    return err;
}

int addOthExpWithItems(OthExp *o)
{
    int err = 0;
    int i;
    int totalAmount = 0;
    WMC_PTR(o);
    for(i = 0; i < o->totalItems; i++)
    {
        o->totalAmount += o->items[i].amount;
    }
    fillDate(&o->date);
Finally:
    return err;
}

int addOthExp(OthExp *o, uint64_t amount)
{
    int err = 0;
    WMC_PTR(o);
    o->totalAmount = amount;
    fillDate(&o->date);
Finally:
    return err;
}

uint64_t fetchExpensesFromCli(Expenses *e)
{
    int err = 0;
    char c;
    char buf[100];
    char name[MAX_STR_LEN];
    char summary[MAX_STR_LEN];
    uint64_t totalExp = 0;
    printf("Type of expense (e - emi, b - bills, g - grocery, t -travel, s -shopping, d - Dining, v - Vehicle, o - other):");
    c = getchar();
    if(c != '\n')
        getchar();
    switch (c) {
        case 'e':
                printf("Adding EMIs \n");
                printf("EMI Name:");
                if (fgets(name, 100, stdin) == NULL)
                    perror("EMI name");

                printf("Enter amount:");
                if (fgets(buf, 100, stdin) == NULL)
                    perror("amount");

                WMC_RET(addEmis(&e->e[e->nEmis], name, atoi(buf)));
                totalExp = e->e[e->nEmis].amount;
                e->nEmis++;
                break;
        case 'b':
                printf("Adding monthly Bills \n");
                printf("Bill Name:");
                if (fgets(name, 100, stdin) == NULL)
                    perror("name");

                printf("Enter amount:");
                if (fgets(buf, 100, stdin) == NULL)
                    perror("amount");

                WMC_RET(addBills(&e->b[e->nBills], name, atoi(buf)));
                totalExp = e->b[e->nBills].amount;
                e->nBills++;
                break;
        case 'g':
                printf("Adding Grocery\n");
                printf("Do you want to add item list?(y//n) [y]:");
                c = getchar();
                if(c != '\n')
                    getchar();
                if(c == 'n') {
                    printf("Enter total amount:");
                    if(fgets(buf, 100, stdin) == NULL) {
                        perror("Grocery");
                        break;
                    }
                    WMC_RET(addGrocery(&e->g[e->nGroc], atoi(buf)));
                } else {
                    WMC_RET(addGroceryWithItems(&e->g[e->nGroc]));
                }
                totalExp = e->g[e->nGroc].totalAmount;
                e->nGroc++; 

                break;
        case 't':
                printf("Adding Travel\n");
                e->t[e->nTrav].totalItems = addItems(e->t[e->nTrav].items);
                WMC_RET(addTravel(&e->t[e->nTrav]));
                totalExp = e->t[e->nTrav].totalAmount;
                e->nTrav++;
                break;
        case 's':
                printf("Adding Shopping list:\n");
                printf("Do you want to add item list?(y//n) [y]:");
                c = getchar();
                if(c != '\n')
                    getchar();
                if(c == 'n') {
                    printf("Enter total amount:");
                    if (fgets(buf, 100, stdin) == NULL) {
                        perror("Shopping");
                        break;
                    }
                    WMC_RET(addShopping(&e->s[e->nShop], atoi(buf)));
                } else
                    WMC_RET(addShoppingWithItems(&e->s[e->nShop]));
                totalExp = e->s[e->nShop].totalAmount;
                e->nShop++;
                break;
        case 'd':
                printf("Enter Dining expenses");
                printf("Dining summary:");
                if (fgets(summary, 100, stdin) == NULL)
                    perror("Summary");

                printf("Amount:");
                if (fgets(buf, 100, stdin) == NULL)
                    perror("amount");

                WMC_RET(addDining(&e->d[e->nDine], name, atoi(buf)));
                totalExp = e->d[e->nDine].amount;
                e->nDine++;
                break;
        case 'v':
                printf("Adding Vehiclel\n");
                e->v[e->nVehi].totalItems = addItems(e->v[e->nVehi].items);
                WMC_RET(addVehicle(&e->v[e->nVehi]));
                totalExp = e->v[e->nVehi].totalAmount;
                e->nVehi++;
                break;
        case 'o':
                printf("Adding other expenses :\n");
                printf("Do you want to add item list?(y//n) [y]:");
                c = getchar();
                if(c != '\n')
                if(c != '\n')
                    getchar();
                    getchar();
                if(c == 'n') {
                    printf("Enter total amount:");
                    if (fgets(buf, 100, stdin) == NULL) {
                        perror("OthExp");
                        break;
                    }
                    WMC_RET(addOthExp(&e->o[e->nOthe], atoi(buf)));
                } else
                    WMC_RET(addOthExpWithItems(&e->o[e->nOthe]));
                totalExp = e->o[e->nOthe].totalAmount;
                e->nOthe++;
                break;
        default:
                printf("Invalid option %c!!! \t supported options <e, b, g, t, s, d, v, o>\n", c);
    }
Finally:
    return totalExp;

}

int addExpenses(Expenses *e)
{
    printf("Adding expenses\n");
    fetchExpensesFromCli(e);

}
