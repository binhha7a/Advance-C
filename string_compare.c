#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
uint8_t StringEqual(char chuoi1[], char chuoi2[]){
    int i = 0;
    while (chuoi1[i] != 0 || chuoi2[i] != 0) {
        if (chuoi1[i] == chuoi2[i]) i++;
        else return 0;
    }
    return 1;
}
char chuoi1[] = "abc";
char chuoi2[] = "abc";
int main(int argc, char const *argv[])
{
    printf("%d", StringEqual(chuoi1,chuoi2));
}
