class Solution:
    def busyStudent(self, a: List[int], b: List[int], t: int) -> int:
        return sum(a[i]<=t<=b[i]for i in range(len(a)))