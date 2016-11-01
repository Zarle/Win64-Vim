" Winƽ̨�´���ȫ����� gvimfullscreen.dll
" Alt + Enter ȫ���л�
" { ���ʹ��ڲ�͸����
" } �Ӵ󴰿ڲ�͸����
" Shift + t �л�Vim�Ƿ�������ǰ����ʾ
if has('gui_running') && has('gui_win32') && has('libcall')
    let g:MyVimLib = 'gvimfullscreen.dll'
    function! ToggleFullScreen()
        "let s:IsFullScreen = libcallnr("gvimfullscreen.dll", 'ToggleFullScreen', 0)
        "let s:IsFullScreen = libcallnr("gvimfullscreen.dll", 'ToggleFullScreen', 27 + 29*256 + 30*256*256)
        call libcall(g:MyVimLib, 'ToggleFullScreen', 27 + 29*256 + 30*256*256)
		"call libcallnr("gvimfullscreen.dll", "ToggleFullScreen", 0)
    endfunction

    let g:VimAlpha = 245
    function! SetAlpha(alpha)
        let g:VimAlpha = g:VimAlpha + a:alpha
        if g:VimAlpha < 180
            let g:VimAlpha = 180
        endif
        if g:VimAlpha > 255
            let g:VimAlpha = 255
        endif
        call libcall(g:MyVimLib, 'SetAlpha', g:VimAlpha)
    endfunction

    let g:VimTopMost = 0
    function! SwitchVimTopMostMode()
        if g:VimTopMost == 0
            let g:VimTopMost = 1
        else
            let g:VimTopMost = 0
        endif
        call libcall(g:MyVimLib, 'EnableTopMost', g:VimTopMost)
    endfunction
    "ӳ�� Alt+Enter �л�ȫ��vim
    nmap <F12> :call ToggleFullScreen()<CR>
    "�л�Vim�Ƿ�����ǰ����ʾ
    nmap <s-t> :call SwitchVimTopMostMode()<CR> 
	"����Vim����Ĳ�͸����
    nmap } :call SetAlpha(10)<cr>
    "����Vim�����͸����
    nmap { :call SetAlpha(-10)<cr>
    "Vim������ʱ���Զ�����InitVim ��ȥ��Vim�İ�ɫ�߿�
    autocmd GUIEnter * call libcallnr(g:MyVimLib, 'InitVim', 0)
    " Ĭ������͸��
    autocmd GUIEnter * call libcallnr(g:MyVimLib, 'SetAlpha', g:VimAlpha)
endif
