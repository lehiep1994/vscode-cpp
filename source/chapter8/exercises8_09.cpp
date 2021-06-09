#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void show_data(const int*data, size_t cnt = 1, const string &title = "Data values", 
                size_t width = 10,size_t perline = 5);
int main(){
    int samples[] {1,2,3,4,5,6,7,8,9,10};
    int data_items{-99};
    show_data(&data_items);

    data_items = 13;
    show_data(&data_items,1,"Unlucky for some");
    
    show_data(samples,sizeof(samples)/sizeof(samples[0]));
    //show_data(samples,sizeof(samples)/sizeof(samples[0]),"Samples");
    //show_data(samples,sizeof(samples)/sizeof(samples[0]),"Samples",6);
    show_data(samples,sizeof(samples)/sizeof(samples[0]),"Samples",8,4);
}

void show_data(const int* data, size_t cnt, const string &title,
                size_t width, size_t perline){
    cout << title << endl;
    for(size_t i{}; i < cnt; ++i){
        cout << setw(width) << data[i];
        if((i+1) % perline == 0) cout << endl;
    }
    cout << endl;
}