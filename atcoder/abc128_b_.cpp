#include <bits/stdc++.h>
using namespace std;
struct Restaurant
{
	string city;
	int score;
	int identification;
} restaurants[100];
int n;
bool cmp(Restaurant a, Restaurant b)
{
	if (a.city != b.city)
	{
		return a.city < b.city;
	}
	if (a.score != b.score)
	{
		return a.score > b.score;	
	}
	return a.identification < b.identification;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> restaurants[i].city >> restaurants[i].score;
		restaurants[i].identification = i + 1;
	}
	sort(restaurants, restaurants + n, cmp);
	for (int i = 0; i < n; i++)
	{
		cout << restaurants[i].identification << endl;
	}
	return 0;
}
