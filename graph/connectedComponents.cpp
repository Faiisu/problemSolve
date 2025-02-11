#include<iostream>
#include<vector>
#include<list>
using namespace std;

int n, m;
const int MAX_N = 100010;
vector<vector<int> > adj(MAX_N);
bool discovered[MAX_N];

void bfs(int root) {
    list<int> q;
    q.push_back(root);
    discovered[root] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for(auto v : adj[u]){
            if(discovered[v] == true) continue;
            discovered[v] = true;
            q.push_back(v);
        }
    }
}

int main(){
    cin >> n >> m;

    int a,b, cnt=0;
    while(m--){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) discovered[i] = false;
    for(int i = 1; i <= n; i++){
        if(discovered[i] == true) continue;
        cnt++;
        bfs(i);
    }
    cout << cnt;
    return 0;
}