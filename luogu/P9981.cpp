#include <bits/stdc++.h>
using namespace std;
const unsigned long long mod1 = 1000000123;
unsigned long long pw1[20];
int n, m;
vector<pair<int, int>> a[400020]; // forward edges / outgoing edges
vector<int> b[400020];			  // backward edges / incoming edges
int d[400020];					  // out degree
long long e[400020];			  // sum of labels on the longest path
int f[400020];					  // length of the longest path
int g[400020][20];				  // g[i][j] = the 2**j-th vectex on the longest path from vectorx i
unsigned long long h[400020][20]; // the hash of all labels of the first 2**j labels on the longest path from vectorx i
bool cmp(int x, int y)			  // compare two paths, which is lexicographically smaller?
{
	assert(f[x] == f[y]); // must have the same length
	for (int j = 19; j >= 0; j--)
	{
		if (h[x][j] == h[y][j]) // if hash are the same, then the first 2**j labels are the same
		{
			x = g[x][j]; // skip these 2**j vectices / labels
			y = g[y][j];
		}
	}
	return h[x][0] < h[y][0]; // the next label (hash) is different, compare them
}
int main()
{
	pw1[0] = 13131;
	for (int i = 1; i < 20; i++)
	{
		pw1[i] = pw1[i - 1] * pw1[i - 1] % mod1;
	} // pw1 and mod1 are useless, you should choose your own hash function
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z)); // forward edges
		d[x]++;
		b[y].push_back(x); // backward edges  for  topological sort
	}
	queue<int> q;
	for (int i = 1; i <= m; i++)
	{
		if (d[i] == 0)
		{
			q.push(i); // all vertices with out degree = 0
		}
	}
	while (q.size() > 0)
	{
		int u = q.front();
		q.pop();
		for (pair<int, int> i : a[u])
		{
			if (f[u] < 1 + f[i.first]) // if a longer path is found
			{
				f[u] = 1 + f[i.first];		  // update length
				e[u] = i.second + e[i.first]; // update sum
				g[u][0] = i.first;			  // update next vectex
				h[u][0] = i.second;			  // update hash (or label when length = 1)
			}
			else if (f[u] == 1 + f[i.first] && (h[u][0] > i.second || h[u][0] == i.second && cmp(i.first, g[u][0])))
			{
				// if a path with the same length found
				//     if the previous choice is larger than current first label or
				//         the previous choice equals the current first label and compare the path from  i.first  and  g[u][0]
				// update
				f[u] = 1 + f[i.first];
				e[u] = i.second + e[i.first];
				g[u][0] = i.first;
				h[u][0] = i.second;
			}
		}
		for (int j = 1; j < 20; j++)
		{
			// update 2**1 to 2**19
			g[u][j] = g[g[u][j - 1]][j - 1];
			h[u][j] = ((h[g[u][j - 1]][j - 1] * 1234567891) ^ h[u][j - 1]); // choose any hash function you like   hash(x, y)
		}
		for (int i : b[u])
		{
			if (!--d[i]) // normal topological sort
			{
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d %lld\n", f[i], e[i]);
	}
	return 0;
}