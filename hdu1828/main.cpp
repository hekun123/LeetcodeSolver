#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct _edg {
    double x;
}Edg[5000*2];

double Y[5000];

int cmp(struct _edg e1, struct _edg e2){
    return e1.x < e2.x;
}

typedef struct _node{
    int val;
    struct _node *left;
    struct _node *right;
}Node;

Node * build(int left, int right){
    Node *node = (Node *)malloc(sizeof(Node));
    if(left == right){
        node->val = 0;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    int mid = (left+right)>>1;
    node->left = build(left, mid);
    node->right = build(mid+1, right);
    return node;
}

int main(){
    int n;
    double x1, y1, x2, y2;
    while(scanf("%d", &n) != EOF){
        int cnt = 0;
        for(int i = 0 ; i < n ; i ++){
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            Edg[cnt].x = x1;Edg[cnt+1].x = x2;
            Y[cnt] = y1;Y[cnt+1] = y2;
            cnt += 2;
        }
        sort(Edg, Edg+cnt, cmp);
        sort(Y, Y+cnt);
        int k = 1;
        for(int i = 1 ; i < cnt ;i ++){
            if(Y[i] != Y[i-1]){
                Y[k++] = Y[i];
            }
        }
        Node *root = build(1, k);
        for(int i = )

    }

    return 0;
}
