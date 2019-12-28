#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int ans, n, t;
long long a[40];
void dfs(int x, int y, long long m)
{
	ans = max(ans, y);
	for (; x < 36; x++) {
		if (__builtin_popcount(m & a[x]) > y) {
			dfs(x + 1, y + 1, m & a[x]);
		}
	}
}
int main()
{
	for(scanf("%d",&t); t--;) {
		scanf("%d",&n);
		ans = 0;
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[x] |= 1LL << y - 1;
		}
		dfs(0, 0, (1LL << 36) - 1);
		printf("%d\n",ans);
	}
	return 0;
}
