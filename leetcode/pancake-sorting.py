class Solution:
    def pancakeSort(self, a: List[int]) -> List[int]:
        z = []
        for i in range(1,len(a)+1)[::-1]:
            r = a.index(i)+1
            z.append(r)
            a[:r] = a[:r][::-1]
            z.append(i)
            a[:i] = a[:i][::-1]
        return z