#include<iostream>
#include<set>
#include<map>
using namespace std;

int N, weeks;
int parents[210], ranks[210];
set< int > unconnects;
map< int, set< pair<int,int> > > graph;
int mins[210][210];

int find(int n){
    if(parents[n] != n) return find(parents[n]);
    return n;
}

void unite(int A, int B){
    int rA = find(A), rB = find(B);
    if(ranks[rA] > ranks[rB]) parents[rB] = rA;
    else if(ranks[rA] < ranks[rB]) parents[rA] = rB;
    else{
        parents[rA] = rB;
        ranks[rB]++;
    }
}

int mst_kruskal(){
    for(int i = 1; i<= N; i++){
        parents[i] = i;
        ranks[i] = 0;
    }

    int total = 0;
    for(auto ite : graph){
        for( auto pair : ite.second){
            int rA = find(pair.first), rB = find(pair.second);
            if(rA == rB) continue;
            unite(rA,rB);
            total += ite.first;
        }
    }
    return total;
}


int main(){
    cin >> N >> weeks;
    int total = 0;
    for(int i = 1; i<= N; i++){
        unconnects.insert(i);
        parents[i] = i;
        ranks[i] = 0;
    }

    while(weeks--){
        int A, B, W;
        cin >>A>>B>>W;
        unconnects.erase(A);
        unconnects.erase(B);   
        graph[W].insert(make_pair(A,B));
        if(!unconnects.empty()){
            cout << "-1\n";
            continue;
        }
        total = mst_kruskal();
        cout << total<< "\n";
    }

    return 0;
}