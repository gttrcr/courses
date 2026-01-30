import math
import random


def hash(s: int) -> int:
    return 0


if __name__ == "__main__":
    collision = {}

    # execute 1000 tests
    for _ in range(1000):
        num = random.randint(0, 2**32 - 1)
        h = hash(num)
        if h not in collision:
            collision[h] = 0
        collision[h] += 1

    # print collisions
    for key, value in list(collision.items())[:10]:
        print(f"{key}\t{value}")

    # print probabilities
    s = sum(collision.values())
    l = list(map(lambda x: x / s, collision.values()))
    collision = dict(zip(list(collision), l))
    for key, value in list(collision.items())[:10]:
        print(f"{key}\t{value}")

    # compute entropy
    h = list(map(lambda x: -x * math.log(x) if x != 0 else 0, collision.values()))
    H = sum(h)
    print(H)
