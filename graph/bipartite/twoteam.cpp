#include<iostream>
#include<map>
#include<vector>
using namespace std;

int n, m;
map<int, vector<int> > adj;
int tb[100100], color[100100];

bool painting(int node, int cl){
    for(auto node : adj){
        // cout << node.first << "| ";
        color[node.first] = cl;
        for(auto next : node.second){
            color[next] = (-1)*cl;
        }
        for(auto next : node.second){
            painting(next, cl);
        }
    }

}

bool tryBipartite(int node){
    for(int i = 0 ; i <= n ; i++){
        tb[i] = 0;
        color[i] = 0;
    }

    return true;
}

int main(){
    cin >> n >> m;
    for(int day = 1 ; day <= m ; day++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        bool canBipartite = tryBipartite(a);
    }

    // for(auto node : adj){
    //     cout << node.first << "| ";
    //     for(auto next : node.second){
    //         cout << next <<" ";
    //     }
    //     cout << "\n";
    // }

    return 0;
}