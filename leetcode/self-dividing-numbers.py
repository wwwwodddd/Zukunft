class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        z = []
        for i in range(left, right + 1):
            if '0' in str(i):
                continue
            for j in str(i):
                if i % int(j) != 0:
                    break
            else:
                z.append(i)
        return z