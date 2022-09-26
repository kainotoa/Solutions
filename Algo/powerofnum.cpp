// Number 'val' raised to power 'pow' TC = O(log(n,2)) SC = O(1)
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
			extra *= val;
		pow = pow / 2;

		val *= val;
	}

	val *= extra;

	return val;
}

// Number 'val' raised to power 'pow' TC = O(log(n,2)) SC = O(log(n,2))
uint64_t PowRec(uint64_t val, uint64_t pow)
{
	if (pow == 0)
		return 1;
	if (val == 0)
		return 0;
	if (pow == 1)
		return val;


	uint64_t d = PowRec(val, pow / 2);
	uint64_t c = d * d;
	if (pow % 2 == 1)
	{
		c *= val;
	}
	return c;
}
