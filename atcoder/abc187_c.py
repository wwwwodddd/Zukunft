n = int(input())
s = set()
for i in range(n):
    s.add(input())
for i in s:
    if '!'+i in s:
        print(i)
        break
else:
    print('satisfiable')