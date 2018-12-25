#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverse_list(struct ListNode *head, int k){
    if(head == NULL)return NULL;
    int cnt = 0;
    struct ListNode *ptr = head;
    int *stack_node = (int *)malloc(sizeof(int)*k);
    while(true){
        stack_node[cnt ++] = ptr->val;
        ptr = ptr->next;
        if( cnt == k){
            break;
        }
    }
    ptr = head;
    while(true){
        ptr->val = stack_node[-- cnt];
        ptr = ptr->next;
        if(cnt <= 0)break;
    }
    return head;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int cnt, flag;
    struct ListNode *a_ptr, *b_ptr;
    if(head == NULL){
        return NULL;
    }
    a_ptr = head;
    cnt = 0;
    flag = 0;
    while(a_ptr){
        a_ptr = a_ptr->next;
        if(a_ptr == NULL){
            flag = 1;
            break;
        }
        cnt ++;
        if(cnt == k - 1){
            break;
        }
    }
    if(flag)return head;
    head = reverse_list(head, k);
    while(a_ptr->next != NULL){
        b_ptr = a_ptr->next;
        a_ptr = a_ptr->next;
        cnt  = 0;
        while(a_ptr){
            a_ptr = a_ptr->next;
            if(a_ptr == NULL){
                flag = 1;
                break;
            }
            cnt ++;
            if(cnt == k - 1){
                break;
            }
        }
        if(flag)break;
        b_ptr = reverse_list(b_ptr, k);
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


    struct ListNode *node = reverseKGroup(ptr_1, 11);
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
