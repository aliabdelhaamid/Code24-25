# Programa que calcula área y perímetro de un círculo con números enteros
# -----------------------------------------------------
# Segmento de datos

		.data 0x10010000
radio:		.word 7			# Radio del círculo
		.align 2		# Alinea para 2^2 = 4 bytes
perimetro:	.space 4		# Perímetro del círculo
area:		.space 4		# Área del círculo
msg1:		.asciz "Perímetro: "
msg2:		.asciz "\nÁrea: "
msg3:		.asciz "\nFin\n"

# ------------------------------------------------------
# Segmento de código

	.globl main
	.text 0x00400000
main:
	la t0, radio			# Obtiene dirección del radio
	lw s0, 0(t0)			# Lee el radio de memoria
	li t1, 31416			# PI con 4 cifras fraccionarias
	li t2, 2
	



# -------------------------------------------------------
# Cálculo e impresión del perímetro

	mul	t2, t1, t2		# 2*PI
	mul 	t2, t2, s0		#2*PI*radio
	
	la	t0, perimetro		# Obtiene dirección del perímetro
	sw	t2, 0(t0)		# Escribe el perímetro en memoria
	
	la	a0, msg1		# Obtiene dirección del msg1
	li	a7, 4			# PrintString
	ecall				# Imprime la cadena msg1
	
	mv	a0, t2			# Pone perímetro en a0
	li	a7, 1			# PrintInt
	ecall				# Imprime el perímetro
	

# -------------------------------------------------------
# Cálculo e impresión del área

	mul	t2, t1, s0		# PI*radio
	mul 	t2, t2, s0		# PI*radio*radio
	
	la	t0, area		# Obtiene dirección del área
	sw	t2, 0(t0)		# Escribe el área en memoria
	
	la	a0, msg2		# Obtiene dirección del msg2
	li	a7, 4			# PrintString
	ecall				# Imprime la cadena msg2
	
	mv	a0, t2			# Pone el área en a0
	li	a7, 1			# PrintInt
	ecall				# Imprime el perímetro
#-----------------------------------------------------------
# Fin del programa

	la	a0, msg3		# Obtiene dirección del msg3
	li	a7, 4			# PrintString
	ecall				# Imprime la cadena msg3
	
	li	a7, 10			# Exit
	ecall				# Finaliza la ejecución
