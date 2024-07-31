I = int (input ())
F = int (input ())


if ((I > 0 and I < 25) and (F > 0 and F < 25)):
    if (F < I):
        print ("Eu odeio a professora!")
    elif (I <= F - 3):
        print ("Muito bem! No prazo!")
    else:
        print ("Parece o trabalho do meu filho!")
        if (F+2 <= 24):
            print ("Trabalho Apresentado!")
        else:
            print ("Voce falhou! Ate a proxima!")
