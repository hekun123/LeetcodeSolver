#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *a_ptr, *b_ptr;
    int swap_num;
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }

    a_ptr = head;
    b_ptr = head->next;

    while(true){
        swap_num = a_ptr->val;
        a_ptr->val = b_ptr->val;
        b_ptr->val = swap_num;

        if(b_ptr->next == NULL)break;
        if(b_ptr->next->next == NULL)break;
        a_ptr = a_ptr->next->next;
        b_ptr = a_ptr->next;
    }
    return head;

}
int main(){
    struct ListNode *head[4], *ptr_1, *ptr_2, *ptr_3, *ptr_4;
    for(int i = 0 ; i < 4 ; i ++){
        head[i] = (struct ListNode *)malloc(sizeof(struct ListNode));
        head[i]->val = i;
        head[i]->next = NULL;
    }
    ptr_1 = head[0];
    ptr_2 = head[1];
    ptr_3 = head[2];
    ptr_4 = head[3];
    for(int i = 0 ; i < 10 ; i ++){
        struct ListNode * node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val   = i + 1;
        node->next  = NULL;
        ptr_1->next = node;
        ptr_1 = ptr_1->next;
    }

    for(int i = 0 ; i < 5; i ++){
        struct ListNode * node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val   = i + 10;
        node->next  = NULL;
        ptr_2->next = node;
        ptr_2 = ptr_2->next;
    }

    for(int i = 0 ; i < 3; i ++){
        struct ListNode * node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val   = i + 20;
        node->next  = NULL;
        ptr_3->next = node;
        ptr_3 = ptr_3->next;
    }

    for(int i = 0 ; i < 7; i ++){
        struct ListNode * node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val   = i + 40;
        node->next  = NULL;
        ptr_4->next = node;
        ptr_4 = ptr_4->next;
    }
    ptr_1 = head[0];
    ptr_2 = head[1];
    ptr_3 = head[2];
    ptr_4 = head[3];


    struct ListNode *node = swapPairs(ptr_2);
    if(node == NULL){
        printf("There is nothing to print!\n");
        return 0;
    }else if(node ->next == NULL){
        printf("%d\n", node->val);
        return 0;
    }
    while(node->next){
        printf("%d->", node->val);
        node = node->next;
    }
    printf("%d\n", node->val);
    return 0;
}
