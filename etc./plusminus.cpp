#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, intput, sum = 0;
    char charput = '+';
    bool plus = true;
    cin >> n;
    for(int i = 1; i < n*2 ; i++){
        if(i%2==0) cin >> charput;
        else{
            cin >> intput;
            charput == '+'? sum+=intput: sum-=intput;
        }
    }
    cout << sum;
    return 0;
}