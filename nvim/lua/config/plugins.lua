local add = MiniDeps.add

add({ source = "https://github.com/neovim/nvim-lspconfig", })
add({ source = "brenoprata10/nvim-highlight-colors" })

vim.lsp.enable({ "lua_ls" })
vim.lsp.enable({ "clangd" })
--vim.lsp.enable({ "html-lsp" })
--vim.lsp.enable({ "css-lsp" })
--vim.lsp.enable({ "tsserver" })

