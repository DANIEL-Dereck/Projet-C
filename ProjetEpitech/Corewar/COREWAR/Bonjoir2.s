.name "Bonjoir"
.comment "Bonjour + Bonsoir = Bonjoir"	

l2:	sti r1,%:live,%1
	and r1,%0,r1

live:	live %21
	zjmp %:main

main:	live %21
	fork %:funk0
	fork %:funk1
	zjmp %:livetowin
	
livetowin:	live %21
	        zjmp %:livetowin
	
funk0:	live %21
	sti r1,%:vie10,%1
	st r1,-400
	live %21
	fork %:vie10
	fork %:vietel0
	live %21
	sti r1,%:funk0,%1
	zjmp %:main
	
vie10:	live %21
	fork %:vie20
	live %21
	sti r1,%:vie20,%50
	zjmp %:vie20

vie20:	live %21
	fork %:vie10
	live %21
	sti r1,%:vie10,%50
	zjmp %:vie10

vietel0:	live %21
	        sti r1,%:vietel0,%1
	        live %21
	        st r1, -400
	        fork %:kamikaze
	        fork %:funk0
	        zjmp %:funk1

funk1:	  live %21
	  sti r1,%:vie11,%1
	  st r1,-400
	  live %21
	  fork %:vie11
	  fork %:vietel1
	  live %21
	  sti r1,%:funk1,%1
	  zjmp %:main

vie11:	   live %21
	   fork %:vie21
	   live %21
	   zjmp %:vie21

vie21:	   live %21
	   fork %:vie11
	   live %21
	   zjmp %:vie11

vietel1:	live %21
	        sti r1,%:vietel1,%1
	        live %21
	        st r1, -400
		fork %:kamikaze
	        fork %:funk1
	        zjmp %:funk1

	
kamikaze:	live %21
		add r1,r3,r3
		ld %42,r3
		sti r1,%:livetowin,%1
		st r3, -400
		fork %:kamikaze
		zjmp %:kamikaze
		zjmp %:livetowin
