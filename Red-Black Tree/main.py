from RBTree import RBTree
import random
import time


def main() -> None:
    rbt = RBTree()

    # l = [-15, -6, 1, 2, 18, 17, 3, 12, -9, -4, -10]
    l = [17, 25, 6, 3, 1, 8, 36, 4, 12, 39, 30, 28, 0, 24]

    t = time.time()
    for i in range(1000000):
        rbt.add(i)

    print(time.time() - t)
    pass


if __name__ == "__main__":
    main()
