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
    e->amount = amount;
    fillDate(&b->date);
Finally:
    return err;
}

int addGroceryWithItems(Grocery *g)
{
    int err = 0;
    int i;
    int total_amount = 0;
    WMC_PTR(g);
    addItems(g->items);
    for(i = 0; i < g->total_items; i++)
    {
        g->total_amount += g->items[i].amount;
    }    
    fillDate(&g->date);
Finally:
    return err;
}

int addGrocery(Grocery *g, uint64_t amount)
{
    WMC_PTR(g);
    g->total_amount = amount;
    fillDate(&g->date);
}

int addTravel(Travel *t)
{
    int err = 0;
    int i;
    int total_amount = 0;
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
    int total_amount = 0;
    WMC_PTR(s);
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
    WMC_PTR(s);
    s->totalAmount = amount;
    fillDate(&g->date);
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
    int total_amount = 0;
    WMC_PTR(v);
    for(i = 0; i < v->total_items; i++)
    {
        v->total_amount += v->items[i].amount;
    }
    fillDate(&v->date);
Finally:
    return err;
}

int addOthExp(OthExp *o)
{
    int err = 0;
    int i;
    int total_amount = 0;
    WMC_PTR(o);
    for(i = 0; i < o->total_items; i++)
    {
        o->total_amount += o->items[i].amount;
    }
    fillDate(&t->date);
Finally:
    return err;
}

int addOthExp(Grocery *o, uint64_t amount)
{
    WMC_PTR(o);
    o->total_amount = amount;
    fillDate(&o->date);
}

int fetchExpensesFromCli(Expenses *e)
{
    char c;
    char buf[100];
    printf("Type of expense (e - emi, b - bills, g - grocery, t -travel, s -shopping, d - Dining, v - Vehicle, o - other):");
    getchar(c);
    switch (c) {
        case 'e':
                printf("Adding EMIs \n");
                printf("EMI Name:");
                if (fgets(name, 100, stdin) == NULL)
                    perror("EMI name");
                else
                    ASSIGN_STR(e->name, name);

                printf("Enter amount:");
                if (fgets(amountt, 100, stdin) == NULL)
                    perror("amount");
                else
                    e->amountt = atoi(amount);
                break;
        case 'b':
                printf("Adding monthly Bills \n");
                printf("Bill Name:");
                if (fgets(name, 100, stdin) == NULL)
                    perror("Bill name");
                else
                    ASSIGN_STR(b->name, name);

                printf("Enter amount:");
                if (fgets(amount, 100, stdin) == NULL)
                    perror("amount");
                else
                    b->amount = atoi(amount);
                break;
        case 'g':
                printf("Adding Grocery\n");
                printf("Do you want to add item list?(y//n) [y]:");
                getchar(c);
                if(c == n) {
                    printf("Enter total amount:");
                    if (fgets(buf, 100, stdin) == NULL) {
                        perror("Grocery");
                        break;
                    }
                    addGrocery(&e->g, atoi(buf));
                } else
                    addGroceryWithItems(&e->g);
                break;
        case 't':
                printf("Adding Travel\n");
                addItems(t->items);
                addTravel(&e->t);
                break;
        case 's':
                printf("Adding Shopping list:\n");
                printf("Do you want to add item list?(y//n) [y]:");
                getchar(c);
                if(c == n) {
                    printf("Enter total amount:");
                    if (fgets(buf, 100, stdin) == NULL) {
                        perror("Shopping");
                        break;
                    }
                    addShopping(&e->s, atoi(buf));
                } else
                    addShoppingWithItems(&e->s);
                break;
        case 'd':
                printf("Enter Dining expenses");
                printf("Dining summary:");
                if (fgets(summary, 100, stdin) == NULL)
                    perror("Summary");
                else
                    ASSIGN_STR(d->summary, summary);

                printf("Amount:");
                if (fgets(amount, 100, stdin) == NULL)
                    perror("amount");
                else
                    s->amount = atoi(amount);
                break;
        case 'v':
                printf("Adding Vehiclel\n");
                addItems(v->items);
                addVehicle(&e->v);
                break;
        case 'o':
                printf("Adding other expenses :\n");
                printf("Do you want to add item list?(y//n) [y]:");
                getchar(c);
                if(c == n) {
                    printf("Enter total amount:");
                    if (fgets(buf, 100, stdin) == NULL) {
                        perror("OthExp");
                        break;
                    }
                    addOthExp(&e->o, atoi(buf));
                } else
                    addOthExpWithItems(&e->o);
                break;
        default:
                printf("Invalid option %c!!! \t supported options <e, b, g, t, s, d, v, o>\n", c);
    }

}

int addExpenses(Expenses *e)
{
    printf("Adding expenses\n");
    fetchExpensesFromCli(e)

}
