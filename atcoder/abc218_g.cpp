#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
#include <iostream> 
using namespace __gnu_pbds; 
using namespace std; 
tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> t;
vector<int> a[100020];
int n, x, y;
int w[100020];
int f[100020];
int median()
{
	if (t.size() & 1)
	{
		return t.find_by_order(t.size() / 2)->first;
	}
	else
	{
		return (t.find_by_order(t.size() / 2)->first + t.find_by_order(t.size() / 2 - 1)->first) / 2;
	}
}
void dfs(int x, int y, int d)
{
	t.insert(make_pair(w[x], x));
	if (d & 1)
	{
		f[x] = 1e9;
	}
	else
	{
		f[x] = 0;
	}
	int children = 0;
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x, d + 1);
			children++;
			if (d & 1)
			{
				f[x] = min(f[x], f[i]);
			}
			else
			{
				f[x] = max(f[x], f[i]);
			}
		}
	}
	if (children == 0)
	{
		f[x] = median();
	}
	t.erase(make_pair(w[x], x));
}
int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0, 0);
	cout << f[1] << endl;
	return 0; 
} 