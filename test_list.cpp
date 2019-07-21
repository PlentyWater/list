#include <cstdio>
#include <iostream>
#include "list.h"

void test_creatAlist();

void test_deleteMiddleNodeOfList();
void test_deleteMidNode2();
void test_reverseList();
void test_reversePartList();
void test_josephusKill();
void test_josephusKill2();
void test_isPalindrome1();
void test_isPalindrome2();
void test_listLowMidHigh();
void test_addTwoList();

int main()
{
    test_addTwoList();
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

void test_josephusKill()
{
    ListNode *pHead = createAList();
    ListNode *pRear = findTheLastNode(pHead);
    pRear->m_pNext = pHead;
    printf("input m\n");
    int m = 0;
    std::cin >> m;
    josephusKill(&pHead, m);
    printList(pHead);
}

void test_josephusKill2()
{
    ListNode *pHead = createAList();
    ListNode *pRear = findTheLastNode(pHead);
    pRear->m_pNext = pHead;
    printf("input m\n");
    int m = 0;
    std::cin >> m;
    ListNode *pNode = josephusKill2(pHead, m);
    printf("live node: %d\n", pNode->m_nValue);
}

void test_isPalindrome1()
{
    ListNode *pHead = createAList();
    printf("is palindrome : %d \n", isPalindrome1(pHead));
}
void test_isPalindrome2()
{
    ListNode *pHead = createAList();
    printf("List %s palindrome \n", isPalindrome2(pHead) ? "is" : "is not");
    printList(pHead);
}

void test_listLowMidHigh()
{
    ListNode *pHead = createAList();
    int x = 0;
    printf("input pivot :");
    std::cin >> x;
    listLowMidHigh(&pHead, x);
    printList(pHead);
}

void test_addTwoList()
{
    printf("input list1\n");
    ListNode *pHead1 = createAList();
    printf("input list2");
    ListNode *pHead2 = createAList();
    ListNode *pNew = addTwoList(pHead1, pHead2);
    printList(pNew);
}
