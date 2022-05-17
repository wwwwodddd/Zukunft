from threading import Semaphore
class DiningPhilosophers:
    def __init__(self):
        self.s = Semaphore()

    # call the functions directly to execute, for example, eat()
    def wantsToEat(self,
                   i: int,
                   pickLeftFork: 'Callable[[], None]',
                   pickRightFork: 'Callable[[], None]',
                   eat: 'Callable[[], None]',
                   putLeftFork: 'Callable[[], None]',
                   putRightFork: 'Callable[[], None]') -> None:
        self.s.acquire()
        pickLeftFork()
        pickRightFork()
        eat()
        putLeftFork()
        putRightFork()
        self.s.release()