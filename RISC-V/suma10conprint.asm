#Suma de los cuadrados de los primeros 10 números naturales
#----------------------------------------------------------

		.data 0x10010000
cadena:		.asciz "Resultado: "

		.text 0x00400000
		.globl main
main:
		li		t0, 10		# límite n
		li		s0, 0		# contador i a cero
		fmv.s.x		t1, 0		# suma parcial a cero
		
bucle:
		addi		t1,t1,1		# i++
		mul 		t2, t1, t1	# cálculo de i * i, asignem a t0 la múltiplicació de t0*t0
		add		s0, s0, t2	# incremento suma parcial, asignem a fs0 la suma de s0 + t0
		bne		t1, t0, bucle	# sale si contador = 10 , va de t1 = 0 fins t0 = 10
		
		la		a0, cadena	# a0 = dirección de la cadena
		li 		a7, 4		# print_string
		ecall				# imprime la cadena
		
		fmv.s 		a0, s0		# a0 = resultado
		li		a7, 1		# PrintInt
		ecall				# imprime el resultado
		
		li		a7, 10		# Exit
		ecall				# fin del programa	