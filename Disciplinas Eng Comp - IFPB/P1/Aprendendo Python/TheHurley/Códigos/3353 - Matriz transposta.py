lin =  int (input())
col = int (input())
Matriz = []

for i in range (lin):
    linha = []
    for j in range (col):
        elemento = int (input ())
        linha.append(elemento)
    Matriz.append(linha)
 
Trans = []   
for k in range (len (Matriz [0])):
    T_Linha = []
    for l in range (len (Matriz [0])):
        T_Linha.append (Matriz [l][k])
    Trans.append(T_Linha)    
print (Trans)