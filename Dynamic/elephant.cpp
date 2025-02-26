/*  greatest sum in which the sequence of each
    number is at least 2 order apart */

#include<iostream>
using namespace std;

int maxs[100010];
int main(){
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        int inp;
        cin >> inp;
        if(i < 3) continue;

        int max = inp + maxs[i-3];
        for(int j = i-3 ; j < i ; j++){
            max = max<maxs[j]?maxs[j]:max;
        }
        maxs[i] = max;
    }
    cout << maxs[n];
    return 0;
}