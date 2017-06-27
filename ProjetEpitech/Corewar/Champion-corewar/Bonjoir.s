.name "Bonjoir"
.comment "Bonjour + Bonsoir = Bonjoir"	

l2:	     sti r1,%:live,%1
	     and r1,%0,r1

live:	live %1
	zjmp %:funk
	
	
livetowin:	live %1
		zjmp %:livetowin
	
funk:	live %1
	st r2,-400
	live %1
	fork %:vie1
	fork %:vietel
	fork %:izi
	live %1
	sti r2,%:funk,%1
	zjmp %:izi
	
vie1:	live %1
	fork %:vie2
	live %1
	zjmp %:vie2

vie2:	live %1
	fork %:vie1
	live %1
	zjmp %:vie1

vietel:	 live %1
	live %1
	st r1, -400
	zjmp %:livetowin

izi:	sti r1,%:live,%1
	and r1,%0,r1
	fork %:ours
	zjmp %:futur
	
ours:	st r1,130
	st r1,140
	st r1,150
	sti r1,%:zero,%1
	fork %:zero
	zjmp %:ours

zero:	ld %0,r15
	st r1,666
	st r1,666
	sti r1,%:zero,%1
	fork %:zero
	
futur:	ld %400,r3	
	fork %34
	fork %54
	fork %74
	fork %94
	st r3,400
	st r3,400
	fork %:zero
	fork %:lmlvsb
	zjmp %:vietel

lmlvsb:	live %3
	st r3,600
	st r3,600
	st r3,600
	st r3,600
	sti r1,%:lmlvsb,%1
	zjmp %:lmlvsb
	
