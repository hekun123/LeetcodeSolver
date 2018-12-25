#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *listPtr = NULL;
    struct ListNode *listHead, *listTail, *tail;
    int listLen = 0;
    listPtr = head;
    while(listPtr != NULL){
        listLen ++;
        listPtr = listPtr->next;
    }
    if(listLen <= 1){
        return head;
    }
    k %= listLen;
    if(k < 1){
        return head;
    }
    int cnt = 0;
    listPtr = head;
    while(listPtr != NULL){
        cnt ++;
        if(cnt == listLen-k){
            tail = listPtr;
        }
        if(cnt == listLen-k+1){
            listHead = listPtr;
        }
        if(listPtr->next == NULL){
            listTail = listPtr;
        }
        listPtr = listPtr->next;
    }

    listTail->next = head;
    head = listHead;
    tail->next = NULL;
    return head;
}

int main()
{
    struct ListNode node[10];
    struct ListNode *nodePtr = NULL;
    node[0].val = 0;
    node[0].next = NULL;
    for(int i = 1 ; i < 3 ; i ++){
        node[i-1].next = &node[i];
        node[i].val = i;
        node[i].next = NULL;
    }
    nodePtr = &node[0];
    nodePtr = rotateRight(node, 4);
    while(nodePtr != NULL){
        printf("%d ", nodePtr->val);
        nodePtr = nodePtr->next;
    }
    return 0;
}
