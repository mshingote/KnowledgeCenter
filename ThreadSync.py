from threading import Thread
import time

def Task(*args):
    for i in range(10):
        print args[0]       

if __name__ == '__main__':
    threads = []
    for i in range(3):
        threads.append(Thread(target=Task, args=(i+1,)))
    for i in threads:
        i.start()
    for i in threads:
        i.join()

    print 'Tasks done!'