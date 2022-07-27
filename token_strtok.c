#include <stdio.h>
//#include <string.h>
////#include <stdlib.h>

int check(char c,const char string[]){
    int i=0;
    //if (c = '\0') return 1;
    while ((int)*(string+i) != 0){
        if ((int)c == (int)*(string+i)) return 1;
        i++;
    }
    return 0;
}

char *strtok_test(char *string,char *reference){
    static char *temp;
    if (string != NULL) temp = string;
    //printf("temp = %s\n",temp);
    int last = 0;
    while (check(*(temp+last),reference) == 0){
        if (*(temp+last) == '\0') break;
        last ++;
    };
    if (last == 0) 
    {
        temp = temp + 1;
        return NULL;
    }
    char *result = temp;
    temp[last] = '\0';
    temp = temp + last + 1;
    return result;
}
int main() {
    char string[] = "Hello! We-are-learning*about strtok";
    char *token = strtok_test(string," -*");

    while (token != NULL){
        printf("token = %s\n",token);
        token = strtok_test(NULL," -*");
    };
  return 0;
}