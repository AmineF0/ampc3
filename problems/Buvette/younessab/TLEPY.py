t = int(input())
while t>0:
    t-=1
    n,m = [int(i) for i in input().strip().split()]
    items=[]
    for i in range(n):
        items.append([i for i in input().strip().split()])
    ans=0
    for i in range(m):
        a,b=[ k for k in input().strip().split()]
        for j in range(n):
            if items[j][0]==a:
                ans+=int(b)*float(items[j][1])

    print(ans)