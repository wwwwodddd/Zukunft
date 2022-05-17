class Solution:
    def generate(self, n: int) -> List[List[int]]:
        r = []
        a = [1]
        r.append(a)
        for i in range(1,n):
            a = [0]+a+[0]
            a = [a[i] + a[i+1]for i in range(len(a)-1)]
            r.append(a)
        return r