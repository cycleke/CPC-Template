syntax enable
set syntax=on
set nobackup
set noswapfile
set noundofile
set nu
set smartindent
set cindent
set foldmethod=marker
set foldlevel=3 
set foldenable
set autowrite
set noeb
set tabstop=2
set softtabstop=2
set shiftwidth=2
set expandtab 
set anti enc=utf-8
set guifont=GoMono\ Nerd\ Font\ 13

:imap jk <Esc>

map <F5> : call Complie() <CR>

func Complie()
	exec "w"
	exec "!g++ % -o %< -g -Wall -std=c++11"
endfunc

map <F6> : call Run() <CR>

func Run()
	exec "!./%<"
endfunc

map <F9> : call DeBug() <CR>

func DeBug()
	exec "!gdb %<"
endfunc

set guioptions-=T
set guioptions-=m
set guioptions-=r
set guioptions-=egrL
set cursorline
:nn <M-1> 1gt
:nn <M-2> 2gt
:nn <M-3> 3gt
:nn <M-4> 4gt
:nn <M-5> 5gt
:nn <M-6> 6gt
:nn <M-7> 7gt
:nn <M-8> 8gt
:nn <M-9> 9gt
:nn <M-t> :tabnew<CR>
:nn <M-w> :close<CR>
:nn <C-Tab> :tabnext<CR>

