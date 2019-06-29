#ifndef __MISC_H__
#define __MISC_H__

#define INVALID_PTR 1
#define CONDITION_FAIL 2
#define RET_FAIL 2
#define WMC_RET(call) \
{\
    if(call) {\
        printf("ERR: %s:%d\n", __func__, __LINE__);\
        err = RET_FAIL;\
        goto Finally;\
    }\
}

#define WMC_PTR(ptr) \
{\
    if(ptr == NULL) {\
        printf("ERR: %s:%d [INVALID PTR]\n", __func__, __LINE__);\
        err = INVALID_PTR;\
        goto Finally;\
    }\
}

#define ASSIGN_STR(ptr, str) \
{\
    WMC_PTR(str);\
    ptr = (char *) calloc(strlen(str) + 1, 1);\
    strncpy(ptr, str, strlen(str));\
}

typedef struct date {
    uint32_t day;
    uint32_t month;
    uint32_t year;
}Date;


void fillDate(Date *d);

#endif
