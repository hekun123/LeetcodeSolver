#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mySqrt(int x) {

    if (x ==0 || x == 1)
        return x;
    long int low = 1;
    long int high = x/2;
    long int res;
    long int mid;
    while(low <= high)
    {
        mid = (low+high)/2;

        if(x == (mid*mid))
           return mid;

        if((mid * mid) < x ){
            low = mid+1;
            res = mid;
        }
        else{
            high = mid-1;
        }
    }
    return res;
}

int main()
{
    printf("%d\n", mySqrt(5));
    return 0;
}
