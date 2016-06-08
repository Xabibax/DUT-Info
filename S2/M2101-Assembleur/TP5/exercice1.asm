.DATA
	clic1 DW 0
	x DSW 1
	y DSW 1
	oldX DSW 1
	oldY DSW 1
	couleur DW $F0

.CODE
				LEA SP, STACK
				
initialisation:	LD R0, 0
				OUT R0, 5
				CALL palette
				
generation:		IN R0, 0
				CMP R0, $C6
				BEQ fin
				CMP R0, $C5
				BEQ initialisation
				CMP R0, $C7
				BNE	generation
				IN R1, 6
				IN R2, 7
				ST R1, x
				ST R2, y
				CMP R1, 20
				BGT zoneDessin
				AND R2, $F0
				ST R2, couleur
				JMP generation
				
zoneDessin:		LD R0, 1
				CMP R0, clic1
				BEQ tracer
				ST R0, clic1
				JMP coordonnees
				
tracer:			LD R1, x
				LD R2, y
				LD R3, oldX
				LD R4, oldY
				LD R5, couleur
				OR R5, $02
				OUT R1, 1
				OUT R2, 2
				OUT R3, 3
				OUT R4, 4
				OUT R5, 5
				
coordonnees:	ST R1, oldX
				ST R2, oldY
				JMP generation
	
palette:		PUSH R1
				PUSH R2
				PUSH R3
				PUSH R4
				PUSH R5
				LD R1, 0
				LD R2, 0
				LD R3, 20
				LD R4, 16
				LD R5, $00
				
boucle: 		PUSH R5
				PUSH R1
				PUSH R2
				PUSH R3
				PUSH R4
				CALL rectangle
				ADD R5, $10
				ADD R2, 16
				CMP R5, $F0
				BLE boucle
				PULL R5
				PULL R4
				PULL R3
				PULL R2
				PULL R1
				RET 
						
rectangle:		PUSH R0
				LD R0, [SP+5]
				OUT R0, 1
				LD R0, [SP+4]
				OUT R0, 2
				LD R0, [SP+3]
				OUT R0, 3
				LD R0, [SP+2]
				OUT R0, 4
				LD R0, [SP+6]
				OR R0, $05
				OUT R0, 5
				PULL R0
				RET 5
				
fin:			HLT
				
.STACK 35