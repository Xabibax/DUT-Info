.DATA
	valinit DW 13
	Fact DSW 1
	
.CODE
	LD R0,1
	LD R1,2
boucle:	CMP R1,valinit
		BLE inferieur
		JMP fact
inferieur: MUL R0,R1
		   INC R1
		   JMP boucle
fact: ST R0,Fact
	  HLT