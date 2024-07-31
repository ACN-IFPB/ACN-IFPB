string = ''
string = input()

#funcao_testar

def testestring (entrada):
    if len(entrada) == 0:
        return False
    if entrada.isdigit == True:
        return False

#funcao_converter
def conversor (nome):
    nome = nome.lower()
    nome = nome.replace ('a', '@')
    nome = nome.replace ('e', '3')
    nome = nome.replace ('i', '1')
    nome = nome.replace ('o', '0')
    nome = nome.replace ('t', '7')
    nome = nome.replace ('s', '5')
    return nome

#func�o_inverter
def inverter_texto (texto):
    return texto[::-1]

if testestring (string) != False:
    #conversor (string)
    print (inverter_texto (conversor(string)))
    
else:
    print ("numeros")
    print (0)