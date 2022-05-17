class MyCalendar:

    def __init__(self):
        self.a = []

    def book(self, s: int, e: int) -> bool:
        for x, y in self.a:
            if max(x, s) < min(e, y):
                return False
        self.a.append((s, e))
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)