#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
  */
struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for a binary tree node.
  */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


//先序遍历输出树结构
void show(struct TreeNode *node){
    if(node == NULL){
        return;
    }
    printf("%d ", node->val);
    show(node->left);
    show(node->right);
}

int FindListLen(struct ListNode *pcListPtr){
    if(pcListPtr == NULL){
        return 0;
    }
    return FindListLen(pcListPtr->next)+1;
}

struct TreeNode *ConverCore(struct ListNode **pcListPtr, int iStart, int iEnd){
    if(iStart >= iEnd){
        return NULL;
    }
    int iIndex = (iStart+iEnd)/2;

    struct TreeNode *pcNodePtr = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    pcNodePtr->left = ConverCore(pcListPtr, iStart, iIndex);
    struct ListNode *pcList = (*pcListPtr);
    pcNodePtr->val = pcList->val;
    (*pcListPtr) = pcList->next;
    pcNodePtr->right = ConverCore(pcListPtr, iIndex+1, iEnd);
    return pcNodePtr;
};


struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head == NULL){
        return NULL;
    }
    int iListLength = FindListLen(head);
    struct TreeNode *pcTreeRoot = ConverCore(&head, 0, iListLength);
    return pcTreeRoot;
}

int main(){
    struct ListNode pcListNode[10];
    for(int i = 0 ; i < 10-1 ; i ++ ){
        pcListNode[i].val = i;
        pcListNode[i].next = &pcListNode[i+1];
    }
    pcListNode[9].val = 9;
    pcListNode[9].next = NULL;
    struct TreeNode *pcTreeNode = sortedListToBST(pcListNode);
    show(pcTreeNode);

    return 0;
}

