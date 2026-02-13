--options

vim.opt.number = true
vim.opt.cursorline = true
vim.opt.relativenumber = true
vim.api.nvim_set_hl(0, "Normal", {bg = "none"})

--keybinds

vim.g.mapleader = ' '
vim.keymap.set('n', '<leader>cd', ':Ex<CR>')
