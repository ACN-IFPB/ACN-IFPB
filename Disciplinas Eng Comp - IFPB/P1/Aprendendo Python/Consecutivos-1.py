N = int(input())
 array = input().split()
 array = list(map(int, array))

aux =  array[0]
count = 1
 array2 = []
for j in range(1,n):
  if aux ==  array[j]:
    cont += 1
  else:
     array2.append(cont)
    aux =  array[j]
    count = 1
    
 array2.append(count)
print(max( array2))

    
