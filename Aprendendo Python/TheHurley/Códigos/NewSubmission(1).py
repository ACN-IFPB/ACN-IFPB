 
from datetime import datetime
#validardatas 
def Validar_Datas(data):
    data = data.split("/")
    dia = data[0]
    mes = data[1] 
    ano = data [2]
    
    valida = False
    if  ('01' <= dia <= '31') and ( '01' <= mes <= '12')  and  (ano > '0001') :
        count = 0

        if int(ano) % 4 == 0 and mes == '02':
            if dia <= '29':
                count += 1
                return True
            else:
                return False
       
        else:
            print ("Data invalida")
            
        if( mes =='01' or mes == '03' or mes =='05' or mes =='07' or mes == '08' or mes == '10' or mes == '12'):
            if(dia <= 31):
                valida = True
            else:
                valida = False
            
    # Meses com 30 dias
        elif( mes == '04' or mes == '06' or mes == '09' or mes == '11'):
            if(dia <= 30):
                valida = True
            
    if(valida):
        return dia, mes, ano
    else:
        print('Data Invalida')
     

#custoporkilometro
Valor_kilometro = 0.30

#veridicar modelo de carro
def modelo (carro):
    carro = input().lower()
    if carro == 'b':
        return 30.0
    elif carro == 'i':
        return 40.0
    elif carro == 'p':
        return 60.0
    else:
        print ('Modelo de carro invalido')
        
def Qtd_kilometros (km):
    distancia = input().split(' ')
    dst_inicio = distancia [0]
    dst_final = distancia [1]
    valor = dst_final - dst_inicio
    if valor > 0:
        return valor
    else:
        print('Valores do odometro com erro')


def data_saida ():
    saida = input()
    
    return Validar_Datas (saida)

def data_devolucao ():
    devolucao = input()
    return Validar_Datas (devolucao)
    
def dias_locado():
    tempo1 = datetime.date(day=dia_saida, month=mes_saida, year=ano_saida)    
    tempo2 = datetime.date(day=dia_entrega, month=mes_entrega, year=ano_entrega)    
    dias_ocupado = tempo2 - tempo1    
    return  dias_ocupado


#func�o principal

while True:
    carro = input().upper()
    if carro == 'FIM':
        break
    else:
        valor_locacao = (modelo(carro) * dias_locado(data_saida(), data_devolucao()) + Valor_kilometro() * Qtd_kilometros())
