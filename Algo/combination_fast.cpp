template<typename T>
T nCr(T n, T k)
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    T result = n;
    for(int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
// works by using a single loop to both increment R value and Decrease N value
