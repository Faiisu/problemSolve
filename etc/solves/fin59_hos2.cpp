#include<iostream>
#include<vector>
#include<list>
using namespace std;
int n, m ,h;
vector<int> adj[1010];
bool discovered[1010];

void h_traversal(vector<int> layer, int Nlayer){
    if(Nlayer == 0) return;
    list<int> next_layer;
    for(int N : layer){
        if(!discovered[N]){
            discovered[N] = true;
            next_layer.push_back(N);
        }
    }
    for(int N: next_layer) h_traversal(adj[N], Nlayer-1);
}

int safe_counting(){
    int max_cnt = 0;
    for(int j = 1 ; j <= n ; j++) discovered[j] = false;
    for(int i = 1 ; i <= n ; i++){
        int cnt = 0;
        discovered[i] = true;
        h_traversal(adj[i], h);
        for(int j = 1; j <= n ; j++){
            if(discovered[j]){
                cnt++;
                discovered[j] = false;
            }
        }
        max_cnt = max_cnt<cnt?cnt:max_cnt;
    }
    return max_cnt;
}

int main(){
    cin >> n >> m >> h;
    while(m--){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    cout << safe_counting();
    return 0;
}