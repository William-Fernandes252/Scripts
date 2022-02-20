from time import sleep
from threading import Thread, Lock


# class Process(Thread):
#     def __init__(self, description, time):
#         self.description = description
#         self.time = time  
#         super().__init__()
    
#     def run(self):
#         sleep(self.time)
#         print(f'Process "{self.description}" done.')
        

# p1 = Process('Thread 1', 5)
# p1.start()

# p2 = Process('Thread 2', 2)
# p2.start()

# p3 = Process('Thread 3', 3)
# p3.start()

# for i in range(20):
#     print(i)
#     sleep(.5)


# def longprocess(description, time):
#     sleep(time)
#     print(f'Process "{description}" done.')
    

# p1 = Thread(target=longprocess, args=('Thread 1', 5))
# p1.start()

# p2 = Thread(target=longprocess, args=('Thread 2', 3))
# p2.start()

# p3 = Thread(target=longprocess, args=('Thread 3', 2))
# p3.start()

# for i in range(20):
#     print(i)
#     sleep(.5)

# p1 = Thread(target=longprocess, args=('Thread 1', 10))
# p1.start()

# while p1.is_alive():
#     print('Thread running.')
#     sleep(2)


class Tickets:
    def __init__(self, stock):
        self.stock = stock
        self.lock = Lock()
        
    def buy(self, amount):
        self.lock.acquire()
        
        if self.stock < amount:
            print('We do not have enough tickets.')
            self.lock.release()
            return
        
        sleep(1)
        
        print(
            f'You bought {amount} tickets.',
            f'We still have {self.stock} in stock.'
        )
        self.stock -= amount
        
        self.lock.release()
        

if __name__ == '__main__':
    tickets = Tickets(10)
    
    threads = []
    for i in range(1, 20):
        buy = Thread(target=tickets.buy, args=(1,))
        threads.append(buy)
        
    for t in threads:
        t.start()
        
    running = True
    while running:
        running = False
        
        for t in threads:
            if t.is_alive():
                running = True
                break
        
    print(f'Tickets in stock: {tickets.stock}')