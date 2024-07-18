#pilha.py
''' pequeno teste de implementação de pilhas em python'''

ultimo = 5
pilha = list (range (1, ultimo +1)) #adicionar um número na pilha

while True:
    print ("\n Existem %d pratos na pilha" %len(pilha))
    print ("pilha atual: \n", pilha)
    print ("Digite F para adicionar um prato ao fim da pilha\n A para realizar o atendimento.\n S para sair.\n")
    escolha = input ("Escolha F, A ou S:\n")

    if escolha == "A":
        if len(pilha) >0:
            prato = pilha.pop(-1) #adiciona um prato no topo da pilha
            print (" %d pratos empilhados", prato)
        else:
            print ("pilha vazia, sem pratos!")
    elif escolha == "F":
        ultimo +=1 #incremtenta o índice dos pratos
        pilha.append(ultimo) #adiciona um prato ao final da pilha
    elif escolha == "S":
        break
    else:
        print ("Opção inválida")

    

