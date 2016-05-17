.DATA
	codeCouleur DW 12
	coordX	DW 50
	coordY DW 50
	largeur DW 110
	hauteur DW 40
	
.CODE
	LEA SP, STACK
	LD R0, 0
	OUT R0, 5
	PUSH codeCouleur
	PUSH coordX
	PUSH coordY
	PUSH largeur
	PUSH hauteur
	CALL rectangle
	HLT
	
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
			RET
			
.STACK 10