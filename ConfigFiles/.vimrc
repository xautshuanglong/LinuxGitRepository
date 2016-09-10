syntax on
filetype on
set autoindent
set cindent
set cmdheight=2

"set foldmethod=indent"
set foldmethod=syntax
set nofoldenable

set noswapfile

set hlsearch
set incsearch
set number
set ruler
set shiftwidth=4
set showcmd
set smartindent
set tabstop=4
set softtabstop=4
set wildmenu

set laststatus=2
set statusline=%F\ [Type=%Y]\ [Pos=(%l,%v)\ %p%%]\ [%{strftime(\"%Y-%m-%d\ %H:%M:%S\")}]

"""""""""""""""""""""""
" Tag List
"""""""""""""""""""""""
let Tlist_Exit_OnlyWindow = 1
let Tlist_Auto_Open = 1
set tags=tags
set autochdir
