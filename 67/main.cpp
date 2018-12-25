#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b){
    return a>b?a:b;
}

char* addBinary(char* a, char* b) {
    int aLen = strlen(a);
    int bLen = strlen(b);
    int cLen = 0;
    if(aLen == bLen && a[0] == '1' && b[0] == '1'){
        cLen = aLen + 1;
    }else{
        cLen = max(aLen, bLen);
    }
    char *c = (char *)malloc(sizeof(char)*cLen+2);
    int aP = aLen-1, bP = bLen-1, cP = 0;
    int isCarry = 0;
    while(aP >= 0 && bP >= 0){
        if(a[aP] == '1' && b[bP] == '1'){
            if(isCarry){
                c[cP] = '1';
            }else{
                c[cP] = '0';
            }
            isCarry = 1;
        }else if(a[aP] == '0' && b[bP] == '0'){
            if(isCarry){
                c[cP] = '1';
                isCarry = 0;
            }else{
                c[cP] = '0';
                isCarry = 0;
            }
        }else{
            if(isCarry){
                c[cP] = '0';
                isCarry = 1;
            }else{
                c[cP] = '1';
                isCarry = 0;
            }
        }
        aP --;bP --;cP ++;
    }
    while(aP >= 0){
        if(isCarry){
            if(a[aP] == '1'){
                c[cP] = '0';
                isCarry = 1;
            }else{
                c[cP] = '1';
                isCarry = 0;
            }
        }else{
            c[cP] = a[aP];
            isCarry = 0;
        }
        cP ++;aP --;
    }
    while(bP >= 0){
        if(isCarry){
            if(b[bP] == '1'){
                c[cP] = '0';
                isCarry = 1;
            }else{
                c[cP] = '1';
                isCarry = 0;
            }
        }else{
            c[cP] = b[bP];
            isCarry = 0;
        }
        bP --;cP ++;
    }
    if(isCarry){
        c[cP] = '1';
        ++cP;
    }
    for(int i = 0 ; i < cP/2; i ++){
        int tmp = c[i];
        c[i] = c[cP-1-i];
        c[cP-1-i] = tmp;
    }
    c[cP] = '\0';
    return c;
}

int main()
{
    char a[] = "11";
    char b[] = "110";
    char *ans = addBinary(a, b);
    printf("%s\n", ans);
    return 0;
}
