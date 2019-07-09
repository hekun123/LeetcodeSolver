#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define Mid(x, y) ((x+y)>>1)

struct _edg {
    double x;
    int val;
    double up;
    double down;
}Edg[5000*2];

double Y[5000];

int cmp(struct _edg e1, struct _edg e2){
    return e1.x < e2.x;
}

typedef struct _node{
    int val;int l;int r; double len;
    struct _node *left;
    struct _node *right;
}Node;

Node * build(int left, int right){
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = 0; node->l = left; node->r = right; node->len = 0;
    node->left = NULL; node->right = NULL;
    if(left == right){
        return node;
    }

    int mid = Mid(left, right);
    node->left = build(left, mid);
    node->right = build(mid+1, right);
    return node;
}

void update(Node *node, int left, int right, int UpdateVal){
    if(left == node->l && right == node->r){
        node->val += UpdateVal;
        if(node->val){
            node->len = Y[node->r+1] - Y[node->l];
        }else if(node->l == node->r){
            node->len = 0;
        }else{
            node->len = node->left->len + node->right->len;
        }
        return;
    }

    int mid = Mid(node->l, node->r);

    if(mid < left){
        update(node->right, left, right, UpdateVal);
    }else if(mid >= right){
        update(node->left, left, right, UpdateVal);
    }else{
        update(node->left, left, mid, UpdateVal);
        update(node->right, mid+1, right, UpdateVal);
    }
    if(node->val){
        node->len = Y[node->r + 1] - Y[node->l];
    }else if(node->l == node->r){
        node->len = 0;
    }else{
        node->len = node->left->len + node->right->len;
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    double x1, y1, x2, y2;
    int count = 1;
    while(scanf("%d", &n) != EOF){
        if(n == 0)break;
        int cnt = 0;
        for(int i = 0 ; i < n ; i ++){
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            Edg[cnt].x = x1;Edg[cnt].val = 1;   Edg[cnt].down = y1; Edg[cnt].up = y2;
            Edg[cnt+1].x = x2;Edg[cnt+1].val = -1;  Edg[cnt+1].down = y1; Edg[cnt+1].up = y2;
            Y[cnt] = y2;Y[cnt+1] = y1;
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
        Node *root = build(0, k-1);
        int l = 0;int r = 0;
        double ans = 0;
        for(int i = 0 ; i < cnt-1; i ++){
            l = lower_bound(Y, Y+k, Edg[i].down) - Y;
            r = lower_bound(Y, Y+k, Edg[i].up) - Y - 1;
            update(root, l, r, Edg[i].val);
            ans += (Edg[i+1].x - Edg[i].x) * root->len;
        }
        printf("Test case #%d\n", count  ++);
        printf("Total explored area: %.2lf\n\n", ans);
    }

    return 0;
}
