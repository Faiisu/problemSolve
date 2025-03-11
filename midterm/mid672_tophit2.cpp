#include<iostream>
#include<map>
#include<vector>
using namespace std;

int l, n, k;
map<int,int> writer, voteScore;
map<int,vector<int> > sortResult;
int track[100100];

int main(){
    cin >> l >> n >> k;
    // number of books = L
    for(int i = 0 ; i < l ; i++){
        int inp;
        cin >> inp;
        writer[i+1] = inp;
    }

    for(int i = 0 ; i < n; i++){
        int voted;
        cin >> voted;
        voteScore[voted] += 1;
    }
    for(auto ite : voteScore){
        int NofB = ite.first;
        int score = ite.second;
        sortResult[score].push_back(NofB);
    }

    int cnt = 0;
    for(auto ite = sortResult.rbegin(); ite!=sortResult.rend(); ite++){
        int score = ite->first;
        // cout << score << "|| ";
        for(auto NofB : ite->second){
            if(track[writer[NofB]] == 1 || cnt >= k) continue;

            // cout << NofB << "-" << writer[NofB] << " ";
            cout << NofB << "\n";
            track[writer[NofB]] = 1;
            cnt++;
            // if(writer[NofB] == 1) continue;
            // cout << NofB << "\n";
            // writer[NofB] == 1;
            // cnt++;
        }
        // cout << endl;
    }

    return 0;
}