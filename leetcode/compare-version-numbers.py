class Solution:
    def compareVersion(self, a: str, b: str) -> int:
        a = list(map(int,a.split('.')))
        b = list(map(int,b.split('.')))
        while len(a) and a[-1]==0:
            a.pop()
        while len(b) and b[-1]==0:
            b.pop()
        return (a > b) - (a < b)