#include <iostream>

using namespace std;

template <typename T> T larger(T a, T b); 

int main(){
    cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << endl;
    cout << "Larger of 2.4 and 4.5 is " << larger(2.4, 4.5) << endl;
    
    int a_int {35}, b_int {45};
    cout << "Larger of " << a_int << " and " << b_int << " is " << larger(a_int, b_int) << endl;

    long a_long {9L}, b_long {8L};
    cout << "Larger of " << a_long << " and " << b_long << " is " << larger(a_long,b_long) << endl;
}

template <typename T> T larger(T a, T b) {return a > b ? a : b;}