#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> _list;
    int m;
    long long input;
    char cmd;
    cin >> m;
    while(m--){
        cin >> cmd >> input;
        if(cmd == 'I') _list.push_front(input);
        else if(cmd == 'A') _list.push_back(input);
        else{
            if(input < 0 || input > _list.size()) continue;
            auto pos = _list.begin();
            advance(pos, input-1);
            _list.erase(pos);
        }
    }
    for(auto i = _list.begin() ; i != _list.end() ; i++){
        cout << *i << endl;
    }
    return 0;
}