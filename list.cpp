#include <cstdio>
#include <iostream>
#include "list.h"

ListNode* createAList()
{
    int k = 0;
    ListNode *pHead = NULL;
    ListNode *pEnd = NULL;

    while(1)
    {
        printf("input an integer(not 999999):");
        std::cin >> k;
        if(k != 999999)
        {
            ListNode *pNode = new ListNode;
            pNode->m_nValue = k;
            pNode->m_pNext = NULL;
            if(pHead == NULL)
            {
                pHead = pNode;
                pEnd = pNode;
            }
            else
            {
                pEnd->m_pNext = pNode;
                pEnd = pEnd->m_pNext;
            }
        }
        else
        {
            break;
        }
    }
    printList(pHead);
    return pHead;
}

void printList(ListNode *pHead)
{
    if(pHead == NULL)
    {
        printf("pHead is NULL\n");
        return;
    }

    printf("list: ");

    ListNode *pNode = pHead;
    while(pNode != NULL)
    {
        printf(" %d ->", pNode->m_nValue);
        pNode = pNode->m_pNext;
    }
    printf("\n");
}

int totalNodesOfList(ListNode *pHead)
{
    int n = 0;
    if(pHead == NULL)
        return 0;

    ListNode *pNode = pHead;
    while(pNode != NULL)
    {
        n++;
        pNode = pNode->m_pNext;
    }

    return n;
}

void deleteMiddleNode(ListNode **pHead)
{
    if(pHead == NULL || *pHead == NULL)
        return;
    ListNode *pNode = *pHead;
    int totalNumber = totalNodesOfList(*pHead);
    int n = 0;

    if(totalNumber <= 1)
        return;

    if(totalNumber == 2)
    {
        *pHead = pNode->m_pNext;
        delete pNode;
        return;
    }
    while(pNode != NULL)
    {
        n++;
        if(n != (totalNumber + 1) / 2 - 1)
        {
            pNode = pNode->m_pNext;
        }
        else
        {
            ListNode *pTemp = pNode->m_pNext;
            pNode->m_pNext = pTemp->m_pNext;
            delete pTemp;
            return;
        }
    }
}

void deleteMidNode2(ListNode **pHead)
{
    if(pHead == NULL || *pHead == NULL)
        return;

    ListNode *pre = *pHead;
    ListNode *p1 = *pHead;
    ListNode *p2 = *pHead;
    ListNode *pTmp = NULL;

    while(p2 != NULL && p2->m_pNext != NULL)
    {
        pre = p1;
        p1 = p1->m_pNext;
        p2 = p2->m_pNext->m_pNext;
    }

    //only one node
    if(p2 == *pHead)
    {
        return;
    }

    //only two nodes
    if(pre == *pHead && p2 == NULL)
    {
        *pHead = pre->m_pNext;
        delete pre;
        return;
    }

    // > 3 nodes
    pTmp = pre->m_pNext;
    pre->m_pNext = pTmp->m_pNext;
    delete pTmp;
}
