#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> t;
int n, k;
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		t.insert(i);
	}
	int s = 0;
	while (t.size() > 0)
	{
		s += k;
		s %= t.size();
		auto it = t.find_by_order(s);
		cout << *it << " ";
		t.erase(it);
	}
	return 0;
}