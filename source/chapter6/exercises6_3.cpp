#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    size_t n {};
    cout << "Enter the number of vector elements: " << endl;
    cin >> n;
    auto value = new vector<double>(n);
    for(unsigned long long i {}; i < n; i++){
        (*value)[static_cast<size_t>(i)] = 1.0/((i+1)*(i+1));
    }
    double sum {};
    for(auto values:*(value)) sum += values;

    cout << "The result is " << sqrt(6.0*sum) << endl;
    return EXIT_SUCCESS;
}
