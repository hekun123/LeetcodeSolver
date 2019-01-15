#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define min(a, b) (a>b?b:a)
#define max(a, b) (a>b?a:b)
int largestRectangleArea(int* heights, int heightsSize) {
    if( NULL == heights || 0 == heightsSize)
        return 0;
    int res = 0;
    for (int i = 0; i < heightsSize; ++i) {
        if (i + 1 < heightsSize && heights[i] <= heights[i + 1]) {
            continue;
        }
        int minH = heights[i];
        for (int j = i; j >= 0; --j) {
            minH = min(minH, heights[j]);
            int area = minH * (i - j + 1);
            res = max(res, area);
        }
    }
    return res;
}


int main(){
    int ans[] = {0,0,0,0,0,0,0,0,2147483647};
    printf("%d\n", largestRectangleArea(ans, sizeof(ans)/sizeof(ans[0])));
    return 0;
}
