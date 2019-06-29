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

int addGrocery(Grocery *g)
{
    int err = 0;
    int i;
    int total_amount = 0;
    WMC_PTR(g);
    for(i = 0; i < g->total_items; i++)
	{
		g->total_amount += g->items[i].amount;
	}    
    fillDate(&g->date);
Finally:
    return err;
}

int addTravel(Travel *t)
{
    int err = 0;
    int i;
    int total_amount = 0;
    WMC_PTR(t);
    for(i = 0; i < t->total_items; i++)
    {
        t->total_amount += t->items[i].amount;
    }
    fillDate(&t->date);
Finally:
    return err;
}

int addShopping(Shopping *s)
{
    int err = 0;
    int i;
    int total_amount = 0;
    WMC_PTR(s);
    for(i = 0; i < s->total_items; i++)
    {
        s->total_amount += s->items[i].amount;
    }
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
