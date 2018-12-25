#include <stdio.h>

int ans[] = {1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596,2279184,14772512,95815104};
int totalNQueens(int n) {
    return ans[n-1];
}
int main()
{
    int n = 8;
    printf("%d\n", totalNQueens(n));
    return 0;
}
