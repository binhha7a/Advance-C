#include <stdio.h>
//#include <stdint.h>
//#include <stdlib.h>
char check_itoa(int mod){
    char symbol[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    return symbol[mod];
}
void itoa(int number, char *buffer , int coding_system){
    int p,i,mod;
    p = number;
    i = 0;
    while (p > 0){
        mod = p % coding_system;
        p = p / coding_system;
        *(buffer+i) = check_itoa(mod);
        i++;
    }   
    *(buffer+i) = '\0';
}
int main(int argc, char const *argv[])
{
    int n, coding_system;
    char buffer[50];
    coding_system = 0;
    while (coding_system != 2 && coding_system != 10 && coding_system != 16){
    printf("Enter coding system(2,10,16) = ");
    scanf("%d",&coding_system);
    }
    printf("Enter your number = ");
    scanf("%d",&n);
    itoa(n,buffer,coding_system);
    printf("Convert = %s",buffer);
    return 0;
}
