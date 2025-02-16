#include<iostream>
using namespace std;

//O(logN)
int main(){
    int n, floor = 1;
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }

    while(floor*floor < n) floor++;
    int wall_break = (floor-2)*2 + 1;
    if(n%2 == 0) wall_break += floor%2==0?1:0;
    else wall_break += floor%2==0?0:1;
    cout << wall_break;
    return 0;
}