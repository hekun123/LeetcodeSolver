#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x) {
    if(NULL == head){
        return NULL;
    }

    struct ListNode * pstListPtr = head, * pstListCurPtr = NULL, *pstListAhead = pstListPtr;
    if(pstListPtr->val >= x){
        pstListPtr = pstListPtr->next;
        while(pstListPtr){
            //找到第一个比x小的当head
            //pstListCurPtr指向head
            if(pstListPtr->val < x){
                break;
            }
            pstListPtr = pstListPtr->next;
            pstListAhead = pstListAhead->next;
        }
        if(pstListPtr){
            pstListAhead->next = pstListPtr->next;
            pstListPtr->next = head;
            head = pstListPtr;
            pstListPtr = pstListAhead->next;
        }else{
            return head;
        }
    }else{
        pstListPtr = pstListPtr->next;
    }

    pstListCurPtr = head;
    while(pstListPtr){
        //找到比x小的放在pstListCurPtr后，pstListCurPtr后移
        if(pstListPtr->val < x ){
            if(pstListCurPtr->next == pstListPtr){
                pstListCurPtr = pstListCurPtr->next;
                pstListPtr = pstListPtr->next;
                pstListAhead = pstListAhead->next;
            }else{
                pstListAhead->next = pstListPtr->next;
                pstListPtr->next = pstListCurPtr->next;
                pstListCurPtr->next = pstListPtr;
                pstListCurPtr = pstListCurPtr->next;
                pstListPtr = pstListAhead->next;
            }

            continue;
        }
        pstListPtr = pstListPtr->next;
        pstListAhead = pstListAhead->next;
    }
    return head;
}

int main(){
    ListNode node[10];
    for(int i = 0 ; i < 9 ; i ++){
        node[i].next = &node[i+1];
    }
    node[9].next = NULL;
    node[0].val = 1;node[1].val = 1;node[2].val = 3;
    node[3].val = 2;node[4].val = 5;node[5].val = 2;
    node[6].val = 2;node[7].val = 5;node[8].val = 7;
    node[9].val = 1;
    node[1].next = NULL;
    ListNode *head = partition(&node[0], 3);
    while(head){
        printf("%d ", head->val);
        head = head->next;
    }
}
