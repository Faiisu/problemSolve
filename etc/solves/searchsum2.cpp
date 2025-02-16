#include<iostream>
#include<map>
using namespace std;

typedef long long ll;
map<int,int> books;

int main(){
    ll n, k, input;
    cin >> n >> k;
    ll sum = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> input;
        sum += input;
        books[sum] = i;
    }
    while(k--){
        cin >> input;
        if(input < books.begin()->first){
            cout << "0\n";
            continue;
        }

        auto ite = books.upper_bound(input);
        ite--;
        cout << ite->second << "\n";
    }
    return 0;
}