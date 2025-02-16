#include<iostream>

using namespace std;
int n, m;
char map[40][40];
int trackback[40][40];
bool canPass = false;

void init(){
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> map[i][j];
            trackback[i][j] = 0;
        }
    }
}

bool spaceCheck(int rol, int col){
    int size = 2;
    for(int i = 0 ; i < size; i++){
        for(int j = 0; j < size ; j++){
            if(map[rol+i][col+j] == '#') return false;
        }
    }
    return true;
}

void traversal(int rol, int col){
    if(col >= m-1 || col < 0) return;
    if(rol >= n-1 || rol < 0) return;
    if(trackback[rol][col] == 1) return;
    bool freeSpace = spaceCheck(rol,col);
    if(!freeSpace) return;

    if(rol == n-2) canPass = true;
    trackback[rol][col] = 1;
    map[rol][col] = 'x';
    traversal(rol+1, col);
    traversal(rol-1, col);
    traversal(rol, col+1);
    traversal(rol, col-1);
}

int main(){
    init();
    for(int i = 0; i < m-1 ; i++){
        traversal(0,i);
        if(canPass) break;
    }
    if(canPass) cout << "yes\n";
    else cout << "no\n";
    return 0;
}