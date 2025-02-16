#include<iostream>
#include<map>
#include<list>
using namespace std;

map<int,int> incache;
list<int> cache;
int main(){
    int n, m, input, misscnt = 0;
    cin >> n >> m;
    while(m--){
        cin >> input;
        if(incache[input] == 1) continue;
        incache[input] = 1;
        int cachesize = cache.size();
        misscnt++;
        if(cachesize >= n){
            incache[cache.front()] = 0;
            cache.pop_front();
        }
        cache.push_back(input);
    }
    cout << misscnt;
    return 0;
}