#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

typedef size_t ull;

void solve();

int main() {
    
    int t;
    cin >> t;
    
    while (t--)
    solve();
}

ull mod = 1e+9 + 7;


uint64_t PowNoRec(uint64_t val, uint64_t pow)
{
	if (val == 0)
		return 0;
	if (pow == 0)
		return 1;

	uint64_t extra = 1;

	while(pow > 1)
	{
		if (pow % 2 == 1)
			{
			    extra *= val;
			    extra %= mod;
			}
		pow = pow / 2;

		val *= val;
		val %= mod;
	}

	val *= extra;
    
    val %= mod;
	return val;
}


ull modInv(ull num)
{
    return PowNoRec(num,mod - 2);
}

template<typename T>
T nCr(T n, T k)
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    T result = n;
    T divi = 1;
    for(int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result %= mod;
        divi *= i;
        divi %= mod;
    }
    divi = modInv(divi);
    result = result * divi % mod;
    return result;
}

void solve()
{
    ull n;
    cin >> n;
    
    string a;
    string b;
    
    cin >> a >> b;
    
    ull hd = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != b [i])
        hd++;
    }
    
    if(hd == 0)
    {
        cout << PowNoRec(2,n) << "\n";
    }
    else
    if (hd % 2)
    {
        cout << 0 << "\n";
    }
    else
    cout << PowNoRec(2,n - hd) * nCr(hd,hd/2) % mod << "\n";
}
