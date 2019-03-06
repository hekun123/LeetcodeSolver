#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool build(struct TreeNode *treeNode, long long iLeftVal, long long iRightVal){
    if(treeNode == NULL){
        return true;
    }

    if(treeNode->left){
        if(0 < iLeftVal -  treeNode->val){
            return false;
        }
        if(treeNode->val <= treeNode->left->val){
            return false;
        }
        if(!build(treeNode->left, iLeftVal, treeNode->val-1)){
            return false;
        }
    }

    if(0 >  iRightVal - treeNode->val){
        return false;
    }

    if(treeNode->left && ){
        return false;
    }

    if(treeNode->right && !build(treeNode->right, treeNode->val+1, iRightVal)){
        return false;
    }

    return true;
}

bool isValidBST(struct TreeNode* root) {
    return build(root, INT_MIN-1, INT_MAX+1);
}

int main(){
    struct TreeNode node[13];
    for(int i = 0 ; i < 13 ; i ++){
        node[i].val= i;
        node[i].left = NULL;
        node[i].right = NULL;
    }
    for(int i = 1 ; i <= 5 ; i ++){
        node[i].left = &node[i<<1];
        node[i].right = &node[i<<1|1];
    }
    node[6].left = &node[12];

    node[1].val = -2147483648;
    node[2].val = -2147483648;
    node[3].val = 15;
    node[6].val = 11;
    node[7].val = 2147483647;

    node[1].left = NULL;
    node[2].left = NULL; node[2].right = NULL;
    node[6].left = NULL; node[6].right = NULL;
    node[7].left = NULL; node[7].right = NULL;


    printf("%s\n", isValidBST(&node[1])?"YES":"NO");
    return 0;
}
