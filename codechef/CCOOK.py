for t in range(int(input())):
	s = ['Beginner', 'Junior Developer', 'Middle Developer', 'Senior Developer', 'Hacker', 'Jeff Dean']
	print(s[sum(map(int, input().split()))])