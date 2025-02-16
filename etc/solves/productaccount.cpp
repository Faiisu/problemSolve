#include<iostream>
#include<map>

using namespace std;

map<int,int> products;

int add_product(){
    int type, num;
    cin >> type >> num;
    products[type] += num;
}

int show_product(){
    int type;
    cin >> type;
    cout << products[type] << "\n";
}

int del_product(){
    int type, num;
    cin >> type >> num;
    if(products[type] < num){
        cout << products[type];
        products[type] = 0;
    }
    else{
        cout << num;
        products[type] -= num;
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cmd;
    cin >> n;
    while(n--){
        cin >> cmd;
        if(cmd == 1) add_product();
        else if(cmd == 2) show_product();
        else del_product();
    }
    return 0;
}