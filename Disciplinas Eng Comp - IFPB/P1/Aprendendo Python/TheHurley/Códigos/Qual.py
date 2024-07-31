n = int(input())

matriz = []
for i in range(n):
    linha = []
    linha = input().split()
    linha = list(map(int,linha))
    matriz.append(linha)


for i in range(1,n):
    for j in range(1,n):
        test = matriz[i][j-1] + matriz[i-1][j-1] + matriz[i-1][j]
        if test >= 2:
            matriz[i][j] = 0
        else:
            matriz[i][j] = 1

print(matriz[n-1][n-1])

