uint64_t Pow(uint64_t val, uint64_t pow)
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
