while True:
    tam = input()
    if tam == "0":
        break
    nome = input()
    string = ""
    for caractere in nome:
            string = caractere + string
    print(string)