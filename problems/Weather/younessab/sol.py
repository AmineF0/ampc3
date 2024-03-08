mod=1000000007

def matrixMultiplication(a, b):
    n = len(a)
    c = [[0]*n for i in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                c[i][j] =(c[i][j]%mod+ (a[i][k]%mod * b[k][j]%mod)%mod)%mod
    return c

def matrixPower(a, p):
    n = len(a)
    res = [[0]*n for i in range(n)]
    for i in range(n):
        res[i][i] = 1
    while p:
        if p & 1:
            res = matrixMultiplication(res, a)
        a = matrixMultiplication(a, a)
        p >>= 1
    return res


t=int(input())
while t:
    t-=1
    x0,y0,z0,n = [int(i) for i in input().strip().split()]
    a = [[6,5,1,5],[1,1,0,7],[1,0,1,1],[0,0,0,1]]
    res = matrixPower(a, n)
    print((res[0][0]*x0%mod+res[0][1]*y0%mod+res[0][2]*z0%mod+res[0][3])%mod)
