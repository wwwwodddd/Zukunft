class Solution:
    def findEvenNumbers(self, a: List[int]) -> List[int]:
        b=[]
        for i in range(len(a)):
            if a[i]>0:
                for j in range(len(a)):
                    if j!=i:
                        for k in range(len(a)):
                            if k!=i and k!=j and a[k]%2==0:
                                b.append(a[i]*100+a[j]*10+a[k])
        return sorted(list(set(b)))