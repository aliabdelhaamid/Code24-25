# Suma de los cuadrados de los primeros 10 números naturales
# --------------------------------------------------------------

	.text 0x00400000
	.globl main
main:	
	li t0, 10		# límite n
	li s0, 0		# suma parcial a cero
	li t1, 0		# contador i a cero
bucle:
	addi 	t1, t1, 1	# i++
	mul	t2, t1, t1	# calculo de i*i
	add	s0, s0, t2	# incremento suma parcial
	bne	t1, t0, bucle	# sale si contador = 10
	
	li	a7, 10		# Exit
	ecall			# fin del programa 