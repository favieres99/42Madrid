				section	.text
				global	_ft_strlen

_ft_strlen:
				mov		rax, 0				;Move 0 to rax
				jmp		count				;Jumps to count

count:
				cmp		BYTE [rdi + rax], 0	;Compares the byte at rdi + rax(displacement) with 0 (str[i] == 0)
				je		done				;exits to done
				inc		rax					;rax++
				jmp		count				;jumps to count

done:
				ret							;returns i