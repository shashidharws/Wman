#include <stdio.h>
#include "profile.h"
User *_uPtr;

main()
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
        switch(c) {
            case 'e' :
                    addUserEarnings(&_uPtr->earns);
                    break;
            case 'x' : 
                    addUserExpenses(&_uPtr->exps);
                    break;
            case 's' :
                    addUserSavings(&_uPtr->s);
                    break;
            default:
                printf("Invalid option %c\n", c);
        }
    }
}
