.name "Bonjoir"
.comment "Bonjour + Bonsoir = Bonjoir"	

l2:	     sti r1,%:live,%1
	     and r1,%0,r1

live:   live %1
	sti r2,%:live,%1
	fork %:live
	zjmp %:live
