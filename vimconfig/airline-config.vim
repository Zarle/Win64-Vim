set guifont=Consolas_for_Powerline_FixedD:h11:cANSI
set laststatus=2
let g:airline_powerline_fonts = 1
"set tabline on the top
let g:airline#extensions#tabline#enabled = 1
"show the number of buffer
let g:airline#extensions#tabline#buffer_nr_show = 1
let g:airline#extensions#whitespace#enabled = 0
let g:airline#extensions#whitespace#symbol = '!'
let g:Powerline_symbols="fancy"
let g:airline_symbols = {}
let g:airline_left_sep = "\u2b80" 
let g:airline_left_alt_sep = "\u2b81"
let g:airline_right_sep = "\u2b82"
let g:airline_right_alt_sep = "\u2b83"
let g:airline_symbols.branch = "\u2b60"
let g:airline_symbols.readonly = "\u2b64"
let g:airline_symbols.linenr = "\u2b61"
let g:airline#extensions#tabline#left_sep = "\u2b80"
let g:airline#extensions#tabline#left_alt_sep = "\u2b81"

nnoremap < :bp<CR>
nnoremap > :bn<CR>
