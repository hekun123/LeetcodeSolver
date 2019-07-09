#include <stdio.h>
#include <string.h>
#include <stdlib.h>


 /* Definition for a binary tree node.*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *pstPre, *pstA, *pstB;

void dfs(struct TreeNode *pstCur){
    if(NULL == pstCur){
        return ;
    }
    dfs(pstCur->left);

    if(!pstPre) pstPre = pstCur;
    else{
        if(pstPre->val > pstCur->val){
            if(!pstA){
                pstA = pstPre;
            }
            pstB = pstCur;
        }
        pstPre = pstCur;
    }

    dfs(pstCur->right);
}


void swap(int *a, int *b){
    int c ;
    c = *a;
    *a = *b;
    *b = c;
}

void recoverTree(struct TreeNode* root) {
    pstPre = pstA = pstB = NULL;

    dfs(root);
    swap(&(pstA->val), &(pstB->val));
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
    node[2].val = 3;
    node[5].val = 2;
    node[1].right = NULL;
    node[2].left = NULL;
    node[5].left = node[5].right = NULL;

    recoverTree(&node[1]);
    for(int i = 0 ; i < 11 ; i ++){
        printf("%d ", node[i].val);
    }
    printf("\n");

    return 0;
}
