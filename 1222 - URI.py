while True:
    ent = input()
    ent = ent.split()

    N = int(ent[0])         #número de palavras
    L = int(ent[1])         #número máximo de linhas por página
    C = int(ent[2])         #número máximo de caracteres por linha

    ent = input()
    ent = ent.split()

    cursor = 0
    n_l = 0
    n_p = 0

    cursor += len(ent[0])
    if cursor >= C:
        cursor -= C
        n_l += 1
    print('n_l', n_l, 'cursor', cursor, ent[0])

    for palavra in ent[1:]:
        cursor += 1
        if cursor >= C:
            cursor -= C
            n_l += 1
        print('n_l', n_l, 'cursor', cursor, "' '")
        cursor += len(palavra)
        if cursor >= C:
            cursor -= C
            n_l += 1
        print('n_l', n_l, 'cursor', cursor, palavra)

    if cursor > 0:
        n_l += 1

    if n_l%L == 0:
        n_p = (n_l//L)
    else:
        n_p = (n_l//L) + 1

    print(n_p)
