array = []
N = int (input())
media = 0
soma = 0

if N == 0:
    print ("Numero de notas invalido.")
else:
    for i in range (0,N,1):
        array.append(float(input()))
        soma = soma + array [i]
        print("Nota %d: %.1f" %(i+1, array[i]))
    media = soma/(len(array))
    print("Media: %.2f" %media)
