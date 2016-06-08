.DATA

la DW 40
ha DW 20
germe DW 12345678
m DW 2147483647
a DW 16807
attrapé DW 0
score DW 0
      DW 0
      DW 0
      DW 0
      DW 0
      DW 0
      DW 0
      DW 0
      DW 0
      DW 0
pointeur DSW 1
vitesse DW 1
niveau DW 'A'
type DW 1 ;1 pour tout droit et 2 pour ellipse
changer_dir DW 0

chaine_menu DW "Menu Principal."
xMenu DW 80
yMenu DW 20
xNiv DW 95
chaine_nivA DW "Niveau A."
yNivA DW 80
chaine_nivB DW "Niveau B."
yNivB DW 120
chaine_nivC DW "Niveau C."
yNivC DW 160
chaine_nivD DW "Niveau D."
yNivD DW 200
chaine_selec DW "Niveau sélectionné : ."
xSelec DW 50
ySelec DW 240
chaine_score DW "Score."
xScore DW 110
yScore DW 20
chaine_perdu DW "PERDU!."
xPerdu DW 106
yPerdu DW 120
chaine_gagne DW "GAGNE!."
xGagne DW 106
yGagne DW 120

.CODE

LEA SP,STACK

;					---EFFACER ECRAN---

debut:			LD R2,0
			OUT R2,5
			LD R3,0
			ST R3,changer_dir

;				---MENU PRINCIPAL---


		LEA R2,chaine_menu
		LD R3,xMenu
		LD R4,yMenu
		OUT R3,1
		OUT R4,2
		LD R5,%11110111
suite_menu:	CMP [R2],'.'
		BEQ nivA
		OUT [R2],3
		OUT R5,5
		INC R2
		JMP suite_menu

nivA:		LEA R2,chaine_nivA
		LD R3,xNiv
		LD R4,yNivA
		OUT R3,1
		OUT R4,2
		LD R5,%11110111
suite_nivA:	CMP [R2],'.'
		BEQ rectA
		OUT [R2],3
		OUT R5,5
		INC R2
		JMP suite_nivA

rectA:		LD R2,xNiv
		LD R3,yNivA
		CALL rectangle

		LEA R2,chaine_nivB
		LD R3,xNiv
		LD R4,yNivB
		OUT R3,1
		OUT R4,2
		LD R5,%11110111
suite_nivB:	CMP [R2],'.'
		BEQ rectB
		OUT [R2],3
		OUT R5,5
		INC R2
		JMP suite_nivB

rectB:		LD R2,xNiv
		LD R3,yNivB
		CALL rectangle

		LEA R2,chaine_nivC
		LD R3,xNiv
		LD R4,yNivC
		OUT R3,1
		OUT R4,2
		LD R5,%11110111
suite_nivC:	CMP [R2],'.'
		BEQ rectC
		OUT [R2],3
		OUT R5,5
		INC R2
		JMP suite_nivC
		
rectC:		LD R2,xNiv
		LD R3,yNivC
		CALL rectangle

		LEA R2,chaine_nivD
		LD R3,xNiv
		LD R4,yNivD
		OUT R3,1
		OUT R4,2
		LD R5,%11110111
suite_nivD:	CMP [R2],'.'
		BEQ rectD
		OUT [R2],3
		OUT R5,5
		INC R2
		JMP suite_nivD

rectD:		LD R2,xNiv
		LD R3,yNivD
		CALL rectangle

		LEA R2,chaine_selec
		LD R3,xSelec
		LD R4,ySelec
		OUT R3,1
		OUT R4,2
		LD R5,%11110111
suite_selec:	CMP [R2],'.'
		BEQ niveau_selec
		OUT [R2],3
		OUT R5,5
		INC R2
		JMP suite_selec

niveau_selec:	LD R3,197
		OUT R3,1
		LD R4,ySelec
		OUT R4,2
		LD R2,niveau
		OUT R2,3
		LD R5,%11110111
		OUT R5,5
		
;				---ATTENTE CHOIX NIVEAU---

AttenteChoixNiveau:	IN R2,0
			CMP R2,%11000101
			BEQ CommencerPartie
			CMP R2,%11000110
			BEQ QuitterJeu
			CMP R2,%11000111
			BNE AttenteChoixNiveau
			IN R3,6
			IN R4,7
			CMP R3,88
			BLT AttenteChoixNiveau
			CMP R3,158
			BGT AttenteChoixNiveau
			

			CMP R4,66
			BLT Test_NiveauB
			CMP R4,87
			BGT Test_NiveauB
			LD R5,197
			OUT R5,1
			LD R5,230
			OUT R5,2
			LD R5,10
			OUT R5,3
			OUT R5,4
			LD R5,%00000101
			OUT R5,5
			LD R5,'A'
			ST R5,niveau
			OUT R5,3
			LD R5,197
			OUT R5,1
			LD R5,ySelec
			OUT R5,2
			LD R5,%11110111
			OUT R5,5
			LD R5,2
			ST R5,vitesse
			LD R5,1
			ST R5,type

Test_NiveauB:		CMP R4,106
			BLT Test_NiveauC
			CMP R4,127
			BGT Test_NiveauC
			LD R5,197
			OUT R5,1
			LD R5,230
			OUT R5,2
			LD R5,10
			OUT R5,3
			OUT R5,4
			LD R5,%00000101
			OUT R5,5
			LD R5,'B'
			ST R5,niveau
			OUT R5,3
			LD R5,197
			OUT R5,1
			LD R5,ySelec
			OUT R5,2
			LD R5,%11110111
			OUT R5,5
			LD R5,2
			ST R5,vitesse
			LD R5,2
			ST R5,type
			

Test_NiveauC:		CMP R4,146
			BLT Test_NiveauD
			CMP R4,167
			BGT Test_NiveauD
			LD R5,197
			OUT R5,1
			LD R5,230
			OUT R5,2
			LD R5,10
			OUT R5,3
			OUT R5,4
			LD R5,%00000101
			OUT R5,5
			LD R5,'C'
			ST R5,niveau
			OUT R5,3
			LD R5,197
			OUT R5,1
			LD R5,ySelec
			OUT R5,2
			LD R5,%11110111
			OUT R5,5
			LD R5,4
			ST R5,vitesse
			LD R5,1
			ST R5,type


Test_NiveauD:		CMP R4,186
			BLT AttenteChoixNiveau
			CMP R4,207
			BGT AttenteChoixNiveau
			LD R5,197
			OUT R5,1
			LD R5,230
			OUT R5,2
			LD R5,10
			OUT R5,3
			OUT R5,4
			LD R5,%00000101
			OUT R5,5
			LD R5,'D'
			ST R5,niveau
			OUT R5,3
			LD R5,197
			OUT R5,1
			LD R5,ySelec
			OUT R5,2
			LD R5,%11110111
			OUT R5,5
			LD R5,4
			ST R5,vitesse
			LD R5,2
			ST R5,type
			
			JMP AttenteChoixNiveau

CommencerPartie:



		LD R5,type
		CMP R5,1
		BEQ tout_droit
		JMP en_ellipse


;					---JEU_TOUT_DROIT---


tout_droit:	LD R2,0
		OUT R2,5
		LD R0,20
		LD R1,100
suite_droit:	CALL loutre
		CMP R0,235
		BGT perdu
		IN R2,0
		CMP R2,%11000111
		BNE suite_droit2
		LD R3,R0
		ADD R3,40
		LD R4,R1
		ADD R4,20
		IN R6,6
		IN R5,7
		CMP R6,R0
		BLT suite_droit2
		CMP R6,R3
		BGT suite_droit2
		CMP R5,R1
		BLT suite_droit2
		CMP R5,R4
		BGT suite_droit2
		JMP gagne


suite_droit2:	CALL effacer_loutre
		LD R2,vitesse
		ADD R0,R2
		JMP suite_droit

;					---JEU_ELLIPSE---


en_ellipse:	LD R2,0
		OUT R2,5
		LD R0,20
		LD R1,100
suite_ellipse:	CALL loutre
		CMP R0,235
		BGT perdu
		IN R2,0
		CMP R2,%11000111
		BNE suite_ellipse2
		LD R3,R0
		ADD R3,40
		LD R4,R1
		ADD R4,20
		IN R6,6
		IN R5,7
		CMP R6,R0
		BLT suite_ellipse2
		CMP R6,R3
		BGT suite_ellipse2
		CMP R5,R1
		BLT suite_ellipse2
		CMP R5,R4
		BGT suite_ellipse2
		JMP gagne


suite_ellipse2:	CALL effacer_loutre
		LD R2,vitesse
		ADD R0,R2
		CMP R1,0
		BNE continuer1
		LD R3,1
		ST R3,changer_dir

		ADD R1,1
		LD R3,1
		ST R3,changer_dir
		JMP suite_ellipse
continuer1:	LD R3,changer_dir
		CMP R3,1
		BNE continuer2
		ADD R1,1
		JMP suite_ellipse
continuer2:	SUB R1,1
		JMP suite_ellipse


;					---PERDU---


perdu:		CALL effacer_loutre
		LEA R2,chaine_perdu
		LD R3,xPerdu
		LD R4,yPerdu
		OUT R3,1
		OUT R4,2
		LD R5,%11110111
suite_perdu:	CMP [R2],'.'
		BEQ suite_perdu2
		OUT [R2],3
		OUT R5,5
		INC R2
		JMP suite_perdu

suite_perdu2:	IN R2,0
		CMP R2,%11000101
		BNE suite_perdu2
		JMP menu_score

;					---GAGNE---


gagne:		CALL effacer_loutre
		LEA R2,chaine_gagne
		LD R3,xGagne
		LD R4,yGagne
		OUT R3,1
		OUT R4,2
		LD R5,%11110111
suite_gagne:	CMP [R2],'.'
		BEQ suite_gagne2
		OUT [R2],3
		OUT R5,5
		INC R2
		JMP suite_gagne

;				---MODIFIER SCORE---


			LD R2,255
			SUB R2,R0
			LEA R3,score
			LD R4,[R3]
suite_changer_score:	INC R3
			LD R5,[R3]
			LD [R3],R4
			LD R4,R5
			CMP R3,9
			BNE suite_changer_score
			LEA R3,score
			LD [R3],R2
		
		
		

suite_gagne2:	IN R2,0
		CMP R2,%11000101
		BNE suite_gagne2
		JMP menu_score

;					---SCORE---


menu_score:	LD R2,0
		OUT R2,5
		LEA R2,chaine_score
		LD R3,xScore
		LD R4,yScore
		OUT R3,1
		OUT R4,2
		LD R5,%11110111
suite_score:	CMP [R2],'.'
		BEQ afficher_score
		OUT [R2],3
		OUT R5,5
		INC R2
		JMP suite_score
		
afficher_score:	



attente_clic_score:	IN R2,0
			CMP R2,%11000101
			BNE attente_clic_score

			JMP debut



QuitterJeu:	HLT






;					----FONCTIONS----

calculgerme:	LD R0,[SP+1]
		MUL R0,[SP+2]
		LD R1,[SP+3]
		CALL proc1
		ST R3,germe
		RET 3

proc1:		LD R3,R0
boucle_proc1:	DIV R3,R1
		MUL R3,R1
		NEG R3
		ADD R3,R0
		CMP R3,R1
		BGTU boucle_proc1
		RET

rectangle:	SUB R2,7
		OUT R2,1
		SUB R3,14
		OUT R3,2
		LD R4,70
		OUT R4,3
		LD R5,21
		OUT R5,4
		LD R6,%11110011
		OUT R6,5
		RET

loutre:		OUT R0,1
		OUT R1,2
		LD R2,la
		OUT R2,3
		LD R2,ha
		OUT R2,4
		LD R2,%10100110
		OUT R2,5
		RET

effacer_loutre:	OUT R0,1
		OUT R1,2
		LD R2,la
		OUT R2,3
		LD R2,ha
		OUT R2,4
		LD R2,%00000110
		OUT R2,5
		RET	


.STACK 10