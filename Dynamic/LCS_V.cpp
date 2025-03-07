// longest common subsequence (value)
#include<iostream>
#include<string.h>
using namespace std;

string fStr, sStr;
int temp[210], head[210];
int main(){
    cin >> fStr >> sStr;
    for(int j = 0 ; j <= sStr.size(); j++){
        temp[j] = 0;
        head[j] = 0;
    }

    for(int i = 0 ; i < fStr.size() ; i++){
        for(int j = 0 ; j < sStr.size() ; j++){
            if(fStr[i] == sStr[j]){
                // cout <<"T\n";
                head[j+1] = max(temp[j+1], temp[j]+1);
            }
            else head[j+1] = max(head[j], temp[j+1]);
        }
        for(int j = 0; j < sStr.size(); j++){
            // printf("%d %d\n", temp[j+1], head[j+1]);
            temp[j+1] = head[j+1];
        }
        // printf("=============\n");
    }

    cout << head[sStr.size()];
    return 0;
}