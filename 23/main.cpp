#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    c_ptr->next = NULL;
    if(a_ptr != NULL){
        c_ptr->next = a_ptr;
    }
    if(b_ptr != NULL){
        c_ptr->next = b_ptr;
    }
    return head;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0){
        return NULL;
    }
    int i;
    int l_num = listsSize;
    while(l_num != 1){

        for(i = 0 ; i < (l_num/2)*2; i = i + 2){
            lists[i/2] = mergeTwoLists(lists[i], lists[i+1]);
        }

        if(l_num%2){
            lists[(i)/2] = lists[i];
            l_num += 2;
        }
        l_num /= 2;
    }
    return lists[0];
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
    while(ptr_1->next){
        printf("%d->", ptr_1->val);
        ptr_1 = ptr_1->next;
    }
    printf("%d\n", ptr_1->val);

    while(ptr_2->next){
        printf("%d->", ptr_2->val);
        ptr_2 = ptr_2->next;
    }
    printf("%d\n", ptr_2->val);

    while(ptr_3->next){
        printf("%d->", ptr_3->val);
        ptr_3 = ptr_3->next;
    }
    printf("%d\n", ptr_3->val);

    while(ptr_4->next){
        printf("%d->", ptr_4->val);
        ptr_4 = ptr_4->next;
    }
    printf("%d\n", ptr_4->val);


    struct ListNode *ans = mergeKLists(head,3);
    struct ListNode *ans_ptr = ans;
    int cnt  = 0;
    if(ans_ptr == NULL){
        printf("There is nothing to return!\n");
        return 0;
    }
    while(ans_ptr->next){
        printf("%d->", ans_ptr->val);
        ans_ptr = ans_ptr->next;
    }
    printf("%d\n", ans_ptr->val);

    return 0;
}
