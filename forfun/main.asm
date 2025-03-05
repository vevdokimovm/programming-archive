section .data
	str: db "Hello, World!", 10, 0

section .text

global _start
_start:
	PUSH RBP
	MOV RBP, RSP

	MOV RSP, RBP
	POP RBP
	RET
