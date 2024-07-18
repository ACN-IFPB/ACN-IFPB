#!/bin/bash

#script pós instalação debian 11 acer aspire 3 A315-23g-r759
#isso é um guia basico + passo a passo para orientar a instalação
#adicionar repositório no source list ou no synaptic
#lembrando que a wifi e o cabo de rede não foram reconhecidos automaticamente
#eu estou usando um adaptador wifi-usb edimax
#atualizar o sistema

apt update && apt upgrade -y

#instalando o curl

apt install curl -y

#instalação dos drivers de rede
#instalação do microcódigo (semelhante a um "firmware") amd64-microcode (para processadores #AMD®). Estes pacotes (disponíveis no repositório non-free) contém correções de erros e de #falhas de segurança dos fabricantes, garantindo maior estabilidade ao seu Debian.
#Se você usa um processador da AMD®:

apt install amd64-microcode -y

#instalação dos drivers amd e suporte a placa de video

apt install firmware-linux firmware-linux-nonfree libdrm-amdgpu1 xserver-xorg-video-amdgpu -y

#instalação do vulkan
apt install mesa-vulkan-drivers libvulkan1 vulkan-tools vulkan-utils vulkan-validationlayers -y

#instalação do Open-Gl
apt install mesa-opencl-icd -y




#otiminizador de bateria do notebook
#Se você está utilizando um notebook/netbook e quer instalar o TLP no seu Debian Bullseye, #basta executar o comando abaixo:

apt install tlp tlp-rdw -y
#e depois 

systemctl enable tlp && tlp start&
 
#utilitarios

#compactadores de arquivos
apt install arc arj cabextract lhasa p7zip p7zip-full p7zip-rar rar unrar unace unzip xz-utils zip -y

#gparted 
#até hoje não entendo o porque ele não fica instalado na máquinas mas enfim:

apt install gparted -y

#codecs
apt install faad ffmpeg gstreamer1.0-fdkaac gstreamer1.0-libav gstreamer1.0-vaapi gstreamer1.0-plugins-bad gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-ugly lame libavcodec-extra libavcodec-extra58 libavdevice58 libgstreamer1.0-0 sox twolame vorbis-tools -y

#vlc

apt install vlc -y

#install PDFSam (separar e unir pdf)

#instalar um visualizador de PDF


#free download manager
#https://www.freedownloadmanager.org/pt/download-fdm-for-linux.htm


#Telegram 
apt install telegram-desktop -y

#instalando o google chrome
#repositorio oficial

echo "deb [arch=amd64] http://dl.google.com/linux/chrome/deb/ stable main" | tee /etc/apt/sources.list.d/google-chrome.list

#baixando a chave

cd /tmp && wget -q -O - https://dl.google.com/linux/linux_signing_key.pub | apt-key add - && cd ..

#enfim a instalação
apt update && apt install google-chrome-stable -y


#programação e desenvolvimento

#instalar o python 3
apt-get install python3 -y


#instalar o gcc

#instalar o git

#instalar o pycharm

#instalar o VScode

#instalar o JRE (Java Runtime Environment) no seu sistema:

#apt-get install default-jre

#instalar JDK (Java Development Kit) no seu sistema

#apt-get install default-jdk





#baseado em :
#https://www.blogopcaolinux.com.br/2021/09/Guia-pos-instalacao-Debian-11-Bullseye.html#sources

#https://linuxconfig.org/how-to-install-the-latest-amd-drivers-on-debian-10-buster


