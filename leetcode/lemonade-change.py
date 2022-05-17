class Solution:
    def lemonadeChange(self, a: List[int]) -> bool:
        x, y = 0, 0
        for i in a:
            if i == 5:
                x += 1
            elif i == 10:
                if x > 0:
                    x -= 1
                    y += 1
                else:
                    return False
            elif i == 20:
                if y > 0 and x > 0:
                    x -= 1
                    y -= 1
                elif x >= 3:
                    x -= 3
                else:
                    return False
        return True