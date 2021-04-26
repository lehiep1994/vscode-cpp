#include <iostream>
#include <array>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    const size_t n_arrays{3};
    const size_t dimension{6};

    //Initialize an arrays of pointers dynamically using new operator
    auto arrays = new int *[n_arrays];

    for(size_t i {}; i<n_arrays; i++){
        *(arrays+i) = new int [dimension];}
    
    size_t value {};
    for(size_t j {}; j < dimension; j++){
        value = i + j;
        for
    }

    return EXIT_SUCCESS;
}