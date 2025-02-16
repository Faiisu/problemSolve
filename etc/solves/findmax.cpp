#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> x;

void read_input()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        int xx;
        cin >> xx;
        x.push_back(xx);
    }
}

int find_max(vector<int>& x, int n)
{
    if(n == 1) return x[n-1];
    // TODO: write this function, do not use any loop control
    int m = find_max(x, n-1);
    if(x[n-1] > m){
        return x[n-1];
    }
    return m;
}

int main()
{
    read_input();
    cout << find_max(x,n) << endl;
}