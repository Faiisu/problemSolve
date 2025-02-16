#include<iostream>
#include<list>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    char cmd;
    int x, i;
    const int MAX_N = 100010;
    list<int> trains[MAX_N];

    cin >> m;
    for(int ii = 0 ; ii < m ; ii++){
        cin >> cmd >> x >> i;
        if(cmd == 'N') trains[i].push_back(x);
        else trains[i].splice(trains[i].end(), trains[x]);
    }
    for(int i = 1 ; i <= m ; i++){
        for(auto j = trains[i].begin(); j != trains[i].end(); j++){
            cout << *j << "\n";
        }
    }
    return 0;
}