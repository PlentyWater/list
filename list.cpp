#include <cstdio>
#include <iostream>
#include <stack>
#include "list.h"
#include <vector>
#include <cmath>
std::vector<ListNode*> nodes;

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

ListNode* createAList2()
{
    int k = 0;
    ListNode *pHead = NULL;
    ListNode *pEnd = NULL;
    nodes.clear();
    while(1)
    {
        printf("input an integer(not 999999):");
        std::cin >> k;
        if(k != 999999)
        {
            ListNode *pNode = new ListNode;
            pNode->m_nValue = k;
            pNode->m_pNext = NULL;
            nodes.push_back(pNode);
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
    printf("input the loop entry:\n");
    int n = -1;
    std::cin >> n;
    if(n != -1)
        pEnd->m_pNext = nodes[n!=0? n-1 : n];
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
    printf(" null\n");
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

bool isPalindrome2(ListNode *pHead)
{
    if(pHead == NULL)
        return false;

    ListNode *pNode = NULL;
    ListNode *pPre = NULL;
    ListNode *pNext = NULL;
    ListNode *pRear = NULL;
    ListNode *pMid = NULL;
    ListNode *pNode2 = NULL;

    pNode = pHead;
    int len = 0;
    while(pNode != NULL)//calculate the total number
    {
        len++;
        pNode = pNode->m_pNext;
    }

    int mid = (len + 1) / 2;
    int number = 1;
    pNode = pHead;
    while(++number <= mid)//find the middle node
        pNode = pNode->m_pNext;

    pMid = pNode;
    pNode = pNode->m_pNext;
    pMid->m_pNext = NULL;
    pPre = pMid;
    while(pNode != NULL) // revert the last middle part of the Liset
    {
        pNext = pNode->m_pNext;
        pNode->m_pNext = pPre;
        pPre = pNode;
        pNode = pNext;
    }
    pRear = pPre;

    pNode = pHead;
    pNode2 = pRear;
    bool ret = true;
    while(pNode != NULL && pNode2 != NULL)
    {
        if(pNode->m_nValue == pNode2->m_nValue)
        {
            pNode = pNode->m_pNext;
            pNode2 = pNode2->m_pNext;
        }
        else
        {
            ret = false;
            break;
        }
    }

    pNode = pRear;
    pPre = NULL;
    while(pNode != NULL) //restore the List
    {
        pNext = pNode->m_pNext;
        pNode->m_pNext = pPre;
        pPre = pNode;
        pNode = pNext;
    }

    return ret;
}

void listLowMidHigh(ListNode **pHead, int pivot)
{
    if(pHead == NULL || *pHead == NULL)
        return;

    ListNode *pNode = *pHead;
    ListNode *pLow1 = NULL;
    ListNode *pLow2 = NULL;
    ListNode *pMid1 = NULL;
    ListNode *pMid2 = NULL;
    ListNode *pHigh1 = NULL;
    ListNode *pHigh2 = NULL;
    ListNode *pNext = NULL;

    while(pNode != NULL)
    {
        pNext = pNode->m_pNext;
        if(pNode->m_nValue < pivot)
        {
            pNode->m_pNext = NULL;
            if(pLow1 == NULL)
            {
                pLow1 = pNode;
                pLow2 = pNode;
            }
            else
            {
                pLow2->m_pNext = pNode;
                pLow2 = pNode;
            }
        }
        else if(pNode->m_nValue == pivot)
        {
            pNode->m_pNext = NULL;
            if(pMid1 == NULL)
            {
                pMid1 = pNode;
                pMid2 = pNode;
            }
            else
            {
                pMid2->m_pNext = pNode;
                pMid2 = pNode;
            }
        }
        else
        {
            pNode->m_pNext = NULL;
            if(pHigh1 == NULL)
            {
                pHigh1 = pNode;
                pHigh2 = pNode;
            }
            else
            {
                pHigh2->m_pNext = pNode;
                pHigh2 = pNode;
            }
        }
        pNode = pNext;
    }

    if(pLow2 != NULL)
    {
        if(pMid2 != NULL)
        {
            pLow2->m_pNext = pMid1;
            pMid2->m_pNext = pHigh1;
        }
        else
        {
            pLow2->m_pNext = pHigh1;
        }
        *pHead = pLow1;
    }
    else
    {
        if(pMid2 != NULL)
        {
            pMid2->m_pNext = pHigh1;
            *pHead = pMid1;
        }
        else
        {
            *pHead = pHigh1;
        }
    }
}

RandListNode* copyRandList(RandListNode *pHead)
{
    if(pHead == NULL)
        return NULL;

    RandListNode *pNode = pHead;
    RandListNode *pNext = NULL;
    while(pNode != NULL)
    {
        pNext = pNode->m_pNext;
        RandListNode *pNew = new RandListNode();
        pNode->m_pNext = pNew;
        pNew->m_pNext = pNext;
        pNew->m_nValue = pNode->m_nValue;
        pNode = pNext;
    }

    pNode = pHead;
    RandListNode *pNode2 = NULL;
    while(pNode != NULL)
    {
        pNode2 = pNode->m_pNext;
        if(pNode->m_pRand != NULL)
        {
            pNode2->m_pRand = pNode->m_pRand->m_pNext;
        }
        else
        {
            pNode2->m_pRand = NULL;
        }
        pNode = pNode2->m_pNext;
    }

    RandListNode *pHead2 = NULL;
    pNode = pHead;
    while(pNode != NULL)
    {
        pNode2 = pNode->m_pNext;
        pNext = pNode2->m_pNext;
        if(pHead2 == NULL)
            pHead2 = pNode2;
        if(pNext != NULL)
        {
            pNode->m_pNext = pNext;
            pNode2->m_pNext = pNext->m_pNext;
        }
        else
        {
            pNode->m_pNext = NULL;
            pNode2->m_pNext = NULL;
        }
        pNode = pNext;
    }
}

ListNode* addTwoList(ListNode *pHead1, ListNode *pHead2)
{
    reverseList(&pHead1);
    reverseList(&pHead2);

    ListNode *pNode1 = pHead1;
    ListNode *pNode2 = pHead2;
    ListNode *pNew = NULL;
    int m = 0;
    while(pNode1 != NULL && pNode2 != NULL)
    {
        int x = pNode1->m_nValue + pNode2->m_nValue + m;
        int n = x % 10;
        m = x / 10;

        ListNode *pTmp = new ListNode();
        pTmp->m_nValue = n;

        pTmp->m_pNext = pNew;
        pNew = pTmp;
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }

    ListNode *pNode = pNode1 != NULL ? pNode1 : pNode2;
    while(pNode != NULL)
    {
        int x = pNode->m_nValue + m;
        int n = x % 10;
        m = x / 10;

        ListNode *pTmp = new ListNode();
        pTmp->m_nValue = n;

        pTmp->m_pNext = pNew;
        pNew = pTmp;
        pNode = pNode->m_pNext;
    }

    if(m != 0)
    {
        ListNode *pTmp = new ListNode();
        pTmp->m_nValue = m;
        pTmp->m_pNext = pNew;
        pNew = pTmp;
    }

    reverseList(&pHead1);
    reverseList(&pHead2);

    return pNew;
}

ListNode* getEntryOfLoop(ListNode *pHead)
{
    if(pHead == NULL)
        return NULL;

    ListNode *pNode1 = pHead;
    ListNode *pNode2 = pHead;
    while(pNode2 != NULL && pNode2->m_pNext != NULL)
    {
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext->m_pNext;
        if(pNode1 == pNode2)
            break;
    }
    if(pNode2 == NULL || pNode2->m_pNext == NULL)
        return NULL;
    pNode1 = pHead;
    while(pNode1 != pNode2)
    {
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }
    return pNode1;
}

ListNode* isNoLoopListIntersect(ListNode *pHead1, ListNode *pHead2)
{
    if(pHead1 == NULL || pHead2 == NULL)
        return NULL;

    ListNode *pNode1 = pHead1;
    ListNode *pNode2 = pHead2;
    int len = 1;

    while(pNode1->m_pNext != NULL)
    {
        len++;
        pNode1 = pNode1->m_pNext;
    }
    len--;
    while(pNode2->m_pNext != NULL)
    {
        len--;
        pNode2 = pNode2->m_pNext;
    }
    if(pNode1 != pNode2)
        return NULL;

    pNode1 = len > 0 ? pHead1 : pHead2;
    pNode2 = pNode1 == pHead1 ? pHead2 : pHead1;
    len = abs(len);
    while(len != 0)
    {
        pNode1 = pNode1->m_pNext;
        len--;
    }
    while(pNode1 != pNode2)
    {
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }
    return pNode1;

}


ListNode* reverseKNode(ListNode *pHead, int k)
{
    if(pHead == NULL || k < 2)
    {
        printf("valid parameter! pHead : %p, k : %d\n",pHead, k);
        return NULL;
    }

    ListNode *pNode = pHead;
    ListNode *pNext = NULL;
    ListNode *pStart = NULL;
    int i = 1;

    while(i <= k && pNode != NULL)
    {
        pNext = pNode->m_pNext;
        pNode->m_pNext = pStart;
        pStart = pNode;
        pNode = pNext;
        i++;
    }

    if(i > k)
    {
        return pStart;
    }
    else
    {
        printf("list length < k(%d)\n", k);
        return NULL;
    }
}

ListNode* reverseEveryKNode(ListNode *pHead, int k)
{
    if(pHead == NULL || k < 2)
    {
        printf("valid parameter! pHead : %p, k : %d\n",pHead, k);
        return pHead;
    }

    int i = 0;
    ListNode *pNode = pHead;
    ListNode *pFront = NULL;
    ListNode *pRear = NULL;
    ListNode *pNewHead = NULL;
    ListNode *pTmp = NULL;
    ListNode *pNext = NULL;

    while(pNode != NULL)
    {
        pNext = pNode->m_pNext;
        i++;
        if(i == 1)
        {
            pFront = pNode;
        }
        else if(i == k)
        {
            pTmp = reverseKNode(pFront, k);
            if(pNewHead == NULL)
            {
                pNewHead = pTmp;
            }
            else
            {
                pRear->m_pNext = pTmp;
            }
            pRear = pFront;
            pRear->m_pNext = pNext;
            i = 0;
        }
        pNode = pNext;
    }

    if(pNewHead != NULL)
    {
        return pNewHead;
    }
    else
    {
        return pHead;
    }
}





