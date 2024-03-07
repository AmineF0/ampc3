t=int(input())

while t:
    t-=1
    n=int(input())
    a=sum(list(map(int,input().split())))
    b=sum(list(map(int,input().split())))
    if a>b:
        print(0)
    elif a<b:
        print(1)
    else:
        print(-1)