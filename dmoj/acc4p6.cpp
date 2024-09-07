bool f(int N)
{
	while (N != 1 && N != 4)
	{
		int s = 0;
		while (N > 0)
		{
			s += (N % 10) * (N % 10);
			N /= 10;
		}
		N = s;
	}
	return N == 1;
}