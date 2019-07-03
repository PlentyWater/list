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

void deleteMiddleNode(ListNode **pHead);
void deleteMidNode2(ListNode **pHead);
void reverseList(ListNode **pHead);













#endif
