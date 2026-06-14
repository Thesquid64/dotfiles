sudo xbps-install -u xbps
sudo xbps-install -Syu
sudo xbps-install vim neovim git firefox alacritty picom fzf sddm btop kew feh pfetch libqalculate rofi krita pavucontrol scrcpy onboard virt-manager qemu wget xorg-minimal make gcc libX11-devel libXft-devel libXinerama-devel libXfixes-devel libXi-devel pkg-config dbus unzip setxkbmap kanata mesa-dri

cd
mkdir scripts git temp .config
cd git
git clone https://github.com/Thesquid64/dotfiles.git

sudo mkdir /usr/share/fonts
cd /usr/share/fonts
sudo mkdir nerdfonts
cd nerdfonts
sudo wget https://github.com/ryanoasis/nerd-fonts/releases/download/v3.4.0/ShareTechMono.zip
sudo unzip ShareTechMono.zip
sudo rm -f ShareTechMono.zip

cd ~/git/dotfiles
cp -r alacritty kanata picom rofi ~/.config

cd ~/git/dotfiles/dwm-flexipatch
sudo make clean install
sudo mkdir /usr/local/share/xsessions
sudo cp ~/git/dotfiles/desktop/dwm.desktop /usr/local/share/xsessions
cd ~/git/dotfiles/desktop
cp .xinitrc .bashrc ~

cp ~/git/dotfiles/scripts/startdwm.sh ~/scripts

cd ~/git/dotfiles/dwmblocks
sudo make clean install

mkdir ~/.config
cp -r ~/git/dotfiles/* ~/.config

sudo cp -r ~/git/dotfiles/scripts/kanata /etc/sv
sudo ln -s /etc/sv/kanata /var/service/
sudo sv start kanata

mkdir ~/Pictures

