#include<iostream>
using namespace std;

int main(){
    int number[310];
    for(int i = 0; i < 310; i++) number[i] = 0;
    int n,inp,pos;
    int _max = -1;
    cin >> n;
    while(n--){
        cin >> inp;
        number[inp] += 1;
        if(number[inp] > _max){
            _max = number[inp];
            pos =inp;
        }
    }
    cout << number[pos] << endl;
    return 0;
}