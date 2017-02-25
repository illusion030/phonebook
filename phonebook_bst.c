#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_bst.h"

entry *findName(char lastName[], entry *pHead)
{
    int cmp;
    while (pHead != NULL) {
        cmp = strcmp(lastName, pHead->lastName);
        if(cmp == 0)
            return pHead;
        if(cmp > 0)
            pHead = pHead->pRight;
        else
            pHead = pHead->pLeft;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    e->pRight = NULL;
    e->pLeft = NULL;

    return e;
}

entry *LinkedlistToBSTRecur(int count, entry **root)
{

    if (count <= 0)
        return NULL;

    entry *left = LinkedlistToBSTRecur(count/2, root);

    entry *bstroot = (entry *) malloc(sizeof(entry));
    bstroot->pNext = NULL;
    bstroot->pRight = NULL;
    bstroot->pLeft = NULL;
    strcpy(bstroot->lastName, (*root)->lastName);
    bstroot->pLeft = left;

    (*root) = (*root)->pNext;

    bstroot->pRight = LinkedlistToBSTRecur(count - count/2 - 1, root);

    return bstroot;
}
