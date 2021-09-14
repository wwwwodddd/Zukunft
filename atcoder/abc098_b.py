n=int(input())
s=input()
print(max(len(set(s[:i])&set(s[i:]))for i in range(n)))