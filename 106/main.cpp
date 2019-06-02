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


struct TreeNode* build(int *inorder, int startIndex, int endIndex, int *preorder, int *index){
    if(startIndex > endIndex){
        return NULL;
    }
    if(startIndex == endIndex){
        struct TreeNode *node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        node->left = NULL;
        node->right = NULL;
        node->val = preorder[*index];
        (*index) --;
        return node;
    }
    int mid = endIndex;
    while(inorder[mid] != preorder[*index]){
        mid --;
    }

    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = preorder[*index];
    (*index) --;

    node->right = build(inorder, mid+1, endIndex, preorder, index);
    node->left = build(inorder, startIndex, mid-1, preorder, index);

    return node;
}


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int index = postorderSize-1;
    struct TreeNode *root = build(inorder, 0, inorderSize-1, postorder, &index);
    return root;
}

void show(struct TreeNode *node){
    if(node == NULL){
        return ;
    }
    show(node->left);
    printf("%d ", node->val);
    show(node->right);
}

int main(){
    int in[] = {39,12,49,26,32,15,35,61,78,14};
    int pst[] = {39,49,12,32,15,26,61,14,78,35};
    struct TreeNode *root = buildTree(in, sizeof(in)/sizeof(int), pst, sizeof(pst)/sizeof(int));
    show(root);
    return 0;
}
