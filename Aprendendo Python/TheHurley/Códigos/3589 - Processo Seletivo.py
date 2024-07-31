aprovados = 0
candidatos = 0
mulheres = 0
homens = 0

while True:
    objetiva = int (input())

    if  objetiva < 0:
        break
    while objetiva > 100:
        print ("Digite uma nota inferior a 100.")
        objetiva = int (input ())
    NotaRedacao = int(input ())
    while NotaRedacao > 100 :
        print ("Digite uma nota inferior a 100.")
        NotaRedacao = int (input())
        
    sexo = input ()
    candidatos +=1
    media = (objetiva + NotaRedacao)/2
    
    if ((media >= 60) and (objetiva > 40) and (NotaRedacao > 40)):
        aprovados +=1
        if (sexo == "F"):
            mulheres +=1
        else:
            homens +=1
        
print ("%d candidato(s) inscrito(s)." %candidatos)
print ("%d candidato(s) aprovado(s)." %aprovados)
print ("%d mulher(es) e %d homem(ns)."%(mulheres, homens))