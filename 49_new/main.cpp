#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int primeNum;
    int flag_i;
    struct node *left, *right;
    node():primeNum(0), flag_i(-1), left(NULL), right(NULL){}
} TreeNode;

TreeNode* treeInsert(TreeNode *node, int primeNum, int flag_i){
    if(!node){
        node = (TreeNode *)malloc(sizeof(TreeNode));
        node->primeNum = primeNum;
        node->flag_i = flag_i;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    if(node->primeNum > primeNum){
        node->left = treeInsert(node->left, primeNum, flag_i);
    }else{
        node->right = treeInsert(node->right, primeNum, flag_i);
    }
    return node;
}

int treeFind(TreeNode *node, int primeNum){
    if(!node){
        return -1;
    }
    if(node->primeNum == primeNum){
        return node->flag_i;
    }else if(node->primeNum > primeNum){
        return treeFind(node->left, primeNum);
    }else{
        return treeFind(node->right, primeNum);
    }
}
void treeFree(TreeNode *node){
    if(!node){
        return;
    }
    treeFree(node->left);
    treeFree(node->right);
    free(node);
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize){
    int PRIME[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
                    67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137,
                    139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211,
                    223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283,
                    293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379,
                    383, 389, 397, 401, 409, 419, 421, 431, 433, 439};
    char ***returnAns   = NULL;
    int *returnCol     = NULL;
    TreeNode *head      = NULL;
    int cnt             = 0;
    int i, j, flag_i, strLen, primeNum;

    for(i = 0 ; i < strsSize ; i ++){
        primeNum = 1;
        strLen = strlen(strs[i]);
        for(j = 0 ; j < strLen ; j ++){
            primeNum *= PRIME[strs[i][j] - 'a'];
        }
        flag_i = treeFind(head, primeNum);
        if(flag_i == -1){
            head = treeInsert(head, primeNum, cnt);
            cnt ++;
            returnAns = (char ***)realloc(returnAns, sizeof(char**)*cnt);
            returnAns[cnt-1] = NULL;
            returnCol = (int *)realloc(returnCol, sizeof(int*)*cnt);
            returnCol[cnt-1] = 0;
            flag_i = cnt-1;
        }
        returnCol[flag_i] ++;
        returnAns[flag_i] = (char**)realloc(returnAns[flag_i], sizeof(char*)*returnCol[flag_i]);
        returnAns[flag_i][returnCol[flag_i]-1] = (char *)malloc(sizeof(char)*(strLen+1));
        memcpy(returnAns[flag_i][returnCol[flag_i]-1], strs[i], strLen+1);
    }
    treeFree(head);
    (*columnSizes) = returnCol;
    (*returnSize)  = cnt;
    return returnAns;
}

int main(int argc, char** argv)
{
    char *abc[10]={
        "asdfads", "tqwerqwea", "tan", "ate", "nat", "bat"
    };
    int *aaLen = NULL;
    char ***returnAsn = NULL;
    int n;
    returnAsn = groupAnagrams(abc, 6, (int **)&aaLen, &n);
    for(int i = 0 ; i < n ; i ++) {
        for(int j = 0 ; j < aaLen[i]; j ++){
            printf("%s\t", returnAsn[i][j]);
        }
        printf("\n");
    }
    return 0;
}
