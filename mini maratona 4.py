def primo(primo):
    cont = 2

    if primo >= 2:
        while cont**2 <= primo:
            if primo%cont == 0:
                return False
            cont = cont + 1
        return True
    return False
    
Q = int(input())

for i in range(Q):
    cont_primos = 0
    r = input().split()
    x = int(r[0])
    y = int(r[1])

    if x == 1:
        x = 2

    for j in range(x, y+1):
        if primo(j) == True:
            if primo(j-2)==True or primo(j+2)==True:
                cont_primos = cont_primos + 1
    print(cont_primos)
