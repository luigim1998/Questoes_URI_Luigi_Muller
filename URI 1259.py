casos = int(input())

pares = []
impares = []

for i in range(casos):

    entrada = int(input())

    if(entrada % 2 == 0):
        pares.append(entrada)
    else:
        impares.append(entrada)

pares.sort()
impares.sort()

for i in pares:
    print(i)

for i in range(len(impares) - 1, 0 - 1, -1):
    print(impares[i])
