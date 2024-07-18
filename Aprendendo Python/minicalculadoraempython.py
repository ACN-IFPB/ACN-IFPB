#mini calculadora em python

#função soma
def soma ():
    print ("entre com dois números")
    a = float (input("primeira parcela: \n"))
    b = float (input ("segunda parcela: \n"))
    s = a+b
    return s 

#função subtração
def subtração ():
    print ("entre com dois números")
    a = float (input("primeira parcela: \n"))
    b = float (input ("segunda parcela: \n"))
    s = a-b
    return s 

#função multiplicação
def multiplicação ():
    print ("entre com dois números")
    m1 = float (input("primeiro multiplicador: \n"))
    m2 = float (input ("segundo multiplicador: \n"))
    total = m1 * m2
    return total

#função divisão
def divisão ():
    print ("entre com dois números")
    d1 = float (input("primeiro multiplicador: \n"))
    d2 = float (input ("segundo multiplicador: \n"))
    total = d1 / d2
    return total

#potenciação
def potenciação ():
    print ("entre com dois números")
    a = float (input("potenciando: \n"))
    b = float (input ("potencia: \n"))
    total = a^b
    return total

n = 7
while (n != 0):
    n = int (input("\n\n Entre com as seguintes opções:\n 1 - soma \n 2 - subração \n 3 - multiplicação \n 4 - divisão \n 5 - potenciação \n 0 - sair\n"))
    if n == 1:
        print (soma () "\n\n")
    elif n == 2:
        print (subtração ()"\n\n")
    elif n == 3:
        print (multiplicação ()"\n\n")
    elif n == 4:
        print (divisão ()"\n\n")
    elif n == 5:
        print (potenciação()"\n\n")
    elif n == 6:
        break
    else:
        n = int (input ("\n opção inválida entre com qualquer valor entre 1 e 6\n"))
