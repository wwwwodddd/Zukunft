class ATM:

    def __init__(self):
        self.a = [0, 0, 0, 0, 0]
        pass

    def deposit(self, a: List[int]) -> None:
        for i in range(5):
            self.a[i] += a[i]

    def withdraw(self, m: int) -> List[int]:
        b = [20, 50, 100, 200, 500]
        c = [0 for i in b]
        for i in range(5)[::-1]:
            c[i] = min(self.a[i], m // b[i])
            m -= c[i] * b[i]
        if m == 0:
            for i in range(5):
                self.a[i] -= c[i]
            return c
        else:
            return [-1]

# Your ATM object will be instantiated and called as such:
# obj = ATM()
# obj.deposit(banknotesCount)
# param_2 = obj.withdraw(amount)