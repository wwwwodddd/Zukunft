s=raw_input()
print [s[i]+s[j]+s[k]for i in range(len(s))for j in range(i)for k in range(j)].count('QAQ')