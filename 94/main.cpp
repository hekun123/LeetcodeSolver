#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *pcRetnVctor;
int cnt;
void dfs(struct TreeNode *node){
    if(NULL == node)return;

    dfs(node->left);

    cnt ++;
    pcRetnVctor = (int *)realloc(pcRetnVctor, sizeof(int)*cnt);
    pcRetnVctor[cnt-1] = node->val;

    dfs(node->right);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    pcRetnVctor = NULL;
    cnt = 0;
    dfs(root);
    (*returnSize) = cnt;
    return pcRetnVctor;
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



    node[1].val = 1;
    node[2].val = 2;
    node[3].val = 3;
    node[1].left = NULL;
    node[1].right = &node[2];
    node[2].left = &node[3];
    node[2].right = NULL;
    node[3].left = NULL;
    node[3].right = NULL;
    int ansCnt = 0;
    int *vect = inorderTraversal(&node[1], &ansCnt);
    for(int i = 0 ; i < ansCnt ; i ++){
        printf("%d ", vect[i]);
    }
    printf("\n");

    return 0;
}
