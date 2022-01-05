/*resursive program to linearly search an element in a given array*/
#include <iostream>
#define MAX 100
//const int MAX 100;

using namespace std;

void InArr(int *a, int k){
    for(size_t i{}; i < k; i++){
        cout << "\nEnter element a["<< i <<"] = ";
        cin >> a[i];
    }
}

void OutArr(int *a, int k){
    for(size_t i{}; i < k; i++)  cout << "\nElement a["<< i <<"] = " << a[i] << endl;   
}

int EleSrch(int *a, int size, int x){
    int rec;
    size --;
    if(size >= 0){
        if(*(a + size) == x) return size;
        else rec = EleSrch(a,size,x);
    }else return -1;
    return rec;
}

int main(){
    int a[MAX],k,f,idx,size,x;
    cout << "Enter number of element of an array: " << endl;
    do{
        cin >> k;
        if(k <= 0 || k > MAX) cout << "\nPlease enter again the number of element for an array correcly: " << endl;
    }while(k <= 0 || k > MAX);
    cout << "-------INPUT-------" << endl;
    InArr(a,k);
    cout << "\n-------OUTPUT-------" << endl;
    OutArr(a,k);
    cout << "\n-------SEARCHING-------" << endl;
    idx = EleSrch(a,size,x);
    if(idx != -1) cout << "Element " << x << "is found at index " << idx << endl;
    else cout << "Element " << x << "is not in the array" << endl;
    EXIT_SUCCESS;
}