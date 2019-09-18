casos = int(input())

while(casos != 0):
    for i in range(casos):
        entrada = int(input())
        if(entrada % 2 == 1):
            print( (entrada-1)*2 + 1 )
        else:
            print( (entrada-2)*2 + 2 )
    casos = int(input())
