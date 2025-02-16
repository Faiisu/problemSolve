#include<iostream>
#include<string>
using namespace std;

int main(){
    string input;
    char c;
    int x = 0, y = 0;
    cin >> input;
    for(int i = 0; i < input.length() ; i++){
        c = input[i];
        if(c == 'N') y+=1;
        if(c == 'E') x+=1;
        if(c == 'S') y-=1;
        if(c=='W') x-=1;
        if(c == 'Z'){
            x=0;
            y=0;
        } 
    }
    cout << x << " " << y;

    return 0;
} 