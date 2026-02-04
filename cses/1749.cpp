#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> t;
int n, x;
int a[200020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		t.insert(i);
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		auto it = t.find_by_order(x - 1);
		printf("%d ", a[*it]);
		t.erase(it);
	}
	return 0;
}