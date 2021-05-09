#include <stdio.h>
#include <ctype.h>

int main(){
    char alphabet;
    printf("Enter an alphabet: ");
    putchar('\n');

    alphabet = getchar();
    printf("\n\nreverse case of %c is : ",alphabet);
    if(islower(alphabet)) putchar(toupper(alphabet));
    else printf("%c",toupper(alphabet));
    
    printf("\n\nHappy coding.");
    return 0;   
}