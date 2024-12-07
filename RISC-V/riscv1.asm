#Programa que imprime la cadena "Hola mundo"
#-------------------------------------------------------------
# Segmento de datos
	.data 0x10010000	#inicio de segmento de datos
cadena:	.asciz "Hola mundo\n"	# cadena a imprimir

#------------------------------------------------------------------------
# Segmento de código

	.text 0x00400000 	#inicio segmento de código	
	.globl main

main:	la	a0, cadena	# a0 = dirección de cadena
	li	a7, 4		# PrintString
	ecall
	
	li	a7, 10		# Exit
	ecall			# Fin del programa
	