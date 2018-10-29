i = int(input())
for cont in range(0, i):
    text = input().split()
    
    for j in range(len(text)-1, 0-1, -1):
        for k in range(0, j):
            if(len(text[k]) < len(text[k+1])):
                text[k],text[k+1] = text[k+1],text[k]
            
    print(text[0], end="")
    
    for j in range(1,len(text)):
        print(" %s"%(text[j]), end = "")
        
    print("")
