n = int(input())
n = n // 100 * 60 + n % 100
def F(n):
	n %= 1440
	return (n // 60 * 100 + n % 60) 
print(F(n), 'in Ottawa')
print(F(n - 180), 'in Victoria')
print(F(n - 120), 'in Edmonton')
print(F(n - 60), 'in Winnipeg')
print(F(n), 'in Toronto')
print(F(n + 60), 'in Halifax')
print(F(n + 90), "in St. John's")