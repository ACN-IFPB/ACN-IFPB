'''
Este código é do "@pycodebr" eu apenas reproduzo para fins de
teste/conhecimento/educativo.
https://linktr.ee/pycodebr
https://github.com/pycodebr
'''
'''
#PARA CAPTURAR INFORMAÇÕES DO PC COM PYTHON É NECESSÁRIO INSTALAR O WMI

#pip install wmi

#Importando a biblioteca
import wmi


#carregando infomrações
c = wmi.WMI()
my_system = c.Win32_ComputerSystem ()[0]

#exibe resultados
print (f"Marca: {my_system.Manufacture}")
print (f"Modelo: {my_system.Model}")
print (f"Nome: {my_system.Name}")
print (f"Quantidades de CPUs: {my_system.NumberOfProcessors}")
print (f"Arquitetura: {my_system.SystemType}")
print (f"Família: {my_system.SystemFamily}")

'''

 # retirado de https://acervolima.com/obtenha-as-informacoes-do-seu-sistema-usando-o-script-python/
 
import platform
 
Meu_Systema = platform.uname()
 
print(f"Sistema: {Meu_Systema.system}")
print(f"Nome do Computador: {Meu_Systema.node}")
print(f"Release: {Meu_Systema.release}")
print(f"Version: {Meu_Systema.version}")
print(f"arquitetura: {Meu_Systema.machine}")
print(f"Processador: {Meu_Systema.processor}")
