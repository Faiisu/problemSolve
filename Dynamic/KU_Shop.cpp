/*  greatest sum in which the sequence of each
    number is at least 1 order apart */

#include <iostream>
using namespace std;

int max1 = 0;
int max2 = 0;
int hold;
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;
        hold = max1;
        if (max1 < max2 + inp)
        {
            max1 = max2 + inp;
        }
        max2 = hold;
    }
    cout << max1;
    return 0;
}