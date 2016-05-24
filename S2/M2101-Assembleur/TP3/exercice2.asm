.DATA
	codeCouleur DW 0
	coordX	DW 0
	coordY DW 0
	largeur DW 255
	hauteur DW 16

.CODE
		LEA SP, STACK
		LD R0, 0
		OUT R0, 5
		LD R1, coordY
mire:	CMP R1, 255
		BGEU suite
		PUSH codeCouleur
		PUSH coordX
		PUSH R1
		PUSH largeur
		PUSH hauteur
		CALL rectangle
		ADD R1, hauteur
		INC codeCouleur
		JMP mire
suite:	HLT	
	
rectangle:  LD R0, [SP+4]
			OUT R0, 1
			LD R0, [SP+3]
			OUT R0, 2
			LD R0, [SP+2]
			OUT R0, 3
			LD R0, [SP+1]
			OUT R0, 4
			LD R0, 5
			SHL [SP+5] ;DLG pour mettre le codeCouleur dans la partie forte du port 5
			SHL [SP+5]
			SHL [SP+5]
			SHL [SP+5]
			ADD R0, [SP+5]
			OUT R0, 5
			RET 5
			
.STACK 10