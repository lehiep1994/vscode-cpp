#include <iostream>
#include <array>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    //the number of rows
    const size_t n_arrays{4};
    //the number of collumns
    const size_t dimension{8};

    //Initializing an arrays of pointers dynamically by using new operator
    auto arrays = new int *[n_arrays];

    for(size_t i {}; i < n_arrays; i++){
        //arrays[i] = new int [dimension];
        *(arrays+i) = new int [dimension];}
    
    size_t value {};
    for(size_t j {}; j < dimension; j++){
        value = j + 2;
        //the value of each consecutive lines (rows) will increase proportionally by power 
        //of two of previous values.
        for(size_t i {}; i < n_arrays; i++){
            *(*(arrays + i) + j) = pow(value, i + 1);
        }
    }

    cout << "The value in the arrays are:\n";
    //Printing the number of row and collumn of matrix or array of arrays.
    for(size_t i {}; i < n_arrays; i++){
        for(size_t j {}; j < dimension; j++){
            cout << setw(8) << arrays[i][j]; 
        }
        cout << endl;
    }

    //Free memory 
    for(size_t i {}; i < n_arrays; i++) delete[]arrays[i];
    delete[]arrays;
    return EXIT_SUCCESS;
}