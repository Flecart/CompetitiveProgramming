import math

a = sum([int(i) for i in input().split(' ')])
b = sum([int(i) for i in input().split(' ')])
shelves = int(input()) - math.ceil(a / 5) - math.ceil(b / 10)


if shelves >= 0:
    print("YES")
else:
    print("NO")