rm -rf custom
mkdir custom
cd custom
$customdir = eval(pwd)
mkdir overlay iso bin

echo "Cloning dotfiles ..."
git clone https://github.com/Thesquid64/dotfiles

echo "Building dwm-flexipatch"
buildDwmFlexipatch

echo "Building dwmblocks"

buildDwmblocks



buildDwmFlexipatch() {
	cd $customdir/dotfiles/dwmblocks
	make dwmblocksCompatible
	mv dwmblocksCompatible $customdir/bin/dwmblocks
	cd -
}

buildDwmblocks() {
	cd $customdir/dotfiles/dwm-flexipatch
	make dwmCompatible
	mv dwmCompatible $customdir/bin/dwm
	cd -
}

# "Do this, or else die"
cd /home/void/Music || { echo "Directory not found"; exit 1; }


sudo .././mkvoid -a x86_64 -I my_overlay -p ""
