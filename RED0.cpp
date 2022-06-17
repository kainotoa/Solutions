//https://www.codechef.com/problems/RED0

#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;

uint64_t flp2(uint64_t x)
{
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    return x - (x >> 1);
}
const int tab64[64] = {
    63,  0, 58,  1, 59, 47, 53,  2,
    60, 39, 48, 27, 54, 33, 42,  3,
    61, 51, 37, 40, 49, 18, 28, 20,
    55, 30, 34, 11, 43, 14, 22,  4,
    62, 57, 46, 52, 38, 26, 32, 41,
    50, 36, 17, 19, 29, 10, 13, 21,
    56, 45, 25, 31, 35, 16,  9, 12,
    44, 24, 15,  8, 23,  7,  6,  5 };

int log2_64(uint64_t value)
{
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    value |= value >> 32;
    return tab64[((uint64_t)((value - (value >> 1)) * 0x07EDD5E59A4E28C2)) >> 58];
}
void solve() {
    ll x, y; cin >> x >> y;
    ll diff = 0, count = 0;
    if (x > y)
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

    auto temp = flp2(y / x);
    x *= temp;
    count += log2_64(temp);

    if (x == y)
        count += y;
    else
        count += y + 1;

    cout << count << endl;
}
int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}