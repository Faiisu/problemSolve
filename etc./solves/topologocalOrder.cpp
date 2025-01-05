#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, m;
bool loop = false;
vector<int> adj[100010];
int discovered[100010];

bool isTopological(int n) {
    vector<int> inDegree(n, 0);
    queue<int> q;
    int processedNodes = 0;

    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            ++inDegree[v];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ++processedNodes;

        for (int v : adj[u]) {
            --inDegree[v];
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return processedNodes == n;
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1 ; i <= n; i++){
        if(!isTopological(i)) loop = true;
    }
    if(loop) cout << "no";
    else isTopological(1);
    return 0;
}