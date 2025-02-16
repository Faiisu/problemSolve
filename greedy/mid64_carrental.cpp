#include<iostream>
#include<cmath>
using namespace std;
int k, n;
int c[110],p[110],w[110], pc[1010];
int maxW = 0;

void readInput(){
    cin >> k >> n;
    for(int i = 0; i<k ; i++){
        cin >> c[i] >> p[i] >> w[i];
    }
    for(int i=0; i<n; i++){
        cin >> pc[i];
        maxW = pc[i]>maxW?pc[i]:maxW;
    }
}

int main(){
    readInput();
    int mincost = 1e9;
    for(int i = 0 ; i < k ; i++){
        if(w[i] < maxW) continue;
        int l = 1;
        int total = 0;
        for(int j = 0 ; j < n ; j++){
            if(total + pc[j] > w[i]){
                l++;
                total = 0;
            }
            total += pc[j];
        }
        int cost = c[i] + (l*p[i]);
        mincost = mincost>cost?cost:mincost;
    }
    cout << mincost;
    return 0;
}