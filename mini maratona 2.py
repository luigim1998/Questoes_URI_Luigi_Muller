def fatorial(x):
    if x == 0 or x == 1:
        return 1
    else:
        fat = 1
        for i in range(2, x+1):
            fat = fat*i
        return fat

e = input().split()

N = int(e[0])
W = int(e[1])
T = int(e[2])
R = int(e[3])

resultado = fatorial(N)/(fatorial(W)*fatorial(T)*fatorial(R))
resultado = resultado%1000000007

print( int(resultado) )
