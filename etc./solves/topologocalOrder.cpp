#include<iostream>
#include<vector>
#include<list>
using namespace std;

int n, m;
vector<int> adj[100100];
list<int> queue, topo;
int indegree[100100];

int main(){

    cin >> n >> m;

    for(int i = 0 ; i <= n; i++){
        indegree[i] = 0;
    }

    for(int i = 0 ; i < m ; i ++){
        int x, y;
        cin >> x >>y;
        adj[x].push_back(y);
        indegree[y] += 1;
    }

    for(int i = 1 ; i <= n; i++){
        if(indegree[i] == 0){
            queue.push_back(i);
        }     
    }
    for(int n : queue){
        for(int N : adj[n]){
           indegree[N]--;
           if(indegree[N] == 0) queue.push_back(N); 
        }
    }
    int qs = queue.size();
    if(qs == n){
        for(int n : queue) cout << n << "\n";
    }
    else cout << "no";
    return 0;
}