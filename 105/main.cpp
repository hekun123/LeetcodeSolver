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
        (*index) ++;
        return node;
    }
    int mid = startIndex;
    while(inorder[mid] != preorder[*index]){
        mid ++;
    }

    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = preorder[*index];
    (*index) ++;

    node->left = build(inorder, startIndex, mid-1, preorder, index);
    node->right = build(inorder, mid+1, endIndex, preorder, index);
    return node;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int index = 0;
    struct TreeNode *root = build(inorder, 0, inorderSize-1, preorder, &index);
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
    int pre[] = {};//{35,26,12,39,49,15,32,78,61,14};
    int in[] =  {};//{39,12,49,26,32,15,35,61,78,14};
    struct TreeNode *root = buildTree(pre, sizeof(pre)/sizeof(int), in, sizeof(in)/sizeof(int));
    show(root);
    return 0;
}
