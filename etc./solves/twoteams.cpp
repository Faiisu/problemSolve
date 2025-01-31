#include<iostream>
#include<list>
using namespace std;

int n, m;
list<int> adj[100100], already;

int bipartite_test(int n){
    
    for(auto next_layer : adj[n]){

    }
    return 0; 
}

int main(){
    cin >> n >> m;
    while(n--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        already.push_back(a);
        already.push_back(b);


    }

    return 0;
}