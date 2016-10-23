; Created by ROOSE Philippe on 7/5/97
; Last modified on 27/03/2002

; Touches habituelles des clavier "PC" DEL, HOME, END, ...
(pc-selection-mode)

;Touches de raccourcis - config par defaut
(put 'downcase-region 'disabled nil)
(global-set-key "\C-l" 'goto-line)
(global-font-lock-mode t); coloration automatique des mots cl�s

;Redefinition des touches 'speciales'
(global-set-key "\M-'" "{")
(global-set-key "\M-=" "}")
(global-set-key "\M-a" "@")
(global-set-key "\M-"" "#")
(global-set-key "\M- " "~")
(global-set-key "\M-(" "[")
(global-set-key "\M-)" "]")
(global-set-key "\M--" "|")
(global-set-key "\M-_" "\\")

;Mise en surbrillance des zones s�lectionn�es
;(transcient-mark-mode t)

; Alphabet europ�en (accents)
(standard-display-european 1)
