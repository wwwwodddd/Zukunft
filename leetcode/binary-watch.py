class Solution:
    def readBinaryWatch(self, m: int) -> List[str]:
        z = []
        for i in range(12):
            for j in range(60):
                if bin(i).count('1') + bin(j).count('1') == m:
                    z.append('%d:%02d' % (i, j))
        return z