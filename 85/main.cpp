#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    if(matrix == NULL || matrixRowSize <= 0 || matrixColSize <= 0 ){
        return 0;
    }

    int ans[matrixColSize];
    memset(ans, 0, sizeof(ans));

    int max_ans = -1;
    for(int i = 0 ; i < matrixRowSize ; i ++){
        for(int j = 0 ; j < matrixColSize; j ++){
            if(matrix[i][j] == '1'){
                ans[j] += 1;
            }else{
                ans[j] = 0;
            }
        }
        max_ans = max(max_ans, largestRectangleArea(ans, matrixColSize));
    }
    return max_ans;
}

int main(){

    char a[][100] = {
    {"10"},
    {"01"}
//        {"10100"},
//        {"10111"},
//        {"01101"},
//        {"10000"}
    };
    char *ans[100];
    for(int i = 0 ; i < 2 ; i ++){
        ans[i] = a[i];
    }
    printf("%d\n", maximalRectangle(ans, 2, 2));
    return 0;
}
