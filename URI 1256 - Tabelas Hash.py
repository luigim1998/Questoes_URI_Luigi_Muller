casos = int(input())

tabela = [[]]*casos

for i in range(casos):
    entrada   = input()
    entrada   = [int(j) for j in entrada]
    enderecos = entrada[0]
    chaves    = entrada[1]
    entrada   = input()
    entrada   = [int(j) for j in entrada]
    