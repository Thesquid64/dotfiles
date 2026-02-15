local add = MiniDeps.add

add({ source = "https://github.com/neovim/nvim-lspconfig", })
add({ source = "brenoprata10/nvim-highlight-colors" })

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
