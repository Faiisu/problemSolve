#include<iostream>
#include<vector>
#include<list>

using namespace std;

int n, m, h;
vector<int> adj[1010];
bool discovered[1010];
//n village, m road, h hour

void init(){
    cin >> n >> m >> h;
    for(int i = 1; i <= m ; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int safety_count(int node_number, int h){
    // cout << node_number << endl;
    if(h == 0) return 1;
    list<int> next_layer;
    int cnt = 1;
    for(auto v: adj[node_number]){
        if(discovered[v] == true) continue;
        discovered[v] = true;
        next_layer.push_back(v);
    }
    for(auto v: next_layer){
        cnt += safety_count(v,h-1);
    }
    return cnt;
}

int node_traversal(){
    int max_cnt = 0, cnt;
    for(int i = 1; i <= n; i++){
        for(int i = 1 ; i <= n; i++) discovered[i] = false;
        discovered[i] = true;
        // cout << "===hospital at : ===" << i << "\n";
        cnt = safety_count(i, h);
        max_cnt = cnt >= max_cnt? cnt:max_cnt;
    }
    return max_cnt;
}

int main(){
    init();
    cout << node_traversal();
    return 0;
}