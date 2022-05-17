class Solution:
    def findCenter(self, a: List[List[int]]) -> int:
        return (set(a[0])&set(a[1])).pop()