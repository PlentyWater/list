#include <cstdio>
#include <iostream>
#include <stack>
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

ListNode *findTheLastNode(ListNode *pHead)
{
    if(pHead == NULL)
        return NULL;

    ListNode *pNode = pHead;
    while(pNode->m_pNext != NULL)
        pNode = pNode->m_pNext;

    return pNode;
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

    while(p2 != NULL && p2->m_pNext != NULL && p2->m_pNext->m_pNext != NULL)
    {
        pre = p1;
        p1 = p1->m_pNext;
        p2 = p2->m_pNext->m_pNext;
    }

    //only one node
    if(p2 == *pHead && p2->m_pNext == NULL)
    {
        return;
    }

    //only two nodes
    if(p2 == *pHead && p2->m_pNext != NULL)
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

void reverseList(ListNode **pHead)
{
    if(pHead == NULL || *pHead == NULL)
        return;

    ListNode *pRear = NULL;
    ListNode *pNext = NULL;
    ListNode *pNode = *pHead;

    while(pNode != NULL)
    {
        pNext = pNode->m_pNext;
        pNode->m_pNext = pRear;
        pRear = pNode;
        pNode = pNext;
    }
    *pHead = pRear;
}

void reversePartList(ListNode **pHead, int from, int to)
{
    if(pHead == NULL || *pHead == NULL)
    {
        printf("invalid parameter, pHead or *pHead is NULL\n");
        return;
    }

    int len = 0;
    ListNode *pFrom = NULL;
    ListNode *pTo = NULL;
    ListNode *pNode = *pHead;
    while(pNode != NULL)
    {
        len++;
        pFrom = len == from - 1 ? pNode : pFrom;
        pTo = len == to + 1 ? pNode : pTo;
        pNode = pNode->m_pNext;
    }

    if(from < 1 || to > len || from > to)
    {
        printf("invalid parameter, from(%d), to(%d)\n", from, to);
        return;
    }

    ListNode *pRear = pTo;
    ListNode *pNext = NULL;
    pNode = pFrom != NULL ? pFrom->m_pNext : *pHead;
    while(pNode != pTo)
    {
        pNext = pNode->m_pNext;
        pNode->m_pNext = pRear;
        pRear = pNode;
        pNode = pNext;
    }
    if(pFrom != NULL)
    {
        pFrom->m_pNext = pRear;
    }
    else
    {
        *pHead = pRear;
    }
}

void josephusKill(ListNode **pHead, int m)
{
    if(pHead == NULL || *pHead == NULL)
    {
        printf("pHead %p or *pHead %p is NULL\n", pHead, *pHead);
        return;
    }

    ListNode *pPre = *pHead;
    ListNode *pNode = (*pHead)->m_pNext;
    int length = 1;
    while(pNode != *pHead)
    {
        length++;
        pPre = pNode;
        pNode = pNode->m_pNext;
    }

    if(m <= 0)
    {
        printf("length (%d), m (%d) is invalid\n", length, m);
        return;
    }

    pNode = *pHead;
    int n = 0;
    while(pNode != pPre)
    {
        n++;
        if(n < m)
        {
            pPre = pNode;
            pNode = pNode->m_pNext;
        }
        else
        {
            ListNode *pTmp = pNode;
            pPre->m_pNext = pNode->m_pNext;
            pNode = pNode->m_pNext;
            delete pTmp;
            n = 0;
        }
    }

    *pHead = pNode;
}

int getLive(int total, int m)
{
    if(total == 1)
        return 1;
    return (getLive(total - 1, m) + m - 1) % total + 1;
}

ListNode* josephusKill2(ListNode *pHead, int m)
{
    if(pHead == NULL || pHead->m_pNext == pHead || m < 1)
    {
        return pHead;
    }

    ListNode *pNode = pHead->m_pNext;
    int total = 1;
    int live = 0;
    while(pNode != pHead)
    {
        total++;
        pNode = pNode->m_pNext;
    }

    live = getLive(total, m);
    pNode = pHead;
    while(--live != 0)
        pNode = pNode->m_pNext;

    return pNode;
}

bool isPalindrome1(ListNode *pHead)
{
    if(pHead == NULL)
        return false;

    std::stack<ListNode*> nodeStack;
    ListNode *pNode = pHead;
    while(pNode != NULL)
    {
        nodeStack.push(pNode);
        pNode = pNode->m_pNext;
    }

    pNode = pHead;
    while(pNode != NULL)
    {
        if(pNode->m_nValue == nodeStack.top()->m_nValue)
        {
            pNode = pNode->m_pNext;
            nodeStack.pop();
        }
        else
        {
            return false;
        }
    }
    return true;
}
















