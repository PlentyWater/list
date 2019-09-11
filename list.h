#ifndef _LIST_H_
#define _LIST_H_

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

struct RandListNode
{
    int m_nValue;
    RandListNode *m_pRand;
    RandListNode *m_pNext;
};

ListNode* createAList();
ListNode* createAList2();
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

RandListNode* copyRandList(RandListNode *pHead);

ListNode* addTwoList(ListNode *pHead1, ListNode *pHead2);

ListNode* getEntryOfLoop(ListNode *pHead);
ListNode* isNoLoopListIntersect(ListNode *pHead1, ListNode *pHead2);

ListNode* reverseKNode(ListNode *pHead, int k);
ListNode* reverseEveryKNode(ListNode *pHead, int k);














#endif
