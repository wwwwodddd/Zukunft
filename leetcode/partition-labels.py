class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        a = [0 for i in s]
        for i in s:
            for j in range(s.index(i),s.rindex(i)):
                a[j]+=1
        b = [i for i in range(len(a))if a[i]==0]
        for i in range(1,len(b))[::-1]:
            b[i]-=b[i-1]
        b[0]+=1
        return b