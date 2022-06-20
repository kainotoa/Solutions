//https://www.codechef.com/problems/LOSTARRAY_
#include <iostream>
using std::cin;
using std::cout;

void Compute()
{
    int n;
    cin >> n;
    int* B = new int[n + 1];
    for(int i = 0; i < n + 1; i++)
    {
        cin >> B[i];
    }

    if (n % 2 == 0)
    {
        for (int i = 1; i < n + 1; i++)
        {
            cout << (B[0] ^ B[i]) << " ";
        }
    }
    else
    {
        for (int i = 0; i < n + 1; i++)
        {
            int XoRs = 0;
            for (int j = 0; j < n + 1; j++)
            {
                if (i != j)
                    XoRs ^= B[j];
            }
            if (XoRs == 0)
            {
                for (int j = 0; j < n + 1; j++)
                {
                    if (i != j)
                        cout << (B[i] ^ B[j]) << " ";
                }
                break;
            }
        }
    }
    delete[] B;
}

int main() {
    int T;
    cin >> T;
    while (T--)
    {
        Compute();
        cout << "\n";
    }
    return 0;
}