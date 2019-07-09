#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;


int convert(char ch){
    int ans = 0;
    if(ch == 'I')ans = 1;
    if(ch == 'V')ans = 5;
    if(ch == 'X')ans = 10;
    if(ch == 'L')ans = 50;
    if(ch == 'C')ans = 100;
    if(ch == 'D')ans = 500;
    if(ch == 'M')ans = 1000;
    return ans;
}
int romanToInt(char* s) {
    int len = strlen(s);
    int i = len - 1;
    int ans = convert(s[i --]);
    while(i >= 0){
        if(convert(s[i]) < convert(s[i+1])){
            ans -= convert(s[i]);
        }else{
            ans += convert(s[i]);
        }
        i --;
    }
    return ans;
}


int main()
{
    printf("%d\n", romanToInt("MMMCMXCIX"));
    return 0;
}
