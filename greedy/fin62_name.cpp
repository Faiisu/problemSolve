#include<iostream>
#include<string>

using namespace std;

int main(){
    string s, input;
    int pos = 0, cnt = 0;
    cin >> s;
    cin >> input;

    int len = s.length();

    for(char c : input){
        if(c == s[pos]){
            if(pos == len-1) cnt++;
            pos++;
            pos %= len;
        }
    }
    cout << cnt;
    return 0;
}