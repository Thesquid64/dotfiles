local add = MiniDeps.add

add({ source = "https://github.com/neovim/nvim-lspconfig" })
add({ source = "brenoprata10/nvim-highlight-colors" })
add({ source = "https://github.com/MeanderingProgrammer/render-markdown.nvim.git" })
add({ source = "https://github.com/nvim-treesitter/nvim-treesitter" })
add({ source = "https://github.com/nvim-mini/mini.nvim" })
add({ source = "https://github.com/lervag/vimtex" })

vim.lsp.enable({ "lua_ls" })
vim.lsp.enable({ "clangd" })
vim.lsp.enable({ "bash-language-server" })

vim.diagnostic.config({
  update_in_insert = true,
  signs = false,
  virtual_lines = false,
  underline = true,
  virtual_text = {
	spacing = 5,
	prefix = "",
  }
})

vim.g.vimtex_view_method = "zathura" -- ou okular / evince
vim.g.vimtex_compiler_method = "latexmk"

require('mini.pick').setup()
