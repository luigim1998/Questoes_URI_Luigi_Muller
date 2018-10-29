def fatorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n*fatorial(n-1)

N = int(input())

while N != 0:
    casos = fatorial(N)/fatorial(3)
    print(int(casos))
    N = int(input())
