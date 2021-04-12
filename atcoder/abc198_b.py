n=input().rstrip('0')
print('YNeos'[n!=n[::-1]::2])