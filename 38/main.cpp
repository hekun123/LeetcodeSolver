#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ans[][5000] = {
    {"1"},
    {"11"},
    {"21"},
    {"1211"},
    {"111221"},
    {"312211"},
    {"13112221"},
    {"1113213211"},
    {"31131211131221"},
    {"13211311123113112211"},
    {"11131221133112132113212221"},
    {"3113112221232112111312211312113211"},
    {"1321132132111213122112311311222113111221131221"},
    {"11131221131211131231121113112221121321132132211331222113112211"},
    {"311311222113111231131112132112311321322112111312211312111322212311322113212221"},
    {"132113213221133112132113311211131221121321131211132221123113112221131112311332111213211322211312113211"},
    {"11131221131211132221232112111312212321123113112221121113122113111231133221121321132132211331121321231231121113122113322113111221131221"},
    {"31131122211311123113321112131221123113112211121312211213211321322112311311222113311213212322211211131221131211132221232112111312111213111213211231131122212322211331222113112211"},
    {"1321132132211331121321231231121113112221121321132122311211131122211211131221131211132221121321132132212321121113121112133221123113112221131112311332111213122112311311123112111331121113122112132113213211121332212311322113212221"},
    {"11131221131211132221232112111312111213111213211231132132211211131221131211221321123113213221123113112221131112311332211211131221131211132211121312211231131112311211232221121321132132211331121321231231121113112221121321133112132112312321123113112221121113122113121113123112112322111213211322211312113211"},
    {"311311222113111231133211121312211231131112311211133112111312211213211312111322211231131122211311122122111312211213211312111322211213211321322113311213212322211231131122211311123113223112111311222112132113311213211221121332211211131221131211132221232112111312111213111213211231132132211211131221232112111312211213111213122112132113213221123113112221131112311311121321122112132231121113122113322113111221131221"},
    {"132113213221133112132123123112111311222112132113311213211231232112311311222112111312211311123113322112132113213221133122112231131122211211131221131112311332211211131221131211132221232112111312111213322112132113213221133112132113221321123113213221121113122123211211131221222112112322211231131122211311123113321112131221123113111231121113311211131221121321131211132221123113112211121312211231131122211211133112111311222112111312211312111322211213211321322113311213211331121113122122211211132213211231131122212322211331222113112211"},
    {"111312211312111322212321121113121112131112132112311321322112111312212321121113122112131112131221121321132132211231131122211331121321232221121113122113121113222123112221221321132132211231131122211331121321232221123113112221131112311332111213122112311311123112112322211211131221131211132221232112111312211322111312211213211312111322211231131122111213122112311311221132211221121332211213211321322113311213212312311211131122211213211331121321123123211231131122211211131221131112311332211213211321223112111311222112132113213221123123211231132132211231131122211311123113322112111312211312111322212321121113122123211231131122113221123113221113122112132113213211121332212311322113212221"},
    {"3113112221131112311332111213122112311311123112111331121113122112132113121113222112311311221112131221123113112221121113311211131122211211131221131211132221121321132132212321121113121112133221123113112221131112311332111213213211221113122113121113222112132113213221232112111312111213322112132113213221133112132123123112111311222112132113311213211221121332211231131122211311123113321112131221123113112221132231131122211211131221131112311332211213211321223112111311222112132113212221132221222112112322211211131221131211132221232112111312111213111213211231132132211211131221232112111312211213111213122112132113213221123113112221133112132123222112111312211312112213211231132132211211131221131211132221121311121312211213211312111322211213211321322113311213212322211231131122211311123113321112131221123113112211121312211213211321222113222112132113223113112221121113122113121113123112112322111213211322211312113211"},
    {"132113213221133112132123123112111311222112132113311213211231232112311311222112111312211311123113322112132113212231121113112221121321132132211231232112311321322112311311222113111231133221121113122113121113221112131221123113111231121123222112132113213221133112132123123112111312111312212231131122211311123113322112111312211312111322111213122112311311123112112322211211131221131211132221232112111312111213111213211231132132211211131221232112111312212221121123222112132113213221133112132123123112111311222112132113213221132213211321322112311311222113311213212322211211131221131211221321123113213221121113122113121132211332113221122112133221123113112221131112311332111213122112311311123112111331121113122112132113121113222112311311221112131221123113112221121113311211131122211211131221131211132221121321132132212321121113121112133221123113112221131112212211131221121321131211132221123113112221131112311332211211133112111311222112111312211311123113322112111312211312111322212321121113121112133221121321132132211331121321231231121113112221121321132122311211131122211211131221131211322113322112111312211322132113213221123113112221131112311311121321122112132231121113122113322113111221131221"},
    {"111312211312111322212321121113121112131112132112311321322112111312212321121113122112131112131221121321132132211231131122211331121321232221121113122113121122132112311321322112111312211312111322211213111213122112132113121113222112132113213221133112132123222112311311222113111231132231121113112221121321133112132112211213322112111312211312111322212321121113121112131112132112311311123113112211221321132132211331121321232221123113112221131112311322311211131122211213211331121321122112133221123113112221131112311332111213122112311311123112111331121113122112132113121113222112311311221112131221123113112211322112211213322112111312211312111322212321121113121112131112132112311321322112111312211312111322211322111312211312111322211213211321322123211211131211121332211231131122211311122122111312211213211312111322211231131122211311122113222123122113222122211211232221121321132132211331121321231231121113112221121321133112132112312321123113112221121113122113111231133221121321132122311211131122211213211321322112312321123113213221123113112221131112311332211211131221131211132211121312211231131112311211232221121321132132211331221122311311222112111312211311123113322112132113213221133112132123222112312321123113213221123113112221133112132123222112311311222113111231133211121312211231131112311211232221121113122113124113112221131112311332111213122112311311123112111331121113122112132113121113222112311311221112131221123113112221121113311211131122211211131221131211132221121321132132212321121113121112133221123113112221131112212211131221121321131211132221123113112211"},
    {"3113112221131112311332111213122112311311123112111331121113122112132113121113222112311311221112131221123113112221121113311211131122211211131221131211132221121321132132212321121113121112133221123113112221131112212211131221121321131211132221123113112221131112311332211211133112111311222112111312211311123113322112111312211312111322212321121113121112133221121321132132211331121321132213211231132132211211131221232112111312212221121123222112311311222113111231133211121312211231131112311211133112111312211213211331121321132122212211131221131211132221232112111312111213322112132113213221133112132113221321123113213221121113122123211211131221222112112322211213211321322113311213212312311211131122211213211331121321123123211231131122211211131221131112311332211213211321223112111311222112132113212221132221222112112322211231131122211311123113321112131221123113111231121113311211131221121321131211132221123113112221131112311332211322311311222113111231133221121113122113121113221112131221123113111231121123222112132113213221133122112231131122211211131221131112311332211213211321322113312221133211121311222113321132211221121332211211131221131211132221232112111312111213111213211231132132211211131221232112111312211213111213122112132113213221123113112221133112132123222112111312211312112213211231132132211211131221131211132211132113213221133112132123123112111311222112132113311213211231232112311311222112111312211311123113322112132113212231121113112221121321132132211231232112311321322112311311222113111231133221121113122113121113221112131221123113111231121123222112132113213221133122112231131122211211131221131112311332211213211321322113311213212322211231232112311321322112311311222113311213212322211231131122211311123113321112131221123113111231121123222112111312211312111322212321121113122113221113122112132113121113222112311311221112131221123113112211322112211213322112132113213221133112132123123112111311222112132113311213211231232112311311222112111312212321121113122113121132112231131122211311123113321112131221123113"},
    {"132113213221133112132123123112111311222112132113311213211231232112311311222112111312211311123113322112132113212231121113112221121321132132211231232112311321322112311311222113111231133221121113122113121113221112131221123113111231121123222112132113213221133122112231131122211211131221131112311332211213211321322113311213212322211231232112311321322112311311222113311213212322211231131122211311123113321112131221123113111231121123222112111312211312111322212321121113122113221113122112132113121113222112311311221112131221123113112211322112211213322112132113213221133112132123123112111311222112132113311213211231232112311311222112111312212321121113122113121132112231131122211311123113321112131221123113111231121123222112111312211312111322212321121113122113221113122112132113121113222112311311221112131221123113112211322112211213322112111312211312111322212321121113121112131112132112311321322112111312212321121113122112131112131221121321132132211231131122211331121321232221121113122113121122132112311321322112111312211312113221133211322112211213322112132113213221133112132123123112111311222112132113311213211231232112311311222112111312211311123113322112132113213221133112132123222113221321132132211331121321232221123113112221131112311322311211131122211213211331121321122112133221121113122113121113222123211211131211121311121321123113213221121113122123211211131221121311121312211213211321322112311311222113311213212322211211131221131211221321123113213221121113122113121113222112131112131221121321131211132221121321132132211331121321232221123113112221131112311322311211131122211213211331121321122112133221121113122113121113222123112221221321132132211231131122211331121321232221121113122113121113222123211211131211121332211213111213122112132113121113222112132113213221232112111312111213322112132113213221133112132123123112111311222112132113311213211221121332211231131122211311123113321112131221123113112221132231131122211211131221131112311332211213211321223112111311222112132113212221132221222112112322211211131221131211132221232112111312111213111213211231132132211211131221232112111312211213111213122112132113213221123113112211121312211231131122211311122113122122132113213221133112132123123112111311222112132113311213211221121332211231131122211311123113321112131221123113112221132231131122211211131221131112311332211213211321223112111311222112132113212221132221222112112322211231131122211311123113321112131221123113111231121113311211131221121321131211132221123113112211121312211231131122211211133112111311222112111312211312111322211213211321322123211211131211121332211231131122211311122122111312211213211312111322211231131112"},
    {"111312211312111322212321121113121112131112132112311321322112111312212321121113122112131112131221121321132132211231131122211331121321232221121113122113121122132112311321322112111312211312111322211213111213122112132113121113222112132113213221133112132123222112311311222113111231132231121113112221121321133112132112211213322112111312211312111322212311222122132113213221123113112221133112132123222112111312211312111322212321121113121112133221121311121312211213211312111322211213211321322123211211131211121332211213211321322113311213212312311211131122211213211331121321122112133221123113112221131112311332111213122112311311222113223113112221121113122113111231133221121321132122311211131122211213211321222113222122211211232221121113122113121113222123211211131211121311121321123113213221121113122123211211131221121311121312211213211321322112311311221112131221123113112221131112211312212213211321322113311213212312311211131122211213211331121321122112133221123113112221131112311332111213122112311311222113223113112221121113122113111231133221121321132122311211131122211213211321222113222122211211232221123113112221131112311332111213122112311311123112111331121113122112132113121113222112311311221112131221123113112221121113311211131122211211131221131211132221121321132132212321121113121112133221123113112221131112212211131221121321131211132241131122211311123113321112131221123113111231121113311211131221121321131211132221123113112211121312211231131122211211133112111311222112111312211312111322211213211321322123211211131211121332211231131122211311122122111312211213211312111322211231131122211311123113322112111331121113112221121113122113111231133221121113122113121113222123211211131211121332211213211321322113311213211322132112311321322112111312212321121113122122211211232221123113112221131112311332111213213211221113122113121113222112132113213221232112111312111213322112311311222113111231133211121312211231131112311211232221121113311211131122211211131221131112311332211211131221131211132211121312211231131112311211232221121113122113121113222123211211131211121311121321123113213221121113122123211211131221222112112322211213211321322113311213212312311211131122211213211321322113221321132132211231131122211331121321232221121113122113121122132112311321322112111312211312113221133211322112211213322112311311222113111231133211121312211231131112311211133112111312211213211312111322211231131122111213122112311311222112111331121113112221121113122113121113222112132113212231121113112221121321132132211331222113112211221113122113121113222123211211131211121311121321123113213221121113122123211211131221222112112322211213211321322113311213212312311211131122211213211321322113221321132132211231131122211331121321232221121113122113121122132112311321322112111312211312113221133211322112211213322112132113213221133112132123123112111311222112132113311213211231232112311311222112111312211311123113322112132113212231121113112221121321132132211231232112311321322112311311222113111231133221121113122113121113221112131221123113111231121123222112132113213221133122112231131122211211131221131112311322142113213221133112132123123112111311222112132113311213211231232112311311222112111312211311123113322112132113212231121113112221121321132132211231232112311321322112311311222113111231133221121113122113121113221112131221123113111231121123222112132113213221133122112231131122211211131221131112311332211213211321322113311213212322211231232112311321322112"},
    {"3113112221131112311332111213122112311311123112111331121113122112132113121113222112311311221112131221123113112221121113311211131122211211131221131211132221121321132132212321121113121112133221123113112221131112212211131221121321131211132221123113112221131112311332211211133112111311222112111312211311123113322112111312211312111322212321121113121112133221121321132132211331121321132213211231132132211211131221232112111312212221121123222112311311222113111231133211121321321122111312211312111322211213211321322123211211131211121332211231131122211311123113321112131221123113111231121123222112111331121113112221121113122113111231133221121113122113121113221112131221123113111231121123222112111312211312111322212321121113121112131112132112311321322112111312212321121113122122211211232221121321132132211331121321231231121113112221121321132132211322132113213221123113112221133112132123222112111312211312112213211231132132211211131221131211322113321132211221121332211231131122211311123113321112131221123113111231121113311211131221121321131211132221123113112211121312211231131122211211133112111311222112111312211312111322211213211321223112111311222112132113213221133122211311221122111312211312111322212321121113121112131112132112311321322112111312212321121113122122211211232221121321132132211331121321231231121113112221121321132132211322132113213221123113112221133112132123222112111312211312112213211231132132211211131221131211322113321132211221121332211213211321322113311213212312311211131122211213211331121321123123211231131122211211131221131112311332211213211321223112111311222112132113213221123123211231132132211231131122211311123113322112111312211312111322111213122112311311123112112322211213211321322113312211223113112221121113122113111231133221121321132132211331222113321112131122211332113221122112133221123113112221131112311332111213122112311311123112111331121113122112132113121113222112311311221112131221123113112221121113311211131122211211131221131211132221121321132132212321121113121112133221123113112221131112311332111213122112311311123112112322211322311311222113111231133211121312211231131112311211232221121113122113121113222123211211131221132211131221121321131211132221123113112211121312211231131122113221122112133221121321132132211331121321231231121113121113122122311311222113111231133221121113122113121113221112131221123113111231121123222112132113213221133112132123123112111312211322311211133112111312211213211311123113223112111321322123122113222122211211232221121113122113121113222123211211131211121311121321123113213221121113122123211211131221121311121312211213211321322112311311222113311213212322211211131221131211221321123113213221121113122113121113222112131112131221121321131211132221121321132132211331121321232221123113112221131112311322311211131122211213211331121321122112133221121113122113121113222123112221221321132132211231131122211331121321232221121113122113121113222123211211131211121332211213111213122112132113121113222112132113213221232112111312111213322112132113213221133112132123123112111311222112132113311213211221121332211231131122211311123113321112131221123113112221132231131122211211131221131112311332211213211321223112111311222112132113212221132221222112112322211211131221131211132221232112111312111213111213211231131112311311221122132113213221133112132123222112311311222113111231132231121113112221121321133112132112211213322112111312211312111322212321121113121112131112132112311321322112111312212321121113122122211211232221121311121312211213211312111322211213211321322123211211131211121332211213211321322113311213211322132112311321322112111312212321121113122122211211232221121321132132211331121321231231121113112221121321133112132112312321123113112221121113122113111231133221121321132122311211131122211213211321222113222122211211232221123113112221131112311332111213122112311311123112111331121113122112132113121113222112311311221112131221123113112221121113311211131122211211131221131211132221121321132132212321121113121112133221123113112221131112311332111213213211221113122113121113222112132113213221232112111312111213322112132113213221133112132123123112111312211322311211133112111312212221121123222112132113213221133112132123222113223113112221131112311332111213122112311311123112112322211211131221131211132221232112111312111213111213211231132132211211131221131211221321123113213221123113112221131112211322212322211231131122211322111312211312111322211213211321322113311213211331121113122122211211132213211231131122212322211331222113112211"}
};
char* countAndSay(int n) {
    n = n-1;
    char *a = (char *)malloc(sizeof(char)*strlen(ans[n]) + 1);
    memcpy(a, ans[n], strlen(ans[n]));
    a[strlen(ans[n])] = '\0';
    return a;
}






void count(){
    int i, j;
    char a[][100] = {
        {"1"},
        {"11"},
        {"21"},
        {"1211"},
        {"111221"},
        {"312211"},
        {"13112221"},
        {"1113213211"},
        {"31131211131221"},
        {"13211311123113112211"}
    };

    for(i = 0 ; i < 10 ; i ++){
        memcpy(ans[i], a[i], strlen(a[i]));
        ans[i][strlen(a[i])] = '\0';
        printf("%s\n", ans[i]);
    }

    int len, ptr;
    char num, cnt;
    for (i = 10 ; i < 30 ; i ++){
        len = strlen(ans[i-1]);
        num = ans[i-1][0];
        cnt = 0;
        ptr = 0;
        for(j = 0 ; j < len ; j ++){
            if(num == ans[i-1][j]) {
                cnt ++;
            }else{
                ans[i][ptr ++] = cnt+'0';
                ans[i][ptr ++] = num;
                cnt = 1;
                num = ans[i-1][j];
            }
        }
        ans[i][ptr ++] = cnt+'0';
        ans[i][ptr ++] = num;
        ans[i][ptr] = '\0';
        printf("%s\n", ans[i]);
        //printf("ptr: %d\t%s\n", ptr, ans[i]);
    }
}

int main() {
    //freopen("input.txt", "w", stdout);
    //char *a = "31131211131221";
    //printf("%d\n", strlen(a));
    char *a = "";
    char *bns = countAndSay(30);
    printf("%s\n", strcmp(a, bns) == 0?"true":"false");
//    printf("%d: %s\n", strlen(bns), bns);
    //count();



//    char *a = "11131221131211132221232112111312111213111213211231132132211211131221131211221321123113213221123113112221131112311332211211131221131211132211121312211231131112311211232221121321132132211331121321231231121113112221121321133112132112312321123113112221121113122113121113123112112322111213211322211312113211";
//    char *b = "11131221131211132221232112111312111213111213211231132132211211131221131211221321123113213221123113112221131112311332211211131221131211132211121312211231131112311211232221121321132132211331121321231231121113112221121321133112132112312321123113112221121113122113121113123112112322111213211322211312113211";
//    printf("%s\n", strcmp(a, b) == 0?"true":"false");
    return 0;
}
