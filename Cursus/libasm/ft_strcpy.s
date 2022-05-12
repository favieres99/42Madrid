				section	.text
				global	_ft_strcpy

_ft_strcpy:		xor		rcx, rcx				;set rcx to 0
				xor		rdx, rdx				;set rcx to 0
				cmp		rsi, 0					;check that source exists
				jz		return					;if it doesn´t exit
				jmp		copy					;goes to copy

copy:			mov		dl, BYTE [rsi + rcx]	;saves first of source to dl
				mov		BYTE [rdi + rcx], dl	;places dl onto dest
				cmp		dl, 0					;check if dl is 0
				jnz		increment				;if it is not next param

increment:		inc		rcx						;rcx++

return:			mov		rax,rdi					;moves rdi into rax
				ret