tipo = input().upper()
limiar = int(input())
ordem = int(input())
matriz = []
for i in range(ordem):
    linha = []
    linha = input().split()
    linha = list(map(int,linha))
    matriz.append(linha)



if tipo == "ACIMA":
    soma = 0
    for i in range(ordem): 
        for j in range(i+1,ordem): 
            soma += matriz[i][j]
else:
    soma = 0
    for i in range(1,ordem):
        for j in range(0,i):
            soma += matriz[i][j]

if soma > limiar :
    print("True")
else:
    print("False")
    