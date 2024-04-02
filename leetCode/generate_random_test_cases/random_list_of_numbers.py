import random

FROM_NUM = 0
TO_NUM = 5
SIZE_LST = 7

def main():
    lst1 = [random.randint(FROM_NUM,TO_NUM) for i in range(SIZE_LST)]
    lst2 = [random.randint(TO_NUM*-1,FROM_NUM*-1) for i in range(SIZE_LST)]

    lst3 = lst1+lst2
    lst3 = random.sample(lst3,SIZE_LST*2)
    print(lst3)

if __name__ == "__main__":
    main()
