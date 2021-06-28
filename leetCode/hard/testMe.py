import random
import numpy as np

def giveMe(lst1):
    lst2 = random.sample(lst1, 50)
    lst3 = random.sample(lst1, 50)
    return lst2, lst3

if __name__ == '__main__':
    lst2, lst3 = giveMe([random.randint(1, 100) for i in range(100)])
    lst1 = lst2 + lst3
    lst1.sort()
    lst2.sort()
    lst3.sort()
    print("MEDIANAS: ")
    print(np.median(np.array(lst1)), np.median(np.array(lst2)), np.median(np.array(lst3)))
    print("COMPLETE LIST: ")
    print(lst1, lst2, lst3)
