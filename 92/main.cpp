#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if(m == n || head == NULL)return head;

    struct ListNode *start, *end, *beforeStart;
    int step = 1, len = n-m;
    start = head;
    end = head;
    beforeStart = head;

    while(step < n){
        if(step > len){
            start = start->next;
        }
        if(step > len + 1){
            beforeStart = beforeStart->next;
        }
        end = end->next;
        step ++;
    }
    //printf("%d %d\n", start->val, end->val);
    if(m == 1){
        head = end;
    }else{
        beforeStart->next = end;
    }
    struct ListNode *pstPtr = NULL;
    while(start != end){
        pstPtr = start;
        start = start->next;
        pstPtr->next = end->next;
        end->next = pstPtr;
    }
    return head;
}

int main(){

    struct ListNode pstLink[10];
    for(int i = 0 ; i < 9 ; i ++){
        pstLink[i].val = i;
        pstLink[i].next = &pstLink[i+1];
    }
    pstLink[9].val = 9;
    pstLink[9].next = NULL;

    struct ListNode *head = &pstLink[0];

    head = reverseBetween(head, 10, 10);
    while(head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }
    return 0;
}
