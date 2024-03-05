t = int(input().strip())
while t > 0:
    t-=1
    n,m =[int(i) for i in input().strip().split()]
    items={}
    for _ in range(n):
        a,b=[i for i in input().strip().split()]
        items[a]=float(b)
    ans=0
    for _ in range(m):
        a,b = [i for i in input().strip().split()]
        ans+=items[a]*int(b)
    print(ans)

