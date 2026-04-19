#!/bin/bash

feh --bg-scale ~/Images/wallpapers/city.png
setxkbmap us colemak

picom -b &

dwmblocks &

dwm
