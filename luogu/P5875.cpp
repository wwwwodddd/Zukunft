int findSample(int n, int *confidence, int *host, int *protocol)
{
	int z = 0;
	for (int i = n - 1; i > 0; i--)
	{
		if (protocol[i] == 0)
		{
			z += confidence[i];
			confidence[host[i]] -= confidence[i];
			if (confidence[host[i]] < 0)
			{
				confidence[host[i]] = 0;
			}
		}
		else if (protocol[i] == 1)
		{
			confidence[host[i]] += confidence[i];
		}
		else if (protocol[i] == 2)
		{
			if (confidence[host[i]] < confidence[i])
			{
				confidence[host[i]] = confidence[i];
			}
		}
	}
	return confidence[0] + z;
}