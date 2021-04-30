//This is new version of counting VOWELs AND CONSONANTs in a string
//Similarly with exercises5_11.cpp

#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main(){
    //Store the input
    string text;
    cout << "Enter a line of text: \n" << endl;
    //getline() function is used for reading 
    //input sentence from keyboard including spaces
    //istream &getline(istream &is, string &str, char delim);
    //And there are two ways for representing of getline()
    //1st, if we use char y[bla_bla] => cin.getline(y,bla_bla);
    //2nd, if we just declare the string text (an array of char)
    //getline(inputstream,str).
    //The most important thing of this getline() is that it will terminate 
    //as soon as the newline signal is read <=> when user press ENTER BUTTON.
    getline(cin,text);

    //For this version of getline(1,2,3) with the third parameter is "#"
    //the string entered by user will not be terminated by newline signal
    //but it will be read all characters until the delimiter is acknowledged.
    getline(cin,text,'#');

    int vowel = 0, consonant = 0;
    //of course, the forloop - range-based can be used rather than the traditional one.
    
    for(size_t i {}; i < text.length(); i++){
        if(isalpha(text[i])){
            switch(tolower(text[i])){
                case 'a':case 'e':case 'i':case 'o':case 'u':
                    ++vowel;
                break;

                default:
                    ++consonant;
                    break;
            }
        }
    }
    cout << "YOUR INPUT CONTAINED: " << vowel << " vowels and "
        << consonant << " consonants." << endl;
    return EXIT_SUCCESS;
}
