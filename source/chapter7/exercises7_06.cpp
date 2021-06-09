#include <iostream>
#include <string>

using namespace std;

int main(){
    string text;
    cout << "Enter a string terminated by *:\n";
    getline(cin,text,'*');

    string word;
    cout << "Enter the word to be replaced: ";
    cin >> word;

    string replacement;
    cout << "Enter the string to be substituted for " << word << ": ";
    cin >> replacement;

    if(word == replacement){
        cout << "The word and its replacement are the same.\n" << "Operation aborted." << endl; 
        return 1;
    }
    size_t start {text.find(word)};
    while(start!=string::npos){
        text.replace(start,word.length(),replacement);
        start = text.find(word,start + replacement.length());
    }
    cout << "\nThe string you entered is now:\n" << text << endl;
    return EXIT_FAILURE;
}
