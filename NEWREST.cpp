#include <iostream>
#include <memory>

using std::cout;
using std::cin;
typedef unsigned long long int intExt;

std::shared_ptr<intExt[]> LookUP;
intExt Size;
intExt Pow(intExt num, intExt exp)
{
	intExt val = 1;
	while (exp--)
	{
		val *= num;
	}
	return val;
}
intExt Fact(intExt n)
{
	if (n == 1)
		return 1;
	if (n == 0)
		return 1;
	return (n * Fact(n - 1));
}
intExt Combination(const intExt n, const intExt r)
{
	return (Fact(n) / Fact(r) / Fact(n - r));
}

intExt ServingPermutation(intExt days, intExt dishes)
{
	intExt perms = Pow(dishes,days);

	for (intExt i = 1; i < dishes; i++)
	{
		perms -= dishes * LookUP.get()[i];
	}

	LookUP.get()[dishes] = perms;

	return perms;
}
uint32_t CalCookingPerm()
{
	intExt total = 0;
	int N, M, K;
	cin >> N >> M >> K;

	if (N < 1 || M < 1 || K < 1)
		return 0;

	if (N == 0)
		return 0;
	if (M < K)
		return 0;

	Size = K + 1;
	LookUP = std::make_shared<intExt[]>(Size);
	for (int i = 1; i <= K; i++)
	{
		total += Combination(M,i) * ServingPermutation(N, i);
	}
	
	return (total % 1000000007);
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cout << CalCookingPerm();
	}
}