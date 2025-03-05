section .data
	str: db "Hello, World!", 10, 0

section .text

global _start
_start;
	PUSH RBP
	MOV RBP, RSP
	MOV RAX, 1
	MOV RDI, 1
	MOV RSI, str
	mov rdx, 14
	mov rsp, rbp
	pop rbp