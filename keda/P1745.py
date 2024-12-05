s = ["Guanyu","Zhangfei","Caocao","Diaochan","Zhugeliang","Simayi"]
print(s[sum(map(ord, input())) % 6])