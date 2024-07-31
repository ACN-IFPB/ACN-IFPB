temperatura = float (input ())
sintomas = input ()

if (sintomas == "S" or sintomas == "N" or sintomas == "s" or sintomas == "n"):
    if (temperatura >= 37):
        if (sintomas == "S" or sintomas == "s"):
            print("Exames Especiais")
        else:
            print("Exames Basicos")
    else:
        if (sintomas == "S" or sintomas == "s"):
            print("Exames Basicos")
        else:
            print("Liberado")
else:
    print ("Erro")