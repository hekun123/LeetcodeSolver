#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* multiply(char* num1, char* num2) {

    if(num1 == NULL || num2 == NULL) {
        return NULL;
    }
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if(len1 < 0 || len2 < 0) {
        return NULL;
    }
    if(len1 == 1 && num1[0] == '0')return "0";
    if(len2 == 1 && num2[0] == '0')return "0";
    char *ans = (char *)malloc(sizeof(char)*50000);
    memset(ans, '0', sizeof(char)*50000);

    int i, j, cnt, adding, cal_tmp;
    for(i = len1-1; i >= 0; i --) {
        cnt = len1-1-i;
        adding = 0;
        for(j = len2-1; j >= 0 ; j --) {
            cal_tmp = (num1[i]-'0')*(num2[j]-'0')+(ans[cnt]-'0');
            if(adding) {
                cal_tmp += adding;
            }
            ans[cnt] = cal_tmp%10 + '0';
            adding = cal_tmp/10;
            cnt ++;
        }
        if(adding) {
            ans[cnt] = adding+'0';
        }
    }
    ans[++cnt] = '\0';
    int tmp;
    for(i = 0 ; i < cnt/2; i ++) {
        tmp = ans[i];
        ans[i] = ans[cnt-i-1];
        ans[cnt-i-1] = tmp;
    }
    while(ans[0] == '0') {
        ans += 1;
    }
    return ans;
}

int main() {
    char *a, *b;
    a = NULL;
    b = NULL;
    printf("%s\n", multiply("9", "99"));

    return 0;
}
