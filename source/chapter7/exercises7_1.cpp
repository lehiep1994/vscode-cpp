#include <iostream>
#include <string>

using namespace std;

int main(){
    string first;
    string second;

    cout << "Enter your first name: " << endl;
    cin >> first;

    cout << "Enter your second name: " << endl;
    cin >> second;

    string sentence {"Your full name is "};
    sentence += first + " " + second + ".";
    cout << sentence << endl;

    cout << "The string contains " << sentence.length() << " character." << endl;
    return EXIT_SUCCESS;
}
