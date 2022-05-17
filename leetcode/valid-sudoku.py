class Solution:
    def isValidSudoku(self, a: List[List[str]]) -> bool:
        for r in a:
            s = set()
            for i in r:
                if i != '.':
                    if i in s:
                        return False
                    s.add(i)
        for c in zip(*a):
            s = set()
            for i in c:
                if i != '.':
                    if i in s:
                        return False
                    s.add(i)
        for i in range(0,9,3):
            for j in range(0,9,3):
                s = set()
                for k in range(i,i+3):
                    for l in range(j,j+3):
                        if a[k][l] != '.':
                            if a[k][l] in s:
                                return False
                            s.add(a[k][l])
        return True