'''Teste implementação passador de storys em python
utilizando a biblioteca pyautogui
como estou utilizando o navegador edge
vou selecionar o ponto exato na tela do meu notebook
fonte do tutorial: https://imasters.com.br/back-end/automacao-de-gui-com-python-exemplo-de-uso-do-pyautogui-2
'''



import pyautogui
import time 

for i in range (1,500):
    pyautogui.click(885,426)
    time.sleep (0.7)
    
