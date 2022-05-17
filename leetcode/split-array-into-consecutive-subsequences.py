class Solution:
    def isPossible(self, a: List[int]) -> bool:
        c = [0 for i in range(3000)]
        for i in a:
            c[i + 1000] += 1
        q = deque()
        for i in range(3000):
            while c[i] > len(q):
                q.append(i)
            while c[i] < len(q):
                if i - q.popleft() < 3:
                    return False
        return True