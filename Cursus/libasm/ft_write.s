			section .text
			extern ___error
			global _ft_write

_ft_write:	push	rbp						;push to the stack
			mov		rbp, rsp				;set size to rsp
			mov		rax, 0x2000004			;read is 0x2000003
			syscall							;save its return into rax
			jc		errno					;jump if there was an error in read
			jmp		exit

errno:		mov		r10, rax				;rax to r10
			call	___error				;get error
			mov		[rax], r10				;save the error
			mov		rax, -1					;rax -1

exit:		leave							;is the same as: mov rbp, rsp and pop rsb
			ret								;return (rax)
