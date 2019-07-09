#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(NULL == head){
        return NULL;
    }
    struct ListNode *pstHead = head;
    struct ListNode *pstNext;
    while(pstHead){
        pstNext = pstHead->next;
        if(NULL == pstNext)
            break;
        if(pstNext->val != pstHead->val){
            break;
        }
        while(pstNext){
            if(pstNext->val == pstHead->val){
                pstNext = pstNext->next;
            }else{
                break;
            }
        }
        pstHead = pstNext;
    }
    if(pstHead == NULL){
        return NULL;
    }

    struct ListNode *pstStart = pstHead;
    pstNext = pstHead->next;
    while(pstNext){
        int flag = 0;
        while(pstNext->next && pstNext->val == pstNext->next->val){
            flag = 1;
            pstNext = pstNext->next;
        }
        if(flag){
            pstStart->next = pstNext->next;
        }else{
            pstStart = pstStart->next;
        }
        pstNext = pstNext->next;
    }
    return pstHead;
}

int main(){

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode)*10);
    head[0].val = 1;head[1].val = 1;
    head[2].val = 2;head[3].val = 3;
    head[4].val = 4;head[5].val = 4;
    head[6].val = 5; head[7].val = 5;
    head[8].val = 6;head[9].val = 6;
    for(int i = 0 ; i < 9 ; i ++){
        head[i].next = &head[i+1];
    }
    head[9].next = NULL;

    head = deleteDuplicates(head);

    struct ListNode *p = head;
    while(p){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}
