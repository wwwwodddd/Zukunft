#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
#include <iostream> 
using namespace __gnu_pbds; 
using namespace std; 
tree<pair<int, int> , null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> t;
pair<pair<int, int>, int> a[200020];
int x[200020];
int y[200020];
int n;
int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first.first, &a[i].first.second);
		a[i].first.second = -a[i].first.second;
		a[i].second = i;
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--)
	{
		x[a[i].second] = t.order_of_key(make_pair(-a[i].first.second, n));
		t.insert(make_pair(-a[i].first.second, i));
	}
	t.clear();
	for (int i = 0; i < n; i++)
	{
		y[a[i].second] = t.size() - t.order_of_key(make_pair(-a[i].first.second, 0));
		t.insert(make_pair(-a[i].first.second, i));
	}
	t.clear();
	for (int i = 0; i < n; i++)
	{
		printf("%d ", x[i] > 0);
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", y[i] > 0);
	}
	printf("\n");
	return 0;
} 