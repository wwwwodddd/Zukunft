from threading import Semaphore
class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.i = 0
        self.f = Semaphore(0)
        self.b = Semaphore(0)
        self.fb = Semaphore(0)
        self.p = Semaphore(1)
    # printFizz() outputs "fizz"
    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        while True:
            self.f.acquire()
            if self.i > self.n:
                return
            printFizz()
            self.p.release()
    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        while True:
            self.b.acquire()
            if self.i > self.n:
                return
            printBuzz()
            self.p.release()
    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        while True:
            self.fb.acquire()
            if self.i > self.n:
                return
            printFizzBuzz()
            self.p.release()
    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        while True:
            self.p.acquire()
            self.i += 1
            if self.i > self.n:
                self.f.release()
                self.b.release()
                self.fb.release()
                return
            if self.i % 15 == 0:
                self.fb.release()
            elif self.i % 5 == 0:
                self.b.release()
            elif self.i % 3 == 0:
                self.f.release()
            else:
                printNumber(self.i)
                self.p.release()