#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int isCarry = 0;
    for(int i = digitsSize-1 ; i >= 0 ; i --){
        int num = 0;
        if(i == digitsSize-1){
            num = digits[i] + 1;
        }else{
            num = digits[i] + isCarry;
        }
        isCarry = 0;
        if(num == 10){
            isCarry = 1;
            digits[i] = 0;
        }else{
            digits[i] = num;
        }
    }

    if(isCarry){
        int *returnAns = (int *)malloc(sizeof(int)*(digitsSize+1));
        for(int i = 0 ; i < digitsSize+1 ; i ++){
            if(i == 0){
                returnAns[i] = 1;
            }else{
                returnAns[i] = 0;
            }
        }
        (*returnSize) = digitsSize+1;
        return returnAns;
    }else{
        (*returnSize) = digitsSize;
        return digits;
    }
}

int main()
{
    int a[] = {4,3,2};
    int num;
    int *ans = plusOne(a, 3, &num);
    for(int i = 0 ; i < num ; i ++){
        printf("%d ", ans[i]);
    }
    return 0;
}
