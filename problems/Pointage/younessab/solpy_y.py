n = int(input().strip())

students = {}
for _ in range(n):
    student = input().strip().split()
    students[student[0].strip()] = student[1].strip()
freq = {}
m = int(input().strip())
while(m):
    m-=1
    arr = [i for i in input().strip().split()]
    for i in range(1,len(arr)):
        if arr[i].strip() in freq:
            freq[arr[i].strip()]+=1
        else:
            freq[arr[i].strip()]=1
    

mx =0
if len(list(freq.values()))>0:
    mx = max(list(freq.values()))
names = []

for name in freq:
    if freq[name] == mx:
        names.append(students[name])

names.sort()
if mx>0:
    for name in names:
        print(name)
else:
    print("Something is very wrong")