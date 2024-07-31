N = int(input())

while ( N != -1):
    div = 0
    for i in range(1, N+1):
        if N % i == 0:
            div = div + 1
    if div != 2:
      print("0")
    else:
      print("1")
    N = int (input())

  