n=int(input())
print(min(abs(i-n//i)+n%i for i in range(1,n+1)))