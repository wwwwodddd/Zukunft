n = int(input())
print('NY'[n % 400 == 0 or n % 100 != 0 and n % 4 == 0])