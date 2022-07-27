#include <stdio.h>
int test_atoi(char *string){
    int temp = 0;
    int i = 0;
    while ((int)*(string+i) >= 48 && (int)*(string+i) <=57){
        temp = temp * 10 + (int)*(string+i) - 48;
        i++;
    }
    return temp;
}


int main(int argc, char const *argv[])
{
    char string[] = "9999";
    int x = test_atoi(string);
    printf("Converted Number = %d",x);
    return 0;
}
