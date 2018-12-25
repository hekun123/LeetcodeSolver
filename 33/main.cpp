#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node{
    int val;
    int i;
    struct _node *left, *right;
}tree_node;

void build_tree(tree_node **head, int val, int i){

    if((*head) == NULL){
        (*head) = (tree_node *)malloc(sizeof(tree_node));
        (*head)->val = val;
        (*head)->i = i;
        (*head)->left = NULL;
        (*head)->right = NULL;
        return;
    }else if((*head)->val > val){
        build_tree(&(*head)->left, val, i);
    }else{
        build_tree(&(*head)->right, val, i);
    }
}

int find_node(tree_node *node, int val){
    if(node == NULL){
        return -1;
    }
    if(node->val == val){
        return node->i;
    }
    if(node->val > val){
        return find_node(node->left, val);
    }else{
        return find_node(node->right, val);
    }
}

int search(int* nums, int numsSize, int target) {
    int i;
    tree_node *head = NULL;
    for(i = 0 ; i < numsSize ; i ++){
        build_tree(&head, nums[i], i);
    }
    return find_node(head, target);
}

int main(){
    int a[] = {4,5,6,7,0,1,2};
    int n = 7;
    printf("%d\n", search(a, n, 0));
    return 0;
}
