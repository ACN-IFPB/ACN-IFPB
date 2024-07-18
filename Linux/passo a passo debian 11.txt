#!/bin/bash

#script pós instalação debian 11 acer aspire 3 A315-23g-r759
#isso é um guia basico + passo a passo para orientar a instalação
#adicionar repositório no source list ou no synaptic
#lembrando que a wifi e o cabo de rede não foram reconhecidos automaticamente
#eu estou usando um adaptador wifi-usb edimax

#atualizar o sistema

apt update && apt upgrade -y
######## placa de video
lspci -nnk | grep -i -EA3 "3d|display|vga"

xrandr

sudo apt-get update
sudo apt-get dist-upgrade

sudo apt-get install xserver-xorg-video-ati -y
sudo apt-get install xserver-xorg-video-amdgpu -y

#sudo nano /etc/apt/sources.list
#(main contrib non-free)

#sudo apt-get update

sudo apt-get install firmware-amd-graphics libgl1-mesa-dri -y
######3

#instalar o sudo
apt install sudo -y

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
#Se você está utilizando um notebook/netbook e quer instalar o TLP no seu Debian Bullseye, 
#basta executar o comando abaixo:

apt install tlp tlp-rdw -y
#e depois 

systemctl enable tlp && tlp start -
 
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
apt install telegram-desktop

#instalando o google chrome
#repositorio oficial

sudo sh -c 'echo "deb [arch=amd64] http://dl.google.com/linux/chrome/deb/ stable main" >> /etc/apt/sources.list.d/google.list'


#baixando a chave

wget -q -O - https://dl.google.com/linux/linux_signing_key.pub | sudo apt-key add -

#enfim a instalação
apt update && apt install google-chrome-stable -y
 
#instalando o edge

apt install curl -y

curl https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > microsoft.gpg
sudo install -o root -g root -m 644 microsoft.gpg /etc/apt/trusted.gpg.d/

sudo sh -c 'echo "deb [arch=amd64] https://packages.microsoft.com/repos/edge stable main" > /etc/apt/sources.list.d/microsoft-edge-dev.list'
sudo rm microsoft.gpg

sudo apt update

sudo apt install microsoft-edge-dev -y


#programação e desenvolvimento

apt clean
apt autoclean


apt update 

#instalacao do adb

sudo apt install android-tools-adb android-tools-fastboot

#instalar o python 3
apt-get install python3 -y


#instalar o gcc

apt install build-essential make libssl-dev libghc-zlib-dev libcurl4-gnutls-dev libexpat1-dev gettext unzip -y


#instalar o git

cd /tmp/

wget https://github.com/git/git/archive/refs/tags/v2.33.0.zip -O git.zip

unzip git.zip

cd git-*

make prefix=/usr/local all
make prefix=/usr/local install

#instalar o pycharm

#instalar o VScodium

wget -qO - https://gitlab.com/paulcarroty/vscodium-deb-rpm-repo/raw/master/pub.gpg | sudo apt-key add -

echo 'deb https://gitlab.com/paulcarroty/vscodium-deb-rpm-repo/raw/repos/debs/ vscodium main' | sudo tee --append /etc/apt/sources.list.d/vscodium.list

apt update && apt install vscodium -y


#instalar o JRE (Java Runtime Environment) no seu sistema:

apt-get install default-jre -y

#instalar JDK (Java Development Kit) no seu sistema

sudo sh -c "echo 'deb http://ppa.launchpad.net/linuxuprising/java/ubuntu bionic main' >> /etc/apt/sources.list" 

sudo sh -c "echo 'deb-src http://ppa.launchpad.net/linuxuprising/java/ubuntu bionic main' >> /etc/apt/sources.list" 

sudo apt-get install dirmngr

sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys EEA14886

sudo apt-get update
sudo apt-get install oracle-java11-installer -y

apt-get install default-jdk

#instalação do wine pra rodar jogos antigos

sudo sh -c 'echo " deb https://dl.winehq.org/wine-builds/debian/ bullseye main" >> /etc/apt/sources.list.d/wine.list'

wget -nc https://dl.winehq.org/wine-builds/winehq.key

sudo apt-key add winehq.key


sudo dpkg --add-architecture i386

sudo apt install --install-recommends winehq-stable 


#baseado em :
#https://www.blogopcaolinux.com.br/2021/09/Guia-pos-instalacao-Debian-11-Bullseye.html#sources

#https://linuxconfig.org/how-to-install-the-latest-amd-drivers-on-debian-10-buster


