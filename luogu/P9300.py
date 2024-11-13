g = {'Poblano' : 1500, 'Mirasol' : 6000, 'Serrano' : 15500, 'Cayenne' : 40000, 'Thai' : 75000, 'Habanero' : 125000}
n = int(input())
print(sum(g[input()]for i in range(n)))