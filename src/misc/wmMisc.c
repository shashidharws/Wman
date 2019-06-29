#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include "misc.h"

void fillDate(Date *d)
{
    struct timeval tv;
    struct tm *now;
    gettimeofday(&tv, NULL);
    now = gmtime(&tv.tv_sec);
    d->month = now->tm_mon;
    d->year = now->tm_year + 1900;
    d->day = now->tm_wday;
}

int fetchItemsFromCli(Items *items, int maxItems)
{
    i = 0;
    char iName[MAX_ITEM_NAME_LEN];
    char amount[10];
    char quantity[10];
    char c = 'y';
    for(i = 0; i < maxItems; i++) {
        c = 'y';
        printf("Want to enter Item?(y\\n) [y]:"); 
        getchar(c);
        if(c == 'n')
            break;
        printf("###################################\n");
        printf("Item Name:");
        if (fgets(iName, 100, stdin) == NULL)
            perror("Item name");
        else
            ASSIGN_STR(items[i].name, iName);

        printf("Price:");
        if (fgets(amount, 100, stdin) == NULL)
            perror("Price");
        else
            items[i].amount = atoi(amount);

        printf("Quantity:");
        if (fgets(iName, 100, stdin) == NULL)
            perror("Quantity [1]");
        else
            items[i].quantity = atoi(quantity) ? atoi(quantity) : 1;
        printf("-----------------------------------\n");
    }
    if(i == maxItems)
        printf("MAX Items reached!!!");
    return i;
}

int addItems(Items *items)
{
    printf("Adding Items \n");
    fetchItemsFromCli(items);

}
