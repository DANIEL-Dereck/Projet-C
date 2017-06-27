.name "Staline"
.comment "Staline - Добро пожаловать в Сталинград"

l2:	sti r1,%:live,%1
	and r1,%0,r1

live:	 live %42
	 sti	r1,%:l2,%500
	 zjmp %:lenine


lenine:	live    %42
        fork    %:staline
	sti	r1,%:live,%500
        live    %42
	fork    %:live
	ld      %251883526,r3           #0F 03 70 06
	ld      %386101254,r6           #17 03 70 06
	ld      %0,r15
	ld      %0,r15
	zjmp    %:live
	zjmp    %:l2
	

staline:	live    %42
	        fork    %:staline
	        live    %42
		fork    %:live
		ld      %251883526,r3           #0F 03 70 06
		ld      %386101254,r6           #17 03 70 06
		ld      %0,r15
		zjmp    %:l2
		ld      %0,r15
		sti	r1,%:live,%500
 		zjmp    %:live
		zjmp	%:l2
