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

//中序遍历输出树结构
void show(struct TreeNode *node){
    if(node == NULL){
        return;
    }
    show(node->left);
    printf("%d ", node->val);
    show(node->right);
}

struct TreeNode *PartitionTree(int *nums, int iStart, int iEnd){
    if(iStart >= iEnd){
        return NULL;
    }
    int iIndex = (iStart+iEnd)/2;
    struct TreeNode *pcNodePtr = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    pcNodePtr->val = nums[iIndex];
    pcNodePtr->left = PartitionTree(nums, iStart, iIndex);
    pcNodePtr->right = PartitionTree(nums, iIndex+1, iEnd);
    return pcNodePtr;

};

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if(nums == NULL || numsSize <= 0){
        return NULL;
    }
    struct TreeNode *pcRootHead = NULL;
    pcRootHead = PartitionTree(nums, 0, numsSize);
    return pcRootHead;
}

int main(){
    int nums[] = {-10,-3,0,5,9};
    struct TreeNode *root = sortedArrayToBST(nums, sizeof(nums)/sizeof(int));
    show(root);
    return 0;
}
