'''
implementação de um jogo do bicho em python
'''
import random

print ("Bem vindo ao jogo do bicho, faça sua aposta\n")
print ("#condição de validade da aposta, valores entre 00 e 99\n")
aposta = int(input())
sorteio = random.randint(0,99)


if aposta == sorteio:
    print (sorteio)

avestruz = [1,2,3,4]
aguia = [5,6,7,8]
burro = [9,10,11,12]
borboleta = [13,14,15,16]
cachorro = [17,18,19,20]
cabra = [21,22,23,24]
carneiro = [25,26,27,28]
camelo = [29,30,31,32]
cobra = [33,34,35,36]
coelho = [37,38,39,40]
cavalo = [41,42,43,44]
elefante = [45,46,47,48]
galo = [49, 50, 51,52]
gato = [53, 54, 55, 56]
jacare = [57,58,59,60]
leao = [61,62, 63, 64]
macaco = [65,66,67,68]
porco = [69, 70, 71, 72]
pavao = [73,74, 75, 76]
peru = [77,78,79,80]
touro = [81,82,83,84]
tigre = [85,86,87,88]
urso = [89,90,91,92]
veado = [93,94,95,96]
vaca = [97,98,99, 00]

jogo = [avestruz, aguia , burro , borboleta , cachorro , cabra , carneiro , camelo , cobra , coelho , cavalo , elefante , galo , gato , jacare , leao , macaco , porco  , pavao  , peru  , touro  , tigre , urso , veado  , vaca  ]

for i in jogo:
    for j in i:
        if sorteio == j:
            print ("Parabéns, A aposta foi %d", sorteio)
            break  
    print ("Infelizmente não deu, tente novamente. A aposta foi %d" %sorteio)
    break
            
