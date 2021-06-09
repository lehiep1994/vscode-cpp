#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long sum(int *a, int n){
    long long int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    return sum;
}

int main(){
    int a[20],i,n,sum;
    printf("Enter the size of array:\n");scanf("%d",&n);
    printf("Enter elements in array:\n");
    for(i = 0; i < n; i++){}
}