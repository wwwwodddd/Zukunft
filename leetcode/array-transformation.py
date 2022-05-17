class Solution:
    def transformArray(self, a: List[int]) -> List[int]:
        while True:
            b = a.copy()
            for i in range(1, len(a) - 1):
                if a[i - 1] > a[i] < a[i + 1]:
                    b[i] += 1
                if a[i - 1] < a[i] > a[i + 1]:
                    b[i] -= 1
            if a == b:
                break
            a = b
        return a

                    