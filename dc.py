
from random import randint
import sys

times = sys.argv[1]

front_max=35
back_max=12

front_num=5
back_num=2

def choose_front():
    start=1
    ret=list()
    pool=list(range(1, front_max + 1))
    # print(pool)

    for i in range(1, front_num + 1):
        index=randint(0, front_max - start)
        get=pool[index]
        # print(pool, get)
        ret.append(get)
        start=start+1
        pool.pop(index)
    return ret

def choose_back():
    start=1
    ret=list()
    pool=list(range(1, back_max + 1))
    # print(pool)

    for i in range(1, back_num + 1):
        index=randint(0, back_max - start)
        get=pool[index]
        # print(pool, get)
        ret.append(get)
        start=start+1
        pool.pop(index)
    return ret

for t in range(0, int(times, 10)):
    front=choose_front()
    front.sort()

    back=choose_back()
    back.sort()
    print(front, back)

