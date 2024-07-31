#questão 1
import math

print ("Calcula distancia entre dois pontos\n\n")
print ("entre com as coordenadas do ponto A ")
XA = int (input ("coordenada XA\n"))
YA = int (input ("coordenada YA\n"))

print ("entre com as coordenadas do ponto B \n")
XB = int (input ("coordenada XB\n"))
YB = int (input ("coordenada YB\n"))

distancia = 0.0

distancia = math.sqrt( (XB - XA)**2 + (YB-YA)**2)

print ("A distancia entre Os Ponto B e A eh: %2f", distancia)

