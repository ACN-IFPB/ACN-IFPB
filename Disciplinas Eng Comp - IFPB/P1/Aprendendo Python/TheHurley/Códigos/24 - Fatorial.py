while True :
    Fatorial = 1
    N = int (input())
        
    if N == -1:
        break
    while N > 1:
        Fatorial = Fatorial * N
        N = N - 1
    print (Fatorial)