#include<iostream>
#include<map>
using namespace std;

int n, m, cnt;
bool tree, material;
char maze[35][35];
bool discovered[35][35];

void input_maze(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> maze[i][j];
        }
    }
}
void reset_track(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m; j++){
            discovered[i][j] = false;
        }
    }
}

void pathfinder(int r, int c){
    if(r < 1 || r > n || c < 1 || c > m) return;
    if(maze[r][c] == '#' || discovered[r][c] == true) return;
    
    // cout << r << " " << c << endl;
    char symbol = maze[r][c];
    discovered[r][c] = true;
    if(symbol == '$') material = true;
    if(symbol == '*') tree = true;
    cnt++;
    pathfinder(r, c+1);
    pathfinder(r+1, c);
    pathfinder(r, c-1);
    pathfinder(r-1, c);
}

int main(){
    int good = 0, med = 0;
    cin >> n >> m;
    input_maze();
    reset_track();
    for(int r = 1; r<= n ; r++){
        for(int c = 1; c<=m;c++){
            if(discovered[r][c]) continue;
            
            tree = false;
            material = false;
            cnt = 0;
            pathfinder(r,c);
            if(tree==true && material==true) good += cnt;
            else if(tree ==true || material==true) med += cnt;
            // cout << cnt << " ";
        }
    }
    cout << good <<" " << med << endl;
    return 0;
}