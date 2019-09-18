aux = input().split()

num_b = int(aux[0])
num_p = int(aux[1])

while(num_b != 0 and num_p != 0):

    clonado = 0
    bilhetes = (num_b+1)*[0]

    entradas = [int(i) for i in input().split()]

    for j in entradas:
        bilhetes[j] += 1

    for j in range(1, num_b+1):
        if(bilhetes[j] > 1):
            clonado += 1

    print(clonado)

    aux = input().split()

    num_b = int(aux[0])
    num_p = int(aux[1])
