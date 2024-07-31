PSNR = float(input())
anal = str(input())
expo = str(input())

if (80 <= PSNR <= 90):
    if (anal == "bom" or anal == "excelente"):
        if (expo == "bem exposta"):
            print("para imprimir")
        else:
            print("boa")
    else:
        print("marromeno")

elif (PSNR >=50 and PSNR < 80):
    if (anal == "excelente"):
        if (expo == "bem exposta"):
            print("boa")
    else:
        print("marromeno")

elif (PSNR < 50):
    if (anal == "excelente"):
        if (expo == "bem exposta"):
            print("marromeno")
        else:
            print("lixo")
    else:
        print("lixo")