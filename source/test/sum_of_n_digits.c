#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,sum = 0;
    char string[50];
    printf("Enter the array of character overhere: \n");
    gets(string);
    while (string[i++]!='\0'){
        /* code */
        printf("\nASCII value of %c is %d",string[i],string[i]);
    }
    return 0;       
}