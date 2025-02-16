#include<iostream>
#include<list>
#include<string>
using namespace std;

int main(){
    int m, input;
    int holding;
    string cmd;
    list<int> ll;

    cin >> m;
    while(m--){
        cin >> cmd;
        if(cmd == "li" || cmd == "ri") cin >> input;

        if(cmd == "li") ll.push_front(input);
        else if(cmd == "ri") ll.push_back(input);
        else if(cmd == "lr"){
            ll.push_back(ll.front());
            ll.pop_front();
        }
        else{
            ll.push_front(ll.back());
            ll.pop_back();
        }
        // cout << *ll.begin();
    }
    for(auto i = ll.begin(); i != ll.end() ; i++){
        cout << *i << endl;
    }
    return 0;
}