# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:

class Solution:
    def findCelebrity(self, n: int) -> int:
        x = 0
        for i in range(1, n):
            if knows(x, i):
                x = i
        for i in range(n):
            if i != x:
                if knows(x, i) or not knows(i, x):
                    return -1
        return x