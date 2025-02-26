#include<iostream>
#include<map>
using namespace std;
int n;

map<int, pair<int, int> > times;
int main(){
    cin >> n;
    for(int i = 0; i < n ; i++){
        int x, y, w;
        cin >> x >> y >> w;
        if(w > times[y].second){
            times[y] = make_pair(x,w);
        }
    }
    for()
    return 0;
}