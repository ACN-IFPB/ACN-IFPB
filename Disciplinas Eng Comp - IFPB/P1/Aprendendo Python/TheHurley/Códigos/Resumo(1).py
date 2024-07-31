pi = 3.14

circulo = []
quadrado = []
retangulo = []

def menu ():
    op = input ("Escolha o Tipo da figura:\n (q)uadrado,\n (r)et�ngulo,\n (c)�rculo \nsair \n").lower()
    return op
    
def quad ():
    l =  float (input())
    if l != -1:  
        return l*l 
    else:
        return -1
def cir ():
    r = float (input())
    if r == -1:
        return -1
    else:
        return 2*pi*r,
def ret ():
    a =  float (input())
    b = float (input())
    if a != -1 and b != -1:
        return a*b
    else:
        return -1


while True:
    escolha = (menu ())
    if escolha == "r":
        retangulo.append (ret())
    elif escolha == "q":
        quadrado.append(quad())
    elif escolha == "c":
        circulo.append(cir())
    else:
        print("Maior circulo: %.2f" %max(circulo))
        print("Maior retangulo: %.2f" %max(retangulo))
        print("Maior quadrado: %.2f"  %max(quadrado))
        print("Quantidade de figuras %d" %(len(circulo)+len(retangulo)+len(quadrado)))
        print("Percentual de circulos: %.2f" %((len(circulo) / (len(circulo)+len(retangulo)+len(quadrado))) * 100))
        break
    

