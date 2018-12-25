#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trap(int* height, int heightSize) {
    int start, end, ptr, start_i, end_i;
    int ans = 0, temp_ans = 0;
    start = 0; ptr = 0; end = 0;
    start_i = 0; end_i = 0;
    while(ptr < heightSize){
        while(ptr < heightSize-1 && height[ptr] <= height[ptr+1])ptr++;
        start = height[ptr];
        start_i = ptr;
        ptr ++;
        temp_ans = 0;
        while(ptr < heightSize && height[ptr] < start) {
            temp_ans += start-height[ptr];
            ptr ++;
        }
        if(ptr < heightSize){
            end = height[ptr];
            end_i = ptr;
            ans += temp_ans;
        }
    }
    if(end_i == heightSize-1){
        return ans;
    }else {
        ptr = heightSize-1;
        while(ptr>=end_i){
            while(ptr > end_i && height[ptr] < height[ptr-1])ptr--;
            if(ptr <= end_i){
                return ans;
            }
            start = height[ptr];
            start_i = ptr;
            ptr --;
            temp_ans = 0;
            while(ptr>=end_i && height[ptr] < start){
                temp_ans += start - height[ptr];
                ptr --;
            }
            if(ptr >= end_i){
                end = height[ptr];
                ans += temp_ans;
            }
        }
    }
    return ans;
}

int main() {
    int a[] = {1,0,5,4,3,2,4};
    int ans = trap(a, 7);
//    if(ans == 0){
//        printf("fasdf\n");
//    }
    printf("%d\n", ans);
    return 0;
}
