from datetime import datetime

def data_valida(data):
    try:
        datetime.strptime(data, '%d/%m/%Y')
        return True
    except ValueError:
        return False
        
def Dias_Locados(data_saida,data_devolucao):
    saida = datetime.strptime(data_saida, "%d/%m/%Y")
    devolucao = datetime.strptime(data_devolucao, "%d/%m/%Y")
    return (devolucao - saida).days

def calcularGastos(m,dias,kr):
    if m == "b":
        d = 30
    elif m == "i":
        d = 40
    else:
        d = 60
    
    total = d*dias + (0.30 * kr)
    print("%.2f"% total )

while True:
    modelo = input()
    if modelo.upper() == "FIM":
        break
    verf = "bip"
    data_saida = input()
    data_devolucao = input()
    dias = Dias_Locados(data_saida,data_devolucao)
    kms = input().split()
    kms = list(map(int,kms))
    
    
    if modelo not in verf:
        print("Modelo de carro invalido")
        continue
    elif not data_valida(data1) or not data_valida(data2):
        print("Data invalida")  
        continue    
    elif dias < 0:
        print("Data de devolucao inferior a data de locacao")
        continue
    elif kms[0] > kms[1]:
        print("Valores do odometro com erro")
        continue
    else:
        kr = (kms[1] - kms[0])
        calcularGastos(modelo,dias,kr)