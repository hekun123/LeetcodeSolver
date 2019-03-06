#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p && !q){
        return false;
    }
    if(q && ! p){
        return false;
    }
    if(!p && !q){
        return true;
    }
    if(p->val != q->val){
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(){

    struct TreeNode node[11], node2[11];
    for(int i = 0 ; i < 11 ; i ++){
        node[i].val= i;
        node[i].left = NULL;
        node[i].right = NULL;
        node2[i].val= i;
        node2[i].left = NULL;
        node2[i].right = NULL;
    }
    for(int i = 1 ; i <= 4 ; i ++){
        node[i].left = &node[i<<1];
        node[i].right = &node[i<<1|1];
        node2[i].left = &node2[i<<1];
        node2[i].right = &node2[i<<1|1];
    }
    node[5].left = &node[10];
    node2[5].left = NULL;//&node2[10];

    printf("%s\n", isSameTree(&node[1], &node2[1])? "YES" : "NO");
    return 0;
}
