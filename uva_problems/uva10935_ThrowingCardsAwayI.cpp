#include<iostream>
#include<list>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(true){
        cin >> n;
        if(n == 0) break;

        list<int> decks;
        for(int i = 1 ; i <= n; i++) decks.push_back(i);

        bool first = true;
        cout << "Discarded cards:";
        while(decks.size() != 1){
            if (!first) cout << ",";
            first = false;
            cout << " " << decks.front();
            decks.pop_front();
            decks.push_back(decks.front());
            decks.pop_front();
        }
        cout << "\nRemaining card: " << decks.front() << "\n";
    }
    return 0;
}