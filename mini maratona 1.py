a = input().split()

n = int(a[0])
m = int(a[1])

walrus = 1

while m >= walrus:
    m = m - walrus
    walrus = walrus + 1

    if walrus > n:
        walrus = 1
        
print(m)
