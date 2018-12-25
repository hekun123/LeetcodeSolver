#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *a_ptr, *b_ptr, *c_ptr, *tem_ptr;
    a_ptr = l1;
    b_ptr = l2;
    if(a_ptr == NULL){
        return b_ptr;
    }
    if(b_ptr == NULL){
        return a_ptr;
    }

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    c_ptr = head;
    if(a_ptr->val > b_ptr->val){
        c_ptr->val  = b_ptr->val;
        c_ptr->next = NULL;
        b_ptr = b_ptr->next;
    }else{
        c_ptr->val  = a_ptr->val;
        c_ptr->next = NULL;
        a_ptr = a_ptr->next;
    }

    while(a_ptr != NULL && b_ptr != NULL){
        if(a_ptr->val > b_ptr->val){
            tem_ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
            tem_ptr->val    = b_ptr->val;
            tem_ptr->next   = NULL;
            c_ptr->next     = tem_ptr;
            c_ptr = c_ptr->next;
            b_ptr = b_ptr->next;
        }else {
            tem_ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
            tem_ptr->val    = a_ptr->val;
            tem_ptr->next   = NULL;
            c_ptr->next     = tem_ptr;
            c_ptr = c_ptr->next;
            a_ptr = a_ptr->next;
        }
    }
    if(a_ptr != NULL){
        c_ptr->next = a_ptr;
    }
    if(b_ptr != NULL){
        c_ptr->next = b_ptr;
    }
    return head;
}

int main(){

    struct ListNode *head, *a, *b;
    struct ListNode node_1[5], node_2[5];
    a = &node_1[0];
    b = &node_2[0];

    node_1[0].val = 1;
    node_2[0].val = 2;
    node_1[4].next = NULL;
    node_2[4].next = NULL;
    for(int i = 1 ; i < 5 ; i ++){
        node_1[i].val = i;
        node_1[i-1].next = &node_1[i];

        node_2[i].val = i+6;
        node_2[i-1].next = &node_2[i];
    }

//    while(a->next != NULL){
//        printf("%d->", a->val);
//        a = a->next;
//    }
//    printf("%d\n", a->val);
//    while(b->next != NULL){
//        printf("%d->", b->val);
//        b = b->next;
//    }
//    printf("%d\n", b->val);
    head = mergeTwoLists(a, b);
    while(head->next != NULL){
        printf("%d->", head->val);
        head = head->next;
    }
    printf("%d\n", head->val);
    return 0;
}
