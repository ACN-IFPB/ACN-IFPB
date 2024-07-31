num = int(input())
i = 1
x = 0

if num < 6:
    print("Falso")
else:
    while x < num:
        x = i*(i+1)*(i+2)
        if x != num:
            i +=1

    if x == num:
        print("%d * %d * %d = %d" %(i, (i+1), (i+2), x))
        print ("Verdadeiro")
    else:
        print("Falso")