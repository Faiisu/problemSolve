#include <iostream>
#include <map>
#include <set>

using namespace std;
int n;

map<int, set<pair<int, pair<int, int>>>> times;
// y, weight, x, i
set<pair<int, pair<int, pair<int, int>>>> totals;
// weight, size, x, y
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        times[y].insert(make_pair(w, make_pair(x, i)));
    }

    for (auto ite : times)
    {
        int y = ite.first;
        }
    return 0;
}