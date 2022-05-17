from threading import Semaphore

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.i = 0
        self.z = Semaphore(1)
        self.o = Semaphore(0)
        self.e = Semaphore(0)
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        while True:
            self.z.acquire()
            self.i += 1
            if self.i > self.n:
                self.o.release()
                self.e.release()
                return
            printNumber(0)
            if self.i % 2:
                self.o.release()
            else:
                self.e.release()

    def even(self, printNumber: 'Callable[[int], None]') -> None:
        while True:
            self.e.acquire()
            if self.i > self.n:
                return
            printNumber(self.i)
            self.z.release()

    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        while True:
            self.o.acquire()
            if self.i > self.n:
                return
            printNumber(self.i)
            self.z.release()
        
        