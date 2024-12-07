#Suma de los cuadrados de los primeros 10 números naturales
#----------------------------------------------------------

		.data 0x10010000
cadena:		.asciz "Resultado: "

		.text 0x00400000
		.globl main
main:
		li		t0, 10		# límite n
		li		t1, 0		# contador i a cero
		fmv.s.x		fs0, zero	# suma parcial a cero
		
bucle:
		addi		t1,t1,1		# i++
		fcvt.s.w	ft0, t1		# (float) i, es un type casting
		fmul.s 		ft0, ft0, ft0	# cálculo de i * i, asignem a ft0 la múltiplicació de ft0*ft0
		fadd.s		fs0, fs0, ft0	# incremento suma, asignem a fs0 la suma de fs0 + ft0
		bne		t1, t0, bucle	# sale si contador = 10 , va de t1 = 0 fins t0 = 10
		
		la		a0, cadena	# a0 = dirección de la cadena
		li 		a7, 4		# print_string
		ecall				# imprime la cadena
		
		fmv.s 		fa0, fs0	# fa0 = resultado
		li		a7, 2		# PrintFloat
		ecall				# imprime el resultado
		
		li		a7, 10		# Exit
		ecall				# fin del programa	