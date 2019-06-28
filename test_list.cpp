#include <cstdio>
#include <iostream>
#include "list.h"

void test_creatAlist();

void test_deleteMiddleNodeOfList();
void test_delteMidNode2();

int main()
{
    test_deleteMiddleNodeOfList();
}

void test_creatAlist()
{
    ListNode *pHead = createAList();
    printList(pHead);
}

void test_deleteMiddleNodeOfList()
{
    ListNode *pHead = createAList();
    deleteMiddleNode(&pHead);
    printList(pHead);
}

void test_delteMidNode2()
{
    ListNode *pHead = createAList();
    deleteMidNode2(&pHead);
    printList(pHead);
}
