while True:
    n = int(input())
    if n == 0:
        break
    matriz = [ [" "]*4 for i in range(4) ]
    for i in range(4):
        linha = []
        for j in range(4):
            matriz[j][i]= int(input())
    for i in range(4):
        matriz[i][i] *= n
    
    for i in matriz:
        for j in i:
            print(j, end = ' ')
        print()