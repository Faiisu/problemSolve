#include<iostream>
#include<map>
#include<vector>
#include<set>

using namespace std;

int n, m, k, s;
int ranks[100100], prices[30];
map<int, vector<int> > adj;

int priceSum[100100];
int tb[100100];

void traversal(int node, int ht, int step){
    int ticketType = ranks[node];
    if(ht < ticketType) ht = ticketType;
    tb[node] = ht;
    for(auto nextNode : adj[node]){
        if(step + 1 > s) continue;
        if(tb[nextNode] != 0 && ht > tb[nextNode]) continue;

        traversal(nextNode, ht, step+1);
    }
}

void init(){
    cin >> n >> m >> k >> s;
    for(int i = 1; i <= n ; i++){
        cin >> ranks[i];
        tb[i] = 0;
    }
    for(int i = 1; i<= k ; i++ ) cin >> prices[i];
    for(int i = 1; i<=m ;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main(){
    init();
    traversal(1,0,1);
    // for(auto ite : adj){
    //     cout << ite.first << " " << tb[ite.first] << "\n";
    // }
    if(tb[n] == 0){
        cout << -1;
        return 0;
    }

    int lowerRank = tb[n], lowerPrice = prices[lowerRank];
    // cout << lowerRank;
    for(int i = lowerRank ; i <= k ; i++){
        if(prices[i] < lowerPrice) lowerPrice = prices[i];
    }
    cout << lowerPrice;
    return 0;
}
