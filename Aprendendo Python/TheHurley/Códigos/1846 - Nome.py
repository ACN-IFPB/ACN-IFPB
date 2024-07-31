string = input().upper()
cont = 0

for cont in range(0,len(string)+1,1):
    for i in range(0,cont,1):
        print(string[i], end="")
    print ()
    cont +=1
    