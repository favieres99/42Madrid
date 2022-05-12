				section	.text
				global	_ft_strcmp

;s1 = rdi, s2 = rsi

_ft_strcmp:		xor		rcx, rcx							;set to 0
				xor		rdx, rdx							;set to 0
				xor		rax, rax							;set to 0
				cmp		rsi, 0								;check that exists
				jz		check_null							;if is 0 jump to check_null
				cmp		rdi, 0								;check that exists
				jz		check_null							;if is 0 jump to check_null
				jmp		check

check_null:		cmp		rdi, rsi
				jz		equal								;s1 == dri == s2 == rsi == NULL
				jg		superior							;s1 == rdi == NULL
				jmp		inferior							;s2 == rsi == NULL

compare:		mov		dl, BYTE [rsi + rcx]				;save s2 in dl
				cmp		BYTE[rdi + rcx], dl					;compare s2 with s1
				jne		last_char

increment:		inc		rcx									;rcx++

check:			cmp		BYTE [rdi + rcx], 0					;checks if is null
				je		last_char							;if is last jumps
				cmp		BYTE [rsi + rcx], 0					;checks if is null
				je		last_char							;if is last jumps
				jmp		compare

last_char:		mov		dl, BYTE [rdi + rcx]				;s1 in dl
				sub		dl, BYTE [rsi + rcx]				;substrates borth numbers
				cmp		dl, 0								;compares de result with 0
				jl		inferior							;si es menor salta
				jg		superior							;si es mayor salta, si no es que es igual y sigue hasta el igual

equal:
				ret

inferior:		mov		dl, BYTE [rsi + rcx]				;s1 in dl
				sub		dl, BYTE [rdi + rcx]				;substrates both numbers
				mov		al, dl								;copy byte of dl to al, wich is the first 8 bytes of rax
				neg		rax									;sets rax to negative
				ret

superior:		mov		dl, BYTE [rdi + rcx]				;s1 in dl
				sub		dl, BYTE [rsi + rcx]				;substrates both numbers
				mov		al, dl								;copy byte of dl to al, wich is the first 8 bytes of rax
				ret