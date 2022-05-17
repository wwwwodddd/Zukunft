class FirstUnique:

    def __init__(self, a: List[int]):
        self.c = Counter()
        self.q = deque()
        for i in a:
            self.c[i] += 1
            self.q.append(i)

    def showFirstUnique(self) -> int:
        while self.q:
            if self.c[self.q[0]] == 1:
                return self.q[0]
            self.q.popleft()
        return -1

    def add(self, i: int) -> None:
        self.c[i] += 1
        self.q.append(i)


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)