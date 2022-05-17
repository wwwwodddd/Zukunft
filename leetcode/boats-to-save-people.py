class Solution:
    def numRescueBoats(self, a: List[int], l: int) -> int:
        a.sort(reverse=True)
        i = 0
        j = len(a) - 1
        while i <= j:
            if a[i] + a[j] <= l:
                i += 1
                j -= 1
            else:
                i += 1
        return i