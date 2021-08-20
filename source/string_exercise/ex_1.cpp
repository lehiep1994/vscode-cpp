#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string reverse_string(string str){
    string tmp_str = str;
    size_t index_pos {};
    for(int x = tmp_str.length()-1; x>=0; x--){
        str[index_pos++] = tmp_str[x];
    }
    return str;
}

int main(){
    string str;
    cout << "Please enter the original string: \n" << endl;
    getline(cin, str);
    cout << "\nReverse string: " << reverse_string(str) << endl;
    return EXIT_SUCCESS;
}