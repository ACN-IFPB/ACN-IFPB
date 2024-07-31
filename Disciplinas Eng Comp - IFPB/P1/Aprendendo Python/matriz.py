matriz = []

for i in range (3):
    linha = []
    for j in range (3):
        if j % 2 == 0:
            linha.append(1)
        else:
            linha.append(0)
    matriz.append(linha)
print(matriz [2][1])