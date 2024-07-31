'''
SIMPLES PROGRAMA V0.1 EM PYTHON PARA GERAR NÚMEROS DA MEGA SENA
UM SALVE PRA TIO SOKA E TODO MUNDO DA FAMÍLIA POKEMON GO
'''
import random
aposta = [] #lista para receber os numeros da aposta
for i in range (0,6): #aposta mínima de 6 números
    aposta.append(random.randint(1, 60)) #randint gera numeros no intervalo definido

aposta.sort() #organizando a aposta em ordem crescente
print (aposta)

