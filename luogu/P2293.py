m = int(input())
n = int(input())
r = 1
while r ** m <= n:
	r *= 2
l = r // 2
while l < r - 1:
	mid = (l + r) // 2
	if mid ** m <= n:
		l = mid
	else:
		r = mid
print(l)