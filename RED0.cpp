//https://www.codechef.com/problems/RED0

#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;

void solve() {
    ll x, y; cin >> x >> y;
    ll diff = 0, count = 0;
    if (x > y)                //always keeping x smaller than y
        swap(x, y);
    if (x == 0 && y == 0) {
        cout << 0 << endl;
        return;
    }
    if (x == 0) {
        cout << -1 << endl;
        return;
    }
    if (x == y) {
        cout << x << endl;
        return;
    }
    while (2 * x < y) {
        x *= 2;
        count++;
    }
    //diff = y-x;
    count += y + 1;
    //x=2*diff;
    //count+=2diff;
    cout << count << endl;
}
int main() {
    // your code goes here
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
