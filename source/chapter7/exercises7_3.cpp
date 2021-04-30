#include <iostream>
#include <locale>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

/*1) input the string of character - names
  2) sorting these string using bubble sort 
  3) find the max longest name
  4) output
*/

int main(){
    vector<string>names;
    string input_name;
    char answer{};

    do{
        cout << "Enter a name: " << endl;
        cin >> input_name;
        names.push_back(input_name);

        cout << "Do you want to continue ? " << endl;
        cin >> answer;
    }while(tolower(answer)=='y');

    string temp;
    bool sorted{false};
    
    while(!sorted){
        sorted = true;
        for(size_t i {1}; i<names.size(); i++){

            if(names[i-1] > names[i]){
                temp = names[i];
                names[i] = names[i-1];
                names[i-1] = temp;
                sorted = false;
            }
        }
    }

    size_t max_lenght{};
    for(auto &name: names){
        if(max_lenght < name.length()) max_lenght = name.length();
    }

    cout << "In ascending sequece the names you entered are:\n";
    size_t field_width = max_lenght + 2;
    size_t count {};
    for(auto & name: names){
        cout << setw(field_width) << name;
        if(!(++count % 5)) cout << endl;
    }
    cout << endl;
    return EXIT_SUCCESS;
}
