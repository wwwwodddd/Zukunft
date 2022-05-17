class Solution:
    def rearrangeArray(self, a: List[int]) -> List[int]:
        a.sort()
        a[0::2], a[1::2] = a[len(a)//2:], a[:len(a)//2]
        return a