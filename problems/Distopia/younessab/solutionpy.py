t=int(input())
while t>0:
    t-=1
    n=int(input())
    nums = [int(x) for x in input().strip().split()]
    acc1 = [0]*32
    acc0 = [0]*32
    for i in range(n):
        for j in range(32):
            if nums[i] & (1<<j):
                acc1[j]+=1
            else:
                acc0[j]+=1
    ans = 0
    for j in range(32):
        if acc1[j]>=acc0[j]:
            ans+=(1<<j)
    print(ans)