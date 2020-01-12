import numpy as np
import random

limit = 50
show = 20

all = [i for i in range(1,limit+1)]


while len(all) > 1:

    temp = []

    while len(temp) <= show:
        
        x = random.choice(all[:len(all)//2])
        y = random.randint(1,limit)

        if x not in temp:
            temp.append(x)
        elif y not in temp:
            temp.append(y)

    temp.sort()

    print(temp)

    check = bool(int(input()))

    if not check:
        all = [i for i in all if i not in temp]
    else:
        all = [x for x in all if x in temp] 

    print(all)