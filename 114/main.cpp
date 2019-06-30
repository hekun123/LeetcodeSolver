#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void ConstructTreeList(struct TreeNode *pcTreeNode, struct TreeNode **pc2ListNodePtr){
    if(pcTreeNode == NULL){
        return;
    }
    struct TreeNode *pcLeftPtr = pcTreeNode->left;
    struct TreeNode *pcRightPtr = pcTreeNode->right;

    (*pc2ListNodePtr)->right = pcTreeNode;
    (*pc2ListNodePtr)->left = NULL;
    (*pc2ListNodePtr) = pcTreeNode;
    ConstructTreeList(pcLeftPtr, pc2ListNodePtr);
    ConstructTreeList(pcRightPtr, pc2ListNodePtr);
}

void flatten(struct TreeNode* root){
    if(root == NULL){
        return ;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    //左子的遍历返回左子中最大的结点
    ConstructTreeList(root, &root);
}

int main(){
    struct TreeNode node[7];
    for(int i = 0 ; i < 7 ; ++ i){
        node[i].val = i;
        node[i].left = NULL;
        node[i].right = NULL;
    }

//    node[1].left = &node[2];
//    node[1].right = &node[5];
//    node[2].left = &node[3];
//    node[2].right = &node[4];
//    node[5].right = &node[6];

    flatten(&node[1]);

    struct TreeNode *pcTreePtr = &node[1];
    while(pcTreePtr){
        printf("%d ", pcTreePtr->val);
        pcTreePtr = pcTreePtr->right;
    }
    return 0;
}
