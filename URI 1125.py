entrada = input().split()

corridas = int(entrada[0])
pilotos = int(entrada[1])

while(corridas != 0 and pilotos != 0):
    podios = []
    for i in range(corridas):
        entrada = input().split()
        entrada = [int(j) for j in entrada]
        podios.append(entrada)

    sistemas = int(input())

    for i in range(sistemas):
        pontuacao = pilotos*[0]

        entrada = input().split()
        entrada = [int(j) for j in entrada[1:]]

        for j in range(corridas):
            for k in range(pilotos):
                if(podios[j][k] <= len(entrada)):
                    pontuacao[k] += entrada[podios[j][k] - 1]
        maximum = max(pontuacao)
        champs = []
        for j in range(len(pontuacao)):
            if(pontuacao[j] == maximum):
                champs.append(j+1)
        print(champs[0], end='')
        for j in range(1, len(champs)):
            print(" " + str(champs[j]), end='')
        print()

    entrada = input().split()

    corridas = int(entrada[0])
    pilotos = int(entrada[1])
