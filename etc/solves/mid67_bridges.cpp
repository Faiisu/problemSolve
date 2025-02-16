#include<iostream>
#include<map>
using namespace std;

map<int,int> test;
int main(){
    test[0] = 1;
    test.erase(0);
    for(auto ite: test){
        cout << ite.first << " ";
    }
    
    return 0;
}