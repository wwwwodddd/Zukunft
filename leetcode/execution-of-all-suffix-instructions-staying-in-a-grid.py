class Solution:
    def executeInstructions(self, n: int, startPos: List[int], s: str) -> List[int]:
        z = []
        for i in range(len(s)):
            x, y = startPos
            for j in range(i, len(s)):
                if s[j] == 'U':
                    x -= 1
                elif s[j] == 'D':
                    x += 1
                elif s[j] == 'L':
                    y -= 1
                elif s[j] == 'R':
                    y += 1
                if x < 0 or x >= n or y < 0 or y >= n:
                    z.append(j - i)
                    break
            else:
                z.append(len(s) - i)
        return z
                