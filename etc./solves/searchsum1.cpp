#include<iostream>
#include<map>
using namespace std;

map<int,int> books;

int main(){
    int n, k, input;
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> input;
        books[i] = input;
    }
    auto ite = books.upper_bound(50);
    if(ite != books.end()) cout << "not found";
    cout << ite->first << " ";

    return 0;
}