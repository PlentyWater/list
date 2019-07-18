#ifndef _LIST_H_
#define _LIST_H_

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

ListNode* createAList();
void printList(ListNode *pHead);
int totalNodesOfList(ListNode *pHead);
ListNode *findTheLastNode(ListNode *pHead);

void deleteMiddleNode(ListNode **pHead);
void deleteMidNode2(ListNode **pHead);
void reverseList(ListNode **pHead);
void reversePartList(ListNode **pHead, int from, int to);

void josephusKill(ListNode **pHead, int m);
int getLive(int total, int m);
ListNode* josephusKill2(ListNode *pHead, int m);

bool isPalindrome1(ListNode *pHead);
bool isPalindrome2(ListNode *pHead);

void listLowMidHigh(ListNode **pHead, int pivot);













#endif
