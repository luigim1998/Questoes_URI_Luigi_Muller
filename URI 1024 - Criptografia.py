import string as s

num = int(input())

for j in range(num):
    texto = input()
    texto_aux = ''
    
    for k in texto:
        if k in s.ascii_letters:
            texto_aux = chr(ord(k) + 3) + texto_aux
        else:
            texto_aux = k + texto_aux
            
    texto = texto_aux[:(len(texto_aux)//2)]
    
    for k in texto_aux[(len(texto_aux)//2):]:
        texto = texto + chr(ord(k) - 1)
    
    print(texto)
