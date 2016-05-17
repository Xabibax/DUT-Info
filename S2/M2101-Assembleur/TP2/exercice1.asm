.DATA
	chaine DW "Lorem Ipsum."

.CODE
				LEA SP, STACK
				LD R0, 0
				OUT R0, 5
				LEA R0, chaine
				LD R1, 5
				LD R2, 10
				call affichechaine
				HLT

affichechaine:	OUT  R1, 1
				OUT R2, 2
boucle:		 	CMP [R0], '.'
				BEQ suite
				OUT [R0], 3
				LD R4, $B7
				OUT R4, 5
				INC R0
				JMP boucle
suite:			RET

.STACK 10