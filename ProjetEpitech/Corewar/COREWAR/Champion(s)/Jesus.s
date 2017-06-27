.name		"jesus1"
.comment	"jesus est parmis nous"

l2:
	live	%1
	fork	%:live
	zjmp	%:l2

live:
	live	%1
	fork	%:t1
	live	%1
	fork	%:t2
	live	%1
	fork	%:t3
	live	%1
	zjmp	%:live

t1:
	ld	%604321456,r5
	ld	%10,r12
	ld	%1,r2
	ld	%1,r2
	ld	%1,r2
	zjmp	%:tir

t2:
	ld	%708465312,r20
	ld	%10,r13
	ld	%1,r3
	ld	%1,r3
	ld	%1,r3
	zjmp	%:tir

t3:	
	ld	%100415852,r140
	ld	%10,r14
	ld	%1,r4
	ld	%1,r4
	ld	%1,r4
	zjmp	%:tir

tir:

	st	r4,-10
	st	r4,-10
	st	r4,-10
#	st	r4,111
#	st	r4,111
#	st	r4,111
	st	r1,10
	fork	%:live
	st	r2,100
	zjmp	%:live
