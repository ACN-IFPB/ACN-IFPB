matriz = [[3,2,5], [1,6,7], [4,10,9]]

for i in range (3):
    for j in range (3):
	    if i != 0:
	           matriz [i][j] += matriz[i-1][j]
	           

print(matriz [2][1])

