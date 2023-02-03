let mapleader=" "
syntax on
set number
set norelativenumber
set cursorline
set wrap
set showcmd
set wildmenu

set hlsearch
exec "nohlsearch"
set ignorecase
set smartcase

noremap J 5j
noremap K 5k

noremap = nzz
noremap - Nzz
noremap <LEADER><CR> :nohlsearch<CR>

inoremap jj <ESC>

map s :<nop>
map S :w<CR>
map Q :q<CR>
map R :source $MYVIMRC<CR>
map <C-n> :NERDTreeToggle<CR>

" ====================
" 	coc_nvim

inoremap <silent><expr> <TAB>
      \ coc#pum#visible() ? coc#pum#next(1) :
      \ CheckBackspace() ? "\<Tab>" :
      \ coc#refresh()
inoremap <expr><S-TAB> coc#pum#visible() ? coc#pum#prev(1) : "\<C-h>"

function! CheckBackspace() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction
inoremap <silent><expr> <c-o> coc#refresh()

inoremap <expr> <cr> complete_info()["selected"] != "-1" ? "\<C-y>" : "\<C-g>u\<CR>"

nmap <silent> [g <Plug>(coc-diagnostic-prev)
nmap <silent> ]g <Plug>(coc-diagnostic-next)

" GoTo code navigation
nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gy <Plug>(coc-type-definition)
nmap <silent> gi <Plug>(coc-implementation)
nmap <silent> gr <Plug>(coc-references)

" Use K to show documentation in preview window
nnoremap <silent> <LEADER>h :call ShowDocumentation()<CR>

function! ShowDocumentation()
  if CocAction('hasProvider', 'hover')
    call CocActionAsync('doHover')
  else
    call feedkeys('K', 'in')
  endif
endfunction

" Symbol renaming
nmap <leader>rn <Plug>(coc-rename)

" Formatting selected code
xmap <leader>f  <Plug>(coc-format-selected)
nmap <leader>f  <Plug>(coc-format-selected)

"=======================
"     plug

call plug#begin('~/.vim/plugged')

Plug 'vim-airline/vim-airline'
Plug 'connorholyday/vim-snazzy'
Plug 'preservim/nerdtree'
Plug 'Yggdroot/LeaderF', {'do': './install.sh'}
Plug 'jiangmiao/auto-pairs'
Plug 'mhinz/vim-startify'
Plug 'neoclide/coc.nvim', {'barnch': 'release'}
Plug 'tjdevries/colorbuddy.vim'
Plug 'tjdevries/gruvbuddy.nvim'
Plug 'shinchu/lightline-gruvbox.vim'

call plug#end()

"let g:lightline = {}
"let g:lightline.colorscheme = 'gruvbox'

color snazzy
let g:SnazzyTransparent = 1

