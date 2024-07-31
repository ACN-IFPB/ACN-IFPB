print("Teste porta OR")


a = int (input ("Entre com o valor A, escolha apenas 0 ou 1\n"))
b = int (input ("Entre com o valor B, escolha apenas 0 ou 1\n"))

if (a == b and a == 1):
    print (" Os Valores são iguais! e a porta deu 1 na saída\n")
else: print ("Os valores são iguais porém a porta deu 0 na saída!\n")

if ((a == 0 and b == 1) or (a == 1 and b ==0)):
    print (" Os Valores são diferentes, porém a porta deu 1 na saída\n")
    

