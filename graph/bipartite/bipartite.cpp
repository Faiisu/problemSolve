#include<iostream>
#include<vector>

using namespace std;
int k;
int n, m;
int discovered[100010];
bool bip = true;

void dfs(int n, int bf, vector<int> adj[]){
    if(discovered[n] != 0){
        if(discovered[n] == discovered[bf]){
            bip = false;
        }
        return;
    }

    if(discovered[bf] == 1) discovered[n] = 2;
    else discovered[n] = 1;
    for(int child: adj[n]){
        if(child == bf) continue;
        dfs(child, n, adj);
    }
}

void bipartite(){
    cin >> n >> m;
    int u, v;
    vector<int> adj[100010];
    for(int i = 0 ; i <= n ; i++) discovered[i] = 0;
    bip = true;
    for(int i = 0 ; i < m ; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(discovered[i]) continue;
        dfs(i, i, adj);
    }
    if(bip) cout << "yes\n";
    else cout << "no\n";
}

int main(){
    cin >> k;
    while(k--){
       bipartite();
    }
    return 0;
}
