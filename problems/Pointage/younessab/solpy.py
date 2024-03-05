n,m=[int(i) for i in input().strip().split()]

students = {}
for _ in range(n):
    student = input().strip().split()
    students[student[0]] = student[1:]
freq = {}
while(m):
    m-=1
    student = input().strip()
    if student in students:
        if student in freq:
            freq[student] += 1
        else:
            freq[student] = 1

mx = max(freq.values())
names = []
for name in freq:
    if freq[name] == mx:
        names.append(name)
names.sort()
if len(names) > 1:
    for name in names:
        print(name)
else:
    print("Something is very wrong")