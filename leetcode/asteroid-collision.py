class Solution:
    def asteroidCollision(self, a: List[int]) -> List[int]:
        b = []
        for i in a:
            if i < 0:
                while len(b) and b[-1] > 0:
                    if -i == b[-1]:
                        b.pop()
                        break
                    elif -i > b[-1]:
                        b.pop()
                    else:
                        break
                else:
                    b.append(i)
            else:
                b.append(i)
        return b