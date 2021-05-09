#include <stdio.h>
#include <string.h>

//This program to reverse string of character inorderly
//using two way - 1st swap each character and 2nd new array

/*int main(){
    char rev[1000], str[1000];
    int i,j,cnt = 0;
    printf("\nEnter the string of character for reversing: \n");
    scanf("%s",str);

    printf("\nString before reverse: %s",str);
    while (str[cnt]!='\0'){
        cnt++;
    }
    j = cnt - 1;

    for(i = 0; i<cnt; i++){
        rev[i] = str[j--];
    }
    printf("\nString after reverse: %s",rev);

    return 0;
}*/

void reverseSTR(char *str){
    int n = strlen(str);
    for(int i = 0; i < n/2; i++){
        char ch = *(str + i);
        *(str + i) = *(str + (n - i - 1));
        *(str + (n - i - 1)) = ch;
    }
}

int main(){
    char str[1000];
    printf("\nEnter the string of character before reversing: ");
    gets(str);
    reverseSTR(str);
    printf("\nThe string after reversing is: ");
    puts(str);

    return 0;
}

