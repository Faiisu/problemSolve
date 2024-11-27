#include<iostream>
using namespace std;
int n, k, t;

int nextpos(int pos){
    int nextpos = pos+k;
    if(nextpos > n) nextpos -= n;
    return nextpos;
}

int sending(int pos, int cnt){
    if(pos == t) return cnt+1;
    if(pos == 1) return cnt;
    return sending(nextpos(pos), cnt+1);
}


int main(){
    cin >> n >> k >> t;
    cout << sending(nextpos(1), 0)+1;
    return 0;
}