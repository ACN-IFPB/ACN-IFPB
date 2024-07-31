N = int(input())
array = input().split()

aux = array [0]
count = 1

array2 = []

for j in range(1,N):
  if aux == array[j]:
    count += 1
  else:
    array2.append(count)
    aux = array[j]
    count = 1
    
array2.append(count)
print(max(array2))

    
