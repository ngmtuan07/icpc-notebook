source $VIMRUNTIME/defaults.vim

let mapleader = " "

runtime! ftplugin/man.vim
packadd! matchit

set modeline
set autoread
set hidden
set undofile
set undodir=~/.vim/undo//
set noswapfile

set tabstop=4
set softtabstop=4
set shiftwidth=4
set expandtab
set smarttab
set autoindent
set nojoinspaces
set nostartofline

set hlsearch
set ignorecase
set smartcase

set mouse=a

set background=dark
set number
set laststatus=2
set belloff=all
set splitbelow
set splitright
set scrolloff=2

nnoremap Y y$
nnoremap <C-L> :nohlsearch<Bar>normal! <C-L><CR>
nnoremap <Leader>h :tab h 
nnoremap <Leader>e :e $MYVIMRC<CR>
nnoremap <Leader>r :source $MYVIMRC<CR>
nnoremap <Leader>c <Cmd>w | !g++-std=c++20 -O2 -Wall % -o %:r<CR>
nnoremap <Leader>x <Cmd>!./%:r<CR>