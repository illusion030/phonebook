#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

#define COMBINE 1

typedef struct __PHONE_BOOK_ENTRY_DETAILS {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} details;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    details *detail;
    struct __PHONE_BOOK_ENTRY *pNext;
    struct __PHONE_BOOK_ENTRY *pRight;
    struct __PHONE_BOOK_ENTRY *pLeft;
} entry;

entry *findName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *e);
entry *LinkedlistToBSTRecur(int count, entry **root);

#endif
