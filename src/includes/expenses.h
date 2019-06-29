#ifndef __EXPENSES_H__
#define __EXPENSES_H__

#include "misc.h"

#define MAX_EMIS 10
#define MAX_BILLS 15
#define MAX_SHOPPING 20
#define MAX_OTHER_EXPENSES 25
#define MAX_GROCERY 30
#define MAX_TRAVEL 10
#define MAX_DINING 10
#define MAX_VEHICLE 62

 
typedef struct _emis {
    char *name;
    uint64_t amount;
    Date date;
}Emis;

typedef struct _bills {
    char *name;
    uint64_t amount;
    Date date;
}Bills;

typedef struct _grocery {
    Items items[MAX_ITEMS];
    uint64_t totalAmount;
    int totalItems;
    Date date;
}Grocery;

typedef struct _travel {
    Items items[MAX_ITEMS];
    uint64_t totalAmount;
    int totalItems;
    Date date;
}Travel;

typedef struct _shopping {
    Items items[MAX_ITEMS];
    uint64_t totalAmount;
    int totalItems;
    Date date;
}Shopping;

typedef struct _dining {
    char *summary;
    uint64_t amount;
    Date date;
}Dining;

typedef struct _vehicle {
    Items items[MAX_ITEMS];
    uint64_t totalAmount;
    int totalItems;
    Date date;
}Vehicle;

typedef struct _othExp {
    Items items[MAX_ITEMS];
    uint64_t totalAmount;
    int totalItems;
    Date date;
}OthExp;

/**
  * e : EMIs paid
  * b : bills paid
  * g : grocery expenses include milk, egg , groceries, vegetables, curd evrything that required to cook except vessels
  * t : travel expenses petrol/diesel, stay and food everything included
  * s : shopping expenses other than groceries like cloths, ornaments, vessels, plastic, gadgets, anything we require for home and us except car/bike
  * d : dining expenses food which we had outside
  * v : vehicles expenses include services, commute(cab, auto, metro, bus, train), fuel, car/bike accessories
  * o : any other expenses
  */
typedef struct _expenses {
    Emis e[MAX_EMIS];
    int nEmis;
    Bills b[MAX_BILLS];
    int nBills;
    Grocery g[MAX_GROCERY];
    int nGroc;
    Travel t[MAX_TRAVEL];
    int nTrav;
    Shopping s[MAX_SHOPPING];
    int nShop;
    Dining d[MAX_DINING];
    int nDine;
    Vehicle v[MAX_VEHICLE];
    int nVehi;
    OthExp o[MAX_OTHER_EXPENSES];
    int nOthe;
}Expenses;

#endif
