#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

char * readFile(char *pcFileName){
    FILE *fp = fopen(pcFileName, "r");
    if(!fp)
        return NULL;
    fseek(fp, 0L, SEEK_END);
    int iSize = ftell(fp);
    char *pcFileBuf = (char *)malloc(sizeof(char)*iSize);
    fseek(fp, 0L, SEEK_SET);
    fread(pcFileBuf, iSize, 1, fp);
    fclose(fp);
    printf("%s\n", pcFileBuf);
    return pcFileBuf;
}

int main(){
    string buf = readFile("test1.json");
    cout << buf << endl;
    return 0;
}
