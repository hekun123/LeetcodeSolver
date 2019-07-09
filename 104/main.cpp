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

void dfs(struct TreeNode *node, int *depth, int step){
    if(node == NULL){
        return ;
    }
    if(*depth < step){
        *depth = step;
    }
    dfs(node->left, depth, step+1);
    dfs(node->right, depth, step+1);
}

int maxDepth(struct TreeNode* root) {
    if(!root) return 0;

    int sum1 = maxDepth(root->left), sum2 = maxDepth(root->right);

    return 1 + (sum1 > sum2?sum1 : sum2);
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

    printf("%d\n", maxDepth(&node[1]));
    return 0;
}
