#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int h1,h2,b1,b2;
    int hb1, hb2, diff;
    int x, y, sum;

    cin >> h1 >> h2 >> b1 >> b2;
    cin >> x >> y;

    if(h1 > b1){
        hb1 = b1;
        h1 -= b1;
        b1 = 0;
    }
    else{
        hb1 = h1;
        b1 -= h1;
        h1 = 0;
    }
    
    if(h2 > b2){
        hb2 = b2;
        h2 -= b2;
        b2 = 0;
    }
    else{
        hb2 = h2;
        b2 -= h2;
        h2 = 0;
    }
    diff = min(h1,b2) + min(h2,b1);
    if(h1 < b2){
        b2 -= h1;
        h1 = 0;
    }
    else{
        h1 -= b2;
        b2 = 0;
    }
    if(h2 < b1){
        b1 -= h2;
        h2 = 0;
    }
    else{
        h2 -= b1;
        b1 = 0;
    }


    int overflow = 0;
    cout << h1 << " " << h2 << " " << b1 << " " << b2 << endl;
    cout << hb1 << " " << hb2 << " " << diff;
    sum = hb1 + hb2 + diff;
    int bf = 0;
    while(sum < )

    return 0;
}