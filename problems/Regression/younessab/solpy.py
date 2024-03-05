x1,y1 = [float(i) for i in input().strip().split()]
x2,y2 = [float(i) for i in input().strip().split()]
x = float(input())
print((x-x1)*(y2-y1)/(x2-x1)+y1)