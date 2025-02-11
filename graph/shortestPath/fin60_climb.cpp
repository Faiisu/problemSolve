#include<iostream>
#include<vector>
#include<climits>
#include<list>

using namespace std;
int h, w;
char table[30][30];
int cost[30][30];

void getinput(){
    cin >> h >> w;
    for(int i = 1; i <=h ; i++){
        for(int j = 1 ; j <= w ;j++){
            cin >> table[i][j];
            cost[i][j] = INT_MAX;
        }
    }
}

int mv[4][2] = {(-1,0),(0,-1),(0,1),(1,0)};
list<pair<int,int> > q;
void moving(int r, int c, int t_cost){
    q.push_back(make_pair(r,c));

    if(r < 1 || c < 1 || r > h || c > w) return;
    if(t_cost >= cost[r][c]) return;
    if(table[r][c] == 'X') return;
    cost[r][c] = t_cost;

    moving(r+1, c , t_cost);
    moving(r, c+1 , t_cost+1);
    moving(r, c-1 , t_cost+1);
    moving(r-1, c , t_cost+5);
}

int main(){
    getinput();
    moving(h,1,0);

    if(cost[1][w] != INT_MAX) cout << cost[1][w];
    else cout << -1;

    return 0;
}