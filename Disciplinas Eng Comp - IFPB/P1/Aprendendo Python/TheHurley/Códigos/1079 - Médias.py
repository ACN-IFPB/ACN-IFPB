n1 = 0
n2 = 0
n3 = 0
p1 = 0
p2 = 0
p3 = 0



media = 0.0

opcao = input()

if not ( opcao == 'a' or opcao == 'p' or opcao == 'h'):
    print ("Escolha um tipo de media valida.")
else:
    if opcao == 'a':
        n1 = int (input ())
        n2 = int (input ())
        n3 = int (input ())
        media =  float ((n1+n2+n3)/3)
        print ("%.2f" %media)
        if 70 <= media <=100:
            print ("Aprovado")
        elif 40 <= media < 70:
            print ("Final")
        else:
            print ("Reprovado")

    elif opcao =='p':
        n1 = int (input ())
        n2 = int (input ())
        n3 = int (input ())
        p1 = int (input ())
        p2 = int (input ())
        p3 = int (input ())
        
        media = float ((n1*p1) + (n2*p2) + (n3*p3))/(p1+p2+p3)
        print ("%.2f" %media)
        
        if 70 <= media <=100:
            print ("Aprovado")
        elif 40 <= media < 70:
            print ("Final")
        else:
            print ("Reprovado")
    else:
        n1 = int (input ())
        n2 = int (input ())
        n3 = int (input ())
        media = float (3/(1/n1 + 1/n2 + 1/n3))
        print ("%.2f" %media)
        
        if 70 <= media <=100:
            print ("Aprovado")
        elif 40 <= media < 70:
            print ("Final")
        else:
            print ("Reprovado")