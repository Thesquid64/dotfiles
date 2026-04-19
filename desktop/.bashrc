# .bashrc

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias ls='ls --color=auto'
alias hfzf='file=$(fd --type f --hidden | fzf --preview "cat {}") && [ -n "$file" ] && nvim "$file"'
alias nivm='nvim'
alias discord='firefox --new-window discord.com &'
alias packet='flatpak run io.github.nozwock.Packet'
alias clear='clear && source ~/.bashrc'
alias mkdwm='cd /home/maxence/Apps/git/dotfiles/dwm-flexipatch && sudo make clean install && cd -'
alias sl='ls'

export PF_INFO="ascii os uptime memory wm"
export PF_SEP="   "
export EDITOR=nvim

pfetch

PS1='[\u@\h \W]\$ '

# opencode
export PATH=/home/maxence/.opencode/bin:$PATH

# OpenClaw Completion
source "/home/maxence/.openclaw/completions/openclaw.bash"
