#include<iostream>
#include<vector>
using namespace std;

vector<int> a;

int f(int n){
    if(n == 0) return 0;
    cout << f(n-1);
}

int main(){
    f(50);
}
