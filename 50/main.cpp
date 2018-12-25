#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n) {
    if(x == 1 || x == 0){
        return x;
    }
    if(x == -1){
        if (n%2 == 0){
            return 1;
        }else{
            return -1;
        }
    }

    int flag = 0;
    double ans = 0.0;
    unsigned long long b = 0;
    if(n < 0){
        b = -n;
        flag = 1;
    }else{
        b = n;
    }
    ans = 1;

    while (b){
        if(b & 1) ans *= x;
        x *= x;
        b = b >> 1;
    }
    return flag == 1? 1/ans:ans;
}

int main()
{
    printf("%lf\n", myPow(1, -2147483648));
    return 0;
}
