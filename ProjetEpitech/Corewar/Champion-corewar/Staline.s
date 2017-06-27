.name "Staline"
.comment "Welcome"	

l2:	sti r1,%:live,%1
	and r1,%0,r1

live:	live %1
	live %2
	live %3
	live %4
	zjmp %:main

main:	live %1
	live %2
	live %3
	live %4
	fork %:funk0
	zjmp %:livetowin
	
livetowin:	live %1
	live %2
	live %3
	live %4
	zjmp %:livetowin
	
funk0:	live %1
	live %2
	live %3
	live %4
	sti r1,%:vie10,%1
	st r1,-400
	live %1
	live %2
	live %3
	live %4
	fork %:vie10
	live %1
	live %2
	live %3
	live %4
	sti r1,%:funk0,%1
	zjmp %:main
	
vie10:	live %1
	live %2
	live %3
	live %4
	fork %:vie20
	live %1
	live %2
	live %3
	live %4
	sti r1,%:vie20,%50
	zjmp %:vie20

vie20:	live %1
	live %2
	live %3
	live %4
	fork %:vie10
	live %1
	live %2
	live %3
	live %4
	sti r1,%:vie10,%50
	zjmp %:vie10
