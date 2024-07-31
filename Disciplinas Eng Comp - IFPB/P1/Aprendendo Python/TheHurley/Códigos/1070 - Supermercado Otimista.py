dia = input()
preco = float(input())
opcao = input()
produto = input()

if (dia == "seg" or dia == "ter" or dia == "qua") and opcao == "ouro":
    preco = preco/2
elif (dia == "qui" or dia == "sex") and (preco >= 10 and preco <= 100):
    preco = preco/3
elif dia == "sab" and opcao == "prata":
    preco = preco*3
else:
    preco = preco*2


print("O preco do produto %s no dia %s eh %.2f"%(produto,dia,preco))