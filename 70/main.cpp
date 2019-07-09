#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int climbStairs(int n) {
    if(n <= 2){
        return n;
    }
    int a = 1;
    int b = 1;
    int c;
    for(int i = 1 ; i < n ; i ++){
        c = a + b;
        b = a;
        a = c;
    }
    return a;
}

int main()
{
    printf("%d\n", climbStairs(4));
    return 0;
}
