aprovados = 0

while True:
    Q_port = int (input())
    if Q_port < 0:
        break
    Q_mat =  int (input ())
    NotaRedacao = float (input ())
    
    acertos_portugues = float (Q_port/50)
    acertos_matematica = float (Q_mat/35)
    if ((acertos_portugues >= 0.80) and (acertos_matematica >= 0.60) and (NotaRedacao >= 7.0)):
        aprovados +=1
print (aprovados)