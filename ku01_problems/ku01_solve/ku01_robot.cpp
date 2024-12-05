#include<iostream>
using namespace std;

//not pass all task
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int h1,h2,b1,b2;
    int hb1, hb2, diff=0;
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
    diff += min(h1,b2) + min(h2,b1);
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
    printf("%d %d\n",hb1,hb2);
    
    int ans = 0;
    while(hb1 + hb2 > x && hb1 > 0 && hb2 > 0){
        hb1--;
        hb2--;
        diff+=2;
        if(diff > y){
            if(h1 > 0){
                hb2--;
                h1--;
                h2++;
            }
            else if(b1 > 0){
                hb2--;
                b2++;
                b1--;
            }
            else if(h2 > 0){
                hb1--;
                h2--;
                h1++;
            }
            else if(b2 > 0){
                hb1--;
                b2--;
                b1++;
            }
            diff+=1;
            break;
        }
        sum = hb1 + hb2 + diff;
        // cout << "sum: " << sum << 10endl;
    }
    sum = min(hb1+hb2,x)+ min(diff + min(h1,b2) + min(h2,b1),y);
    // cout << hb1 << " " << hb2 << " " << diff << endl;
    cout << sum;
    return 0;
}