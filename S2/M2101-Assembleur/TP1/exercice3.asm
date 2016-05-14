.DATA
	txt DW "Lorem Ipsum"
		DW 0
	maxi DSW 1
.CODE
		LEA SP, STACK
		LEA R2, txt
		LD R1, 0
boucle:	LD R0, [R2]
		CMP R0, 0
		BEQ sortir
		CALL max
		LD R1, R3
		INC R2
		JMP boucle
sortir:	ST R3, maxi
		HLT
		
max:	CMP R0, R1
		BGTU suite
		LD R3, R1
		JMP fin
suite:	LD R3, R0
fin:	RET

.STACK 10