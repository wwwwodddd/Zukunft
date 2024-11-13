a, b = map(int,input().split())
print(['No', 'Yes'][a + b + a * b == 111])
