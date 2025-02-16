#include<iostream>
#include<map>
using namespace std;

int n, q;
int R,C,A,B;
char maze[21][21];
bool discovered[21][21], found;
void input_maze(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> maze[i][j];
        }
    }
}

void reset_track(){
    found = false;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            discovered[i][j] = false;
        }
    }
}

void pathfinder(int r, int c, bool key){
    if(r < 1 || r > n || c < 1 || c > n) return;
    if(maze[r][c] == '#' || discovered[r][c] == true) return;
    if(maze[r][c] == 'O'){
        if(!key) return;
        else key = false;
    }
    
    discovered[r][c] = true;
    if(r == A && c == B){
        found = true;
        return;
    }

    pathfinder(r, c+1, key);
    pathfinder(r+1, c, key);
    pathfinder(r, c-1, key);
    pathfinder(r-1, c, key);
}

int main(){
    cin >> n >> q;
    input_maze();
    while(q--){
        cin >> R >> C >> A >> B;
        reset_track();
        pathfinder(R,C,1);
        if(found) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}