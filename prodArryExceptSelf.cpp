// https://www.youtube.com/watch?v=riBWq1DvVb8
// T.C. = O(n) S.C. = O(1)

typedef long long int ll;
ll* sol(int* arr, size_t n)
{
    ll prod = 1;
    int zeros = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            prod *= arr[i];
        else
            zeros++;
    }

    ll* out = new ull[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            if(zeros > 1)
                out[i] = 0;
            else
                out[i] = prod;
        else if( zeros > 0)
            out[i] = 0;
        else
            out[i] = prod / arr[i];
    }

    return out;
}
int main()
{
    const int n = 4;
    int arr[n] = { 0 ,-2 ,0 ,-4 };
    auto out = sol(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << out[i] << " ";
    }
}
