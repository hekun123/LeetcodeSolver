#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int add(int a,int b){
    if(b == 0)return a;

    int yihuo, yu;
    yihuo = a^b;
    yu = (a&b)<<1;
    return add(yihuo, yu);
}

int get_negetive(int a){
    return add(~a, 1);
}

int get_positive(int a){
    if(a >= 0){
        return a;
    }else{
        return get_negetive(a);
    }
}

int minus(int a, int b){
    return add(a, get_negetive(b));
}

int is_result_positive(int a, int b){
    if((a>0&&b<0) || (a<0&&b>0)){
        return 1;
    }else{
        return 0;
    }
}

int divide(int dividend, int divisor) {
    if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
        return INT_MAX;

    unsigned int B = (divisor < 0) ? -divisor : divisor;
    unsigned int A = (dividend < 0) ? -dividend : dividend;

    int result_flag = 0;
    result_flag = (dividend > 0)^(divisor > 0);

    int i = 31;
    int ans = 0;
    while(i >= 0){
        if((A>>i) >= B){
            ans = add(ans, 1<<i);
            A = minus(A, B<<i);
            if(A == 0)break;
        }
        i = minus(i, 1);
    }
    if(result_flag){
        ans = get_negetive(ans);
    }
    return ans;
}

int main(){
    printf("%ld\n", divide(10, 3));
    return 0;
}
