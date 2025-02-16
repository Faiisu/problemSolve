#include<iostream>
#include<map>
#include<set>
using namespace std;

map<int,int> mem_seq;

int main(){
    int n, input, m = 0, output;
    cin >> n;
    while(n--){
        cin >> input;
        mem_seq[input] +=1;
        if(mem_seq[input] >= m){
            m = mem_seq[input];
            output = input;
        }
        cout << output << "\n";
    }
    return 0;
}