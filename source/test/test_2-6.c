#include <stdio.h>

int setbits(int x, int p, int n, int y){
    x = x & (~(~(~0 << n) << p));
    // x = x & (~(~(1<<n)) << p))
    y = (y & (~(~0 << n)) << p);
    // y = y & (~(1 << n) << p);
    return x | y; 
}

int main(){
    int a = setbits(255,0,4,0);printf("%d\n",a);
    int b = setbits(1,1,3,4);printf("%d\n",b);
    int c = setbits(218,2,4,9);printf("%d\n",c);
}
