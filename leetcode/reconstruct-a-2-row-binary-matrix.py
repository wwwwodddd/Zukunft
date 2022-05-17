class Solution:
    def reconstructMatrix(self, a: int, b: int, c: List[int]) -> List[List[int]]:
        A = []
        B = []
        for i in c:
            if i == 0:
                A.append(0)
                B.append(0)
            elif i == 2:
                A.append(1)
                B.append(1)
                a -= 1
                b -= 1
            elif i == 1:
                if a > b:
                    A.append(1)
                    B.append(0)
                    a -= 1
                else:
                    A.append(0)
                    B.append(1)
                    b -= 1
        if a == 0 and b == 0:
            return [A, B]
        else:
            return []