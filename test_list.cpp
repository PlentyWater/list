#include <cstdio>
#include <iostream>
#include "list.h"

void test_creatAlist();

void test_deleteMiddleNodeOfList();
void test_deleteMidNode2();
void test_reverseList();
void test_reversePartList();

int main()
{
    test_reversePartList();
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

void test_deleteMidNode2()
{
    ListNode *pHead = createAList();
    deleteMidNode2(&pHead);
    printList(pHead);
}

void test_reverseList()
{
    ListNode *pHead = createAList();
    reverseList(&pHead);
    printList(pHead);
}

void test_reversePartList()
{
    ListNode *pHead = createAList();
    int from = 0;
    int to = 0;
    printf("input from :");
    std::cin >> from;
    printf("input to :");
    std::cin >> to;
    reversePartList(&pHead, from, to);
    printList(pHead);
}
