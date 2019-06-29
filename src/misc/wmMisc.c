#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include "misc.h"
#define MAX_ITEM_NAME_LEN 100

void fillDate(Date *d)
{
    struct timeval tv;
    struct tm *now;
    gettimeofday(&tv, NULL);
    now = gmtime(&tv.tv_sec);
    d->month = now->tm_mon + 1;
    d->year = now->tm_year + 1900;
    d->day = now->tm_mday;
}

int fetchItemsFromCli(Items *items, int maxItems)
{
    int i = 0;
    int err = 0;
    char iName[MAX_ITEM_NAME_LEN];
    char amount[10];
    char quantity[10];
    char c = 'y';
    for(i = 0; i < maxItems; i++) {
        c = 'y';
        printf("Want to enter Item?(y\\n) [y]:"); 
        c = getchar();
        if(c == 'n')
            break;
        printf("###################################\n");
        printf("Item Name:");
        if (fgets(iName, MAX_ITEM_NAME_LEN, stdin) == NULL)
            perror("Item name");
        else
            ASSIGN_STR(items[i].name, iName);

        printf("Price:");
        if (fgets(amount, MAX_ITEM_NAME_LEN, stdin) == NULL)
            perror("Price");
        else
            items[i].amount = atoi(amount);

        printf("Quantity [1]:");
        if (fgets(quantity, MAX_ITEM_NAME_LEN, stdin) == NULL)
            perror("Quantity");
        else
            items[i].quantity = atoi(quantity) ? atoi(quantity) : 1;
        printf("-----------------------------------\n");
    }
    if(i == maxItems)
        printf("MAX Items reached!!!");
Finally:
    return i;
}

int addItems(Items *items)
{
    printf("Adding Items \n");
    fetchItemsFromCli(items, MAX_ITEMS);
}

void printDate(Date d)
{
    printf("[%u-%u-%u]", d.day, d.month, d.year);
}
