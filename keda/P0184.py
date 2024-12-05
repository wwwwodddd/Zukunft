a, b = map(int, input().split())
print(["Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"][pow(a, b, 7)])