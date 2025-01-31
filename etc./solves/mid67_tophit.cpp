#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<int, int> vote_map;
int vote_seq[1001000];
int main(){
    int n, m, l;
    cin >> n >> m >> l;
    int top_vote = 0;
    int bestB = 0;
    
    for(int i = 1 ; i <= n ; i++){
        int input;
        cin >> input;
        vote_map[input] += 1;
        vote_seq[i] = input;
        
        if(i >= m){
            vote_map[vote_seq[i-m+1]] -= 1;
        }
        
        if(vote_map[input] > top_vote || (vote_map[input] == top_vote && input < bestB)){
            top_vote = vote_map[input];
            bestB = input;
        }
    }
    cout << bestB << " " << top_vote;
    return 0;
}