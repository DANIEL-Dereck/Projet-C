.name "Bonjoir"
.comment "Bonjour + Bonsoir = Bonjoir"	

l2:	     sti r1,%:live,%1
	     and r1,%0,r1

live:	    live %1
	    zjmp %:funk

livetowin:	live %1
		zjmp %:livetowin
	
funk:	live %1
	sti r1,%:vie1,%1
	st r1,-400
	live %1
	fork %:vie1
	fork %:vietel
	live %1
	sti r1,%:funk,%1
	zjmp %:live
	
vie1:	live %1
	fork %:vie2
	live %1
	zjmp %:vie2

vie2:	live %1
	fork %:vie1
	live %1
	zjmp %:vie1

vietel:	 live %1
	sti r1,%:vietel,%1
	live %1
	st r1, -400
	fork %:funk
	zjmp %:livetowin
