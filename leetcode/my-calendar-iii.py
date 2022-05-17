class MyCalendarThree:

    def __init__(self):
        self.a = []

    def book(self, start: int, end: int) -> int:
        self.a.append((start, 1))
        self.a.append((end, -1))
        self.a.sort()
        z = c = 0
        for x, y in self.a:
            c += y
            z = max(z, c)
        return z


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(start,end)