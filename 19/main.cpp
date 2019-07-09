#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.

 */
struct ListNode {
    int val;
    struct ListNode *next;
 };
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* ptr = head, *ptr_for;
    int struct_len = 1, cnt;
    while(ptr->next != NULL){
        struct_len ++;
        ptr = ptr->next;
    }
    if(struct_len == 1){
        return NULL;
    }
    int dele_len = struct_len - n + 1;
    if(dele_len == 1){
        head = head->next;
    }
    ptr = head;
    cnt = 2;
    while(ptr->next){
        ptr_for = ptr;
        ptr = ptr->next;
        if(cnt == dele_len){
            ptr_for->next = ptr->next;
            break;
        }
        cnt ++;
    }
    return head;
}
int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = NULL;
    struct ListNode *ptr = head;
    for(int i = 0 ; i < 0;  i ++){
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = i+2;
        node->next = NULL;
        ptr->next = node;
        ptr = ptr->next;
    }
    head = removeNthFromEnd(head, 1);
    ptr = head;
    while(ptr){
        printf("%d\t", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
    return 0;
}
