				section	.text
				global	_ft_strdup
				extern	_ft_strlen
				extern	_ft_strcpy
				extern	_malloc

_ft_strdup:		call	_ft_strlen			;rax = len
				add		rax, 1				;add 1 more space
				push	rdi					;places rdi at the end of stack
				mov		rdi, rax			;rdi = rax (strlen + 1)
				call	_malloc				;malloc(rax)
				pop		rcx					;rdisave into rcx
				mov		rdi, rax			;rdi = malloc(rax)
				mov		rsi, rcx			;rsi is rcx
				call	_ft_strcpy			;ft_strcpy(rdi, rsi)	
				ret							;return rax