#uso estrutura elif em python

categoria = int (input ("Entre com a sua categoria: \n"))

if categoria == 1:
    preço = 10
elif categoria == 2:
    preço = 18
elif categoria == 3:
    preço = 23
elif categoria == 4:
    preço = 26
elif categoria == 5:
    preço = 31
else:
    print ("Categoria Invalida entre com um número entre 1 e 5.\n")
    preço = 0
print ("o preço do produto é: %6.2f" %preço)