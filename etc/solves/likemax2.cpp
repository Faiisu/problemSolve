#include<iostream>
#include<map>
#include<list>
using namespace std;

map<int,list<int> > mem_seq;
map<int,map<int,int> > mem_num;
map<int, int> mem_like;

int main(){
    int n, like, num, max_like = 0;
    cin >> n;
    while(n--){
        cin >> like >> num;
        if(like) mem_like[num] += 1;
        else mem_like[num] -= 1;
        mem_seq[mem_like[num]].push_front(num);
    
        auto ite = mem_seq.end();
    }

    return 0;
}