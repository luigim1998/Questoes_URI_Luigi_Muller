casos = int(input())

for i in range(casos):
    entrada = [int(i) for i in input().split()]

    num1 = entrada[0]
    num2 = entrada[1]

    while(num1 != num2):
        if(num1 < num2):
            num2 -= num1
        else:
            num1 -= num2
    print(num1)
