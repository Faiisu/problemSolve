#include<iostream>
#include<string>
#include<list>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    while(getline(cin, n)){
        if(n.empty()) break;
        list<char> output;
        auto ite = output.begin();
        for(char c : n){
            if(c == '[') ite = output.begin();
            else if(c == ']') ite = output.end();
            else output.insert(ite, c);
        }
        for(auto c = output.begin() ; c != output.end(); c++) cout << *c;
        cout << "\n";
    }
    return 0;
}