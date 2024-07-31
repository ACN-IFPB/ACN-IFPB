#lista.py
''' pequeno teste de implementação de listas em python'''

ultimo = 5
fila = list (range (1, ultimo +1)) #adicionar um número na lista

while True:
    print ("\n Existem %d clientes na fila" %len(fila))
    print ("Fila atual: \n", fila)
    print ("Digite F para adicionar um cliente ao fim da fila\n A para realizar o atendimento.\n S para sair.\n")
    escolha = input ("Escolha F, A ou S:\n")

    if escolha == "A":
        if len(fila) >0:
            cliente = fila.pop(0)
            print ("Cliente %d atendido", cliente)
        else:
            print ("Fila vazia, sem clientes!")
    elif escolha == "F":
        ultimo +=1 #incremtenta o índice dos clientes
        fila.append(ultimo) #adiciona um cliente ao final da fila
    elif escolha == "S":
        break
    else:
        print ("Opção inválida")

    

