s = input()
print('Letters=%d' % (sum(i.isalpha() for i in s)))
print('Digits=%d' % (sum(i.isdigit() for i in s)))