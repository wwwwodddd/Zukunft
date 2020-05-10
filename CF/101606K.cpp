#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int a[1000020][3];
int h[100020];
int v[100020];
int s,t;
int tot = 1;
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;

	tot++;
	a[tot][0]=h[y];
	a[tot][1]=x;
	a[tot][2]=0;
	h[y]=tot;
//	cerr << x << ' ' << y << ' ' << z << endl;
}
int bfs()
{
	int now,p,i;
	memset(v,0,sizeof(v));
	v[s]=1;
	queue<int>q;
	q.push(s);
	while(q.size())
	{
		now=q.front();
		q.pop();
		for(i=h[now];i;i=a[i][0])
		{
			if(!v[a[i][1]]&&a[i][2])
			{
				v[a[i][1]]=v[now]+1;
				q.push(a[i][1]);
				if(a[i][1]==t)
					return 1;
			}
		}
	}
	return 0;
}

int dinic(int x,int y)
{
	int u=y,k,i;
	if(x==t)
		return y;
	for(i=h[x];i;i=a[i][0])
	{
		if(u&&a[i][2]&&v[a[i][1]]==v[x]+1)
		{
			k=dinic(a[i][1],min(a[i][2],u));
			if(!k)
				v[a[i][1]]=0;
			u-=k;
			a[i][2]-=k;
			a[i^1][2]+=k;
		}
	}
	return y-u;
}
int n, m;
int W[120], L[120];
int T[120];
vector<int> pt[120];
int z[120], zc;
void dfs(int x) {
//	printf("%d\n", x);
	if (x == t) {
		int which = -1;
//		for (int i = 0; i < zc; i++) {
//			printf("%d%c", z[i], i == zc - 1 ? '\n' : ' ');
//		}
		for (int i = 0; i < zc; i++) {
			if (2 * n <= z[i] && z[i] < 2 * n + m) {
				assert(which == -1);
				which = z[i] - 2 * n;
//				printf("which %d %d %d\n", which, i, z[i]);
			}
		}
		for (int i = 0; i < zc; i++) {
			if (n <= z[i] && z[i] < 2 * n) {
				pt[which].push_back(z[i] - n + 1);
			}
		}
		return;
	}
	z[zc++] = x;
	for(int i=h[x];i;i=a[i][0]) {
		if (i % 2 == 0 && a[i^1][2] > 0) {
			dfs(a[i][1]);
		}
	}
	zc--;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> W[i] >> L[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> T[i];
	}
	s = 2 * n + m;
	t = s + 1;
//	cerr << "s" << s << endl;
//	cerr << "t" << t << endl;

	for (int i = 0; i < n; i++) {
		if (W[i] == 0) {
			add(s, i, 1);
		}
		add(i, i + n, 1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (L[i] >= W[j]) {
				add(i + n, j, 1);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		add(2 * n + i, t, 1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (L[i] >= T[j]) {
				add(i + n, 2 * n + j, 1);
			}
		}
	}

	int ans = 0;
	while(bfs())
		while(int dd=dinic(s,inf))
			ans += dd;
	if (ans == m) {
//		fprintf(stderr, "YES\n");
		dfs(s);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < pt[i].size(); j++) {
				printf("%d%c", pt[i][j], j == pt[i].size() - 1 ? '\n' : ' ');
			}
		}
	} else {
		printf("impossible\n");
	}
	return 0;
}
