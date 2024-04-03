//https://www.codechef.com/problems/ARRGAME?tab=statement

#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <deque>
#include <list>
#include <forward_list>
#include <utility>
#include <algorithm>
#include <vector>
#include <array>
#include <tuple>

using namespace std;

typedef unsigned long long int ull;
typedef unsigned long int ul;
typedef unsigned short us;
typedef unsigned char uc;

typedef long long int ll;

void solve();
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

void solve()
{
    ll n;
    cin >> n;

    int count = 0;
    int max1 = 0;
    int max2 = 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] != 1)
            count++;
        else
        {
            if (count >= max1)
            {
                max2 = max1;
                max1 = count;
            }
            else if (count > max2)
            {
                max2 = count;
            }
            count = 0;
        }

    }

    if (max1 != 0 && max1 % 2 == 1 && max2 < (max1 + 1) / 2)
        cout << "Yes\n";
    else
        cout << "No\n";
}
