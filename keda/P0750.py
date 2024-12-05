import sys
sys.stdin = open('jishu.in')
sys.stdout = open('jishu.out', 'w')
for t in range(int(input())):
	n, k = map(int, input().split())
	s = sum(int(i) % 2 for i in map(int, input().split()))
	if s % 2 == k % 2 and s >= k:
		print('YES')
	else:
		print('NO')