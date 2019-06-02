#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



bool hasPathSum(struct TreeNode* root, int sum) {
    if(root == NULL){
        return false;
    }
    sum = sum - root->val;
    if(root->left == NULL && root->right == NULL && sum == 0){
        return true;
    }
    return hasPathSum(root->left, sum) ||
            hasPathSum(root->right, sum);
}

int main(){
    struct TreeNode pcTreeNode[10];
    int iNum[] = {5,4,8,11,13,4,7,2,1};
    for(int i = 0 ; i < sizeof(iNum)/sizeof(int) ; ++ i){
        pcTreeNode[i].val = iNum[i];
        pcTreeNode[i].left = NULL;
        pcTreeNode[i].right = NULL;
    }
    pcTreeNode[0].left = &pcTreeNode[1];
    pcTreeNode[0].right = &pcTreeNode[2];
    pcTreeNode[1].left = &pcTreeNode[3];
    pcTreeNode[2].left = &pcTreeNode[4];
    pcTreeNode[2].right = &pcTreeNode[5];
    pcTreeNode[3].left = &pcTreeNode[6];
    pcTreeNode[3].right = &pcTreeNode[7];
    pcTreeNode[5].right = &pcTreeNode[8];
    printf("%s\n", hasPathSum(&pcTreeNode[0], 22)?"YES":"NO");
    return 0;
}
