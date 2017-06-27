.name "qsqs plop"
.comment "plop plop"

live:		live	%30
		zjmp	%:live

couscous:	zjmp	%:zsh

plop:	ld 	%0,r2
	live 	%20
	zjmp	%:live

zsh:	live	%15
	zjmp	%:plop
