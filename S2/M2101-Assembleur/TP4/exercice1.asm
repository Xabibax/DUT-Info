.DATA
	codeCouleur DW 15
	
.CODE
				LEA SP, STACK
				LD R0, 0
				OUT R0, 5
			
boucle1:		PUSH codeCouleur

suite:			CALL carreMaxSize
				IN R0, 0
				CMP R0, $86
				BEQ fin
				CMP R0, $C5
				BNE boucle1
				PUSH codeCouleur
				CALL carreMinSize
				
boucle2:		IN R0, 0
				CMP R0, $85
				BNE boucle2
				PUSH codeCouleur
				CALL carreMaxSize
				JMP suite
fin:			HLT
	
carreMaxSize:	LD R0, 78
				OUT R0, 1
				OUT R0, 2
				LD R0, 100
				OUT R0, 3
				OUT R0, 4
				LD R0, 5
				SHL [SP+1]
				SHL [SP+1]
				SHL [SP+1]
				SHL [SP+1]
				ADD R0, [SP+1]
				OUT R0, 5
				RET 1
			
carreMinSize:	LD R0, 0
				OUT R0, 5			
				LD R0, 103
				OUT R0, 1
				OUT R0, 2
				LD R0, 50
				OUT R0, 3
				OUT R0, 4
				LD R0, 5
				SHL [SP+1]
				SHL [SP+1]
				SHL [SP+1]
				SHL [SP+1]
				ADD R0, [SP+1]
				OUT R0, 5
				RET 1
			
.STACK 10