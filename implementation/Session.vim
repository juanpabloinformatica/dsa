let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Documents/dsa/implementation
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +107 dsa.c
badd +0 queue.h
badd +4 dynamicArray.c
badd +32 queue.c
badd +32 stack.c
badd +18 stack.h
argglobal
%argdel
$argadd .
edit dsa.c
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
wincmd _ | wincmd |
split
1wincmd k
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 18 + 20) / 40)
exe 'vert 1resize ' . ((&columns * 93 + 95) / 191)
exe '2resize ' . ((&lines * 19 + 20) / 40)
exe 'vert 2resize ' . ((&columns * 93 + 95) / 191)
exe '3resize ' . ((&lines * 18 + 20) / 40)
exe 'vert 3resize ' . ((&columns * 97 + 95) / 191)
exe '4resize ' . ((&lines * 19 + 20) / 40)
exe 'vert 4resize ' . ((&columns * 97 + 95) / 191)
argglobal
balt stack.c
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 15 - ((14 * winheight(0) + 9) / 18)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 15
normal! 0
lcd ~/Documents/dsa/implementation
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/dsa/implementation/dynamicArray.c", ":p")) | buffer ~/Documents/dsa/implementation/dynamicArray.c | else | edit ~/Documents/dsa/implementation/dynamicArray.c | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/dsa/implementation/dynamicArray.c
endif
balt ~/Documents/dsa/implementation/dsa.c
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 15 - ((14 * winheight(0) + 9) / 19)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 15
normal! 034|
lcd ~/Documents/dsa/implementation
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/dsa/implementation/queue.h", ":p")) | buffer ~/Documents/dsa/implementation/queue.h | else | edit ~/Documents/dsa/implementation/queue.h | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/dsa/implementation/queue.h
endif
balt ~/Documents/dsa/implementation/queue.c
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 19 - ((12 * winheight(0) + 9) / 18)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 19
normal! 06|
lcd ~/Documents/dsa/implementation
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/dsa/implementation/queue.c", ":p")) | buffer ~/Documents/dsa/implementation/queue.c | else | edit ~/Documents/dsa/implementation/queue.c | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/dsa/implementation/queue.c
endif
balt ~/Documents/dsa/implementation/queue.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 25 - ((9 * winheight(0) + 9) / 19)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 25
normal! 09|
lcd ~/Documents/dsa/implementation
wincmd w
exe '1resize ' . ((&lines * 18 + 20) / 40)
exe 'vert 1resize ' . ((&columns * 93 + 95) / 191)
exe '2resize ' . ((&lines * 19 + 20) / 40)
exe 'vert 2resize ' . ((&columns * 93 + 95) / 191)
exe '3resize ' . ((&lines * 18 + 20) / 40)
exe 'vert 3resize ' . ((&columns * 97 + 95) / 191)
exe '4resize ' . ((&lines * 19 + 20) / 40)
exe 'vert 4resize ' . ((&columns * 97 + 95) / 191)
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
