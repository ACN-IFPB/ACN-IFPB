divida = int (input())
prestacao = int (input())

while (divida > 0):
    print ("(antes) %d" %divida)
    if (divida <= prestacao):
        divida = 0 
    else:
        divida = divida - prestacao
    print ("(depois) %d" %divida)