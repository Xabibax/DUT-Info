.DATA
 
.CODE
			LEA SP,STACK
			LD R0,0
			OUT R0,5
waitClick:	IN R0,0
			CMP R0,%11000111
			BNE waitClick
			IN R2,6
			IN R3,7
			SUB R2,50
			SUB R3,50
			PUSH R2
			PUSH R3
			ADD R2,25
			ADD R3,25
			PUSH R2
			PUSH R3
boucle:		LD R0,0
			OUT R0,5
			call carreMaxSize
onA:		IN R1,0
			CMP R1,%11000110
			BEQ fin
			CMP R1,%11000101
			BNE onA
			call carreMinSize
offA:		IN R1,0
			CMP R1,%10000101
			BNE offA
			JMP boucle
fin:		HLT			
			
			
carreMaxSize:	LD R0,[SP+4]
			OUT R0,1
			LD R0,[SP+3]
			OUT R0,2
			LD R0,100
			OUT R0,3
			OUT R0,4
			LD R0,$F5
			OUT R0,5
			RET
			
carreMinSize:	LD R0,0
			OUT R0,5
			LD R0,[SP+2]
			OUT R0,1
			LD R0,[SP+1]
			OUT R0,2
			LD R0,50
			OUT R0,3
			OUT R0,4
			LD R0,$F5
			OUT R0,5
			RET
			
			
.STACK 10