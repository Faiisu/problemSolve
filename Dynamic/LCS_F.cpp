// Longest common substring (full)
// longest common subsequence (value)
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

string fStr, sStr;
int temp[210], head[210];
vector<char> seq;

void printSeq(int n){
    if(n == 0) return;
    cout << fStr[n];
    if(bf[n] != n) printSeq(bf[n]);
}

int main(){
    cin >> fStr >> sStr;
    for(int j = 0 ; j <= sStr.size(); j++){
        temp[j] = 0;
        head[j] = 0;
        bf[j] = j;
    }

    for(int i = 1 ; i < fStr.size() ; i++){
        for(int j = 1; j < sStr.size() ; j++){
            if(fStr[i] == sStr[j]){
                // cout <<"T\n";
                if(temp[j] +1  > temp[j+1]){
                    head[j+1] = temp[j] +1;                                        

                }
                else{
                    head[j+1] = temp[j+1];
                }
            }
            else head[j+1] = max(head[j], temp[j+1]);
        }
        for(int j = 0; j < sStr.size(); j++){
            // printf("%d %d\n", temp[j+1], head[j+1]);
            temp[j+1] = head[j+1];
        }
        // printf("=============\n");
    }
    cout << head[sStr.size()]+1 <<"\n";
    printSeq(sStr.size());
    return 0;
}