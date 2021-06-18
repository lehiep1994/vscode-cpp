#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>

using namespace std;

/*void find_words(vector<string>& words, string& str, const string& separators);*/
void list_words(const vector<string>& words);

int main(){
    string text;
    cout << "enter some text terminated by*: \n";
    getline(cin, text,'*');

    const string separators{" ,;:.\"!?'\n"};
    /*vector<string> words;
    
    find_words(words,text,separators);
    list_words(words);*/

    auto pWords = find_words(text,separators);
    list_words(pWords);
    
    return EXIT_SUCCESS;
}

/*void find_words(vector<string>& words, string& str, const string& separators){
    size_t start{str.find_first_not_of(separators)};
    size_t end {};
    while(start != string::npos){
        end = str.find_first_of(separators, start + 1);
        if(end == string::npos)
            end = str.length();
            words.push_back(str.substr(start,end - start));
            start = str.find_first_not_of(separators,end + 1);
    }
}*/

/*void list_words(const vector<string>& words){
    cout << "your string contains the following " << words.size() << " words:\n";
    size_t count{};
    for(const auto& word: words)
        cout << setw(15) << word;
        if(!(++count%5)) cout << endl;
    cout << endl;
}*/

shared_ptr<vector<string>> find_words(const string& str, const string& separators){
    auto pWords = make_shared<vector<string>>();
    
    size_t start {str.find_first_not_of(separators)};
    size_t end {};
    
    while(start != string::npos){
        end = str.find_first_of(separators, start + 1); 
        if(end == string::npos) end = str.length();
        pWords->push_back(str.substr(start,end - start));
        start = str.find_first_not_of(separators,end + 1);
    }
    return pWords;
}

void list_words(const shared_ptr<vector<string>> pWords){
    cout << "your string contains the following " << pWords->size() << " words:\n";
    size_t count {};
    for(const auto&word: *pWords){
        cout << setw(15) << word;
        if(!(++count % 5)) cout << endl;
    }
    cout << endl;
}