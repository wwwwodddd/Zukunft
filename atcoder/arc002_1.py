n=int(input())
print('YNEOS'[n%4>0 or n%100==0 and n%400>0::2])