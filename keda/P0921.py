n = int(input())
print(['no', 'yes'][n % 400 == 0 or n % 100 != 0 and n % 4 == 0])