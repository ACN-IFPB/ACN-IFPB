n = int (input())

if 1 <= n <= 40:
    for x in range (1, n+1, 1):
        for m in range (1, x+1,1):
            if m == x:
                print(m)
            else:
                print (m, end=" ")