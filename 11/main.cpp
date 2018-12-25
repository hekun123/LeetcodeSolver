#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int maxArea(int *height, int heightSize){
    int max_vol = -1, tem_vol = -1, tem_height = -1;
    int i = 0, j = heightSize - 1;
    while(i < j){
        tem_height = min(height[i], height[j]);
        tem_vol = (j-i)*tem_height;
        if(max_vol < tem_vol){
            max_vol = tem_vol;
            tem_vol = -1;
        }
        while(height[i] <= tem_height && i < j) i ++;
        while(height[j] <= tem_height && i < j) j --;
    }
    return max_vol;
}
int main()
{
    int num[] = {1,8,6,2,5,4,8,3,7};
    int len = 9;
    printf("%d\n", maxArea(num, len));
    return 0;
}
