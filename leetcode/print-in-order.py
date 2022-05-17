from threading import Semaphore

class Foo:
    def __init__(self):
        self.a = Semaphore(0)
        self.b = Semaphore(0)
        pass


    def first(self, printFirst: 'Callable[[], None]') -> None:
        
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.a.release()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        
        self.a.acquire()
        # printSecond() outputs "second". Do not change or remove this line.
        printSecond()
        self.b.release()

    def third(self, printThird: 'Callable[[], None]') -> None:
        
        self.b.acquire()
        # printThird() outputs "third". Do not change or remove this line.
        printThird()
