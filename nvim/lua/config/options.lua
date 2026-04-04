--options

vim.opt.number = true
vim.opt.cursorline = true
vim.opt.relativenumber = true
vim.api.nvim_set_hl(0, "Normal", {bg = "none"})

vim.o.completeopt = "menu,menuone,noselect"

--keybinds

vim.g.mapleader = ' '
vim.keymap.set('n', '<leader>cd', ':Ex<CR>')
vim.keymap.set('n', '<leader>l', ':bnext<CR>')
vim.keymap.set('n', '<leader>h', ':bprevious<CR>')
vim.keymap.set("n", "<A-j>", ":m .+1<CR>==")
vim.keymap.set("n", "<A-k>", ":m .-2<CR>==")
