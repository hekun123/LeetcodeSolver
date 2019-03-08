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

bool dfsTest(struct TreeNode* pstNode1, struct TreeNode* pstNode2){
    if(pstNode1 == NULL && pstNode2 == NULL){
        return true;
    }
    if(pstNode1 == NULL || pstNode2 == NULL){
        return false;
    }
    if(pstNode1->val != pstNode2->val){
        return false;
    }
    return dfsTest(pstNode1->left, pstNode2->right)
                && dfsTest(pstNode1->right,  pstNode2->left);

}

bool isSymmetric(struct TreeNode* root) {
    if(root == NULL){
        return true;
    }
    return dfsTest(root, root);
}

int main(){
    struct TreeNode node[11];
    for(int i = 0 ; i < 11 ; i ++){
        node[i].val= i;
        node[i].left = NULL;
        node[i].right = NULL;
    }
    for(int i = 1 ; i <= 4 ; i ++){
        node[i].left = &node[i<<1];
        node[i].right = &node[i<<1|1];
    }
    node[5].left = &node[10];


    node[4].left = NULL; node[4].right = NULL;
    node[5].left = NULL; node[5].right = NULL;
    node[2].val = node[3].val = 2;
    node[4].val = node[7].val = 3;
    node[5].val = node[6].val = 4;
    node[2].left = node[3].right = NULL;

    printf("%s\n", isSymmetric(&node[1])?"YES" : "NO");
    return 0;
}
