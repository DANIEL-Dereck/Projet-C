.name "Live"
.comment "Bonjour je suis la :)"

l2:	sti r1,%:live,%1
	and r1,%0,r1

live:	 live %1
	zjmp %:live

barriere:	live %1
		fork %:barriere
		zjmp %1
		zjmp %:barriere
