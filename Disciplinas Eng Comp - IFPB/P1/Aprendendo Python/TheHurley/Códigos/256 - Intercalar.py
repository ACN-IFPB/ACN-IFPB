tam = int (input())

array1 = []
array2 = []

for i in range (tam):
    array1 = array1 + [input()]
    
for j in range (tam):
    array2 = array2 + [input()]
    
for k in range (tam):
    print (array1[k])
    print (array2[k])