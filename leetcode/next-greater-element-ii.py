class Solution:
    def nextGreaterElements(self, a: List[int]) -> List[int]:
        n = len(a)
        a = a + a
        s = []
        z = [-1 for i in range(2 * n)]
        for i in range(2 * n)[::-1]:
            while len(s) > 0 and a[i] >= s[-1]:
                s.pop()
            if len(s) > 0:
                z[i] = s[-1]
            s.append(a[i])
        return z[:n]
                
                