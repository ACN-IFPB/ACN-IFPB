idade = int ( input ())
jogo = input ()

if (idade >= 0 and idade <= 130):
    if (jogo == "azar" or jogo == "mmorpg" or jogo == "moba" or jogo == "casual"):
        if (jogo != "casual"):
            if (idade >= 21 and jogo == "azar"):
                print ("Pode entrar!")
            elif (idade >= 14 and jogo == "mmorpg"):
                print ("Pode entrar!")
            elif (idade >=10 and jogo == "moba"):
                print ("Pode entrar!")
            else: print ("Volte daqui h� alguns anos.")
        else: print ("Pode entrar!")
    else: print ("Jogo invalido.")
else:    print ("Idade invalida.")


