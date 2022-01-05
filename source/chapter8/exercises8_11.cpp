#include <iostream>
#include <iomanip>

using namespace std;

long next_fibonanci();

int main(){
    size_t count{};
    cout << "Enter the number of fibonanci vales to be generated: ";
    cin >> count;
    cout << "The fibonanci series: \n";
    for(size_t i {}; i < count; i++){
        cout << setw(10) << next_fibonanci();
        if(!(i + 1) % 8) cout << endl;
    }
    cout << endl;
}

long next_fibonanci(){
    static long last; 
    static long last_but_one{1L};
    long next {last + last_but_one};
    last_but_one = last;
    last = next;
    //last_but_one = last;
    return last;
}
