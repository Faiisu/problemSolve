#include<iostream>
using namespace std;

int main(){
    int l = 0, n = 0, conner = 0, _sum = 0;
    int _round = 0; 
    cin >> l >> n;
    for(int i = 1 ; i <= l ; i++) conner+=i;
    while(_sum < n){
        _sum += (l*_round*l) + conner;
        _round+=1;
    }
    cout << _round;
    return 0;
}