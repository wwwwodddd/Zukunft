s = input()
a = s.split(' ')
print(' '.join(i[::-1] for i in a))