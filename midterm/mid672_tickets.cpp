#include<iostream>
#include<list>
#include<vector>

using namespace std;

int n, m, k, s;
int ranks[50100], prices[30];
vector<int> adj[50100];
int tb[50100];

void bfs(){
    list<pair<int, pair<int, int > > > q;
    
    q.push_back(make_pair(1 ,make_pair(0, 1)));

    int node, ht, step, ticketType;
    while(!q.empty()){
        auto ite = *q.begin();
        node = ite.first, ht = ite.second.first, step = ite.second.second;
        q.pop_front();

        ticketType = ranks[node];
        if(ht < ticketType) ht = ticketType;
        if(tb[node] > ht || tb[node] == 0) tb[node] = ht;
        for(int nextNode : adj[node]){
            if(step >= s) continue;
            if(tb[nextNode] != 0 && ht >= tb[nextNode]){
                tb[nextNode] = ht;
                continue;
            }
            q.push_back(make_pair(nextNode ,make_pair(ht, step+1)));
        }
    }
}

void init(){
    cin >> n >> m >> k >> s;
    int a, b;
    for(int i = 1; i <= n ; i++){
        cin >> ranks[i];
        tb[i] = 0;
    }
    for(int i = 1; i<= k ; i++ ) cin >> prices[i];
    for(int i = 1; i<=m ;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main(){
    init();
    bfs();

    if(tb[n] == 0){
        cout << -1;
        return 0;
    }
    
    int lowerRank = tb[n], lowerPrice = prices[lowerRank];
    for(int i = lowerRank ; i <= k ; i++){
        if(prices[i] < lowerPrice) lowerPrice = prices[i];
    }
    cout << lowerPrice;
    return 0;
}