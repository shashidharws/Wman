#include <stdio.h>
#include "profile.h"
User *_uPtr;

int main()
{
    char buf[MAX_STR_LEN];
    char c;
    printf("Enter User name :");
    if (fgets(buf, 100, stdin) == NULL) {
        perror("User name");
        return -1;
    }
    _uPtr = createUser(buf);
    while(1) {
        printf("Wealth type (e - earnings, x - expenses, s - savings) :");
        c = getchar();
        getchar();
        switch(c) {
            case 'e' :
                    addUserEarnings(_uPtr);
                    break;
            case 'x' : 
                    addUserExpenses(_uPtr);
                    break;
            case 's' :
                    addUserSavings(_uPtr);
                    break;
            default:
                printf("Invalid option %c\n", c);
        }
        printf("Print Wealth ? (e - earnings, x - expenses, s - savings) :");
        c = getchar();
        getchar();
        switch(c) {
            case 'e' :
                    printAllMyEarnings(_uPtr->earns);
                    break;
            case 'x' : 
                    printAllMyExpenses(_uPtr->exps);
                    break;
            case 's' :
                    printAllMySavings(_uPtr);
                    break;
            default:
                //printf("Invalid option %c\n", c);
                break;
        }

    printf("current balance : %lu\n", _uPtr->balance);
    printf("==========================================================\n");
    }
}

