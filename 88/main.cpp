#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int* nums1, int m, int* nums2, int n) {

    int i = 0, j = 0;
    for(; i < m ; i ++){
        int begin = -1;
        for(; j < n ; j ++){
            if(nums2[j] < nums1[i]){
                if(-1 == begin){
                    begin = j;
                }
            }else{
                if(begin != -1){
                    int move1len = m-i;
                    int len2 = j - begin;
                    for(int k = 0 ; k < move1len; k ++){
                        nums1[m+len2-k-1] = nums1[m-k-1];
                    }
                    for(int k = 0 ; k < len2 ; k ++){
                        nums1[i+k] = nums2[begin+k];
                    }
                    begin = -1;
                    m += len2;
                    i += len2;
                    break;
                }
                break;
            }
        }
        if(begin != -1){
            int move1len = m-i;
            int len2 = j - begin;
            for(int k = 0 ; k < move1len; k ++){
                nums1[m+len2-k-1] = nums1[m-k-1];
            }
            for(int k = 0 ; k < len2 ; k ++){
                nums1[i+k] = nums2[begin+k];
            }
            break;
        }
    }
    if(i >= m && j < n){
        for(;j < n ; j ++, i ++){
            nums1[i] = nums2[j];
        }
    }
}

int main(){
    int a[] = {1,2,3,0,0,0};
    int b[] = {2,5,6};
    int *aa = (int *)&a;
    int *bb = (int *)&b;
    int m = 3;
    int n = sizeof(b)/sizeof(b[0]);
    //printf("%d %d\n", sizeof(a)/sizeof(a[0]), sizeof(b)/sizeof(b[0]));
    merge(aa, m, bb, n);
    for(int i = 0 ; i < m+n; i ++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
