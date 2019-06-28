#ifndef __EXPENSES_H__
#define __EXPENSES_H__

#define MAX_EMIS 10
#define MAX_BILLS 15
#define MAX_SHOPPING 20
#define MAX_OTHER_EXPENSES 25
#define MAX_GROCERY 30
#define MAX_ITEMS 50
#define MAX_TRAVEL 10
#define MAX_DINING 10
#define MAX_VEHICLE 62
 
typedef struct _items {
    char *i_name;
    uint64_t amount;
    int i_quantity;
}Items;

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
    uint64_t total_amount;
    int total_items;
    Date date;
}Grocery;

typedef struct _travel {
    Items items[MAX_ITEMS];
    uint64_t total_amount;
    int total_items;
    Date date;
}Travel;

typedef struct _shopping {
    Items items[MAX_ITEMS];
    uint64_t total_amount;
    int total_quantity;
    Date date;
}Shopping;

typedef struct _dining {
    char *summary;
    uint64_t amount;
    Date date;
}Dining;

typedef struct _vehicle {
    Items items[[MAX_ITEMS];
    uint64_t total_amount;
    int total_quantity;
    uint64_t amount;
    Date date;
}Vehicle;

typedef struct _othExp {
    Items items[MAX_ITEMS];
    uint64_t total_amount;
    int total_quantity;
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
    Bills b[MAX_BILLS];
    Grocery g[MAX_GROCERY];
    Travel t[MAX_TRAVEL];
    Shopping s[MAX_SHOPPING];
    Dining d[MAX_DINING];
    Vehicle v[MAX_VEHICLE];
    OthExp o[MAX_OTHER_EXPENSES];
}expenses;

#endif
