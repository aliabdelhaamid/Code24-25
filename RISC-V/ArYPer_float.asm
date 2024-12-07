# Programa que calcula área y perímetro de un círculo con números reales
# -----------------------------------------------------
# Segmento de datos

		.data 0x010010000
radio:		.float 7.0		# Radio del círculo
pi:		.float 3.1416		# Número PI
		.align 2		# Alinea para 2^2 = 4 bytes
perimetro:	.space 4		# Perímetro del círculo
area:		.space 4		# Área del círculo
msg1:		.asciz "Perimetro: "
msg2:		.asciz "\nArea:"
msg3:		.asciz "\nFin\n"

# ------------------------------------------------------
# Segmento de código

	.globl main
	.text 0x00400000
main:
	la 		t0, radio		# Obtiene dirección del radio
	flw 		ft0, 0(t0)		# Lee el radio de memoria
	flw 		ft1, 4(t0)		# PI con 4 cifras fraccionarias
	li 		t2, 2			# Constante entera 2
	fcvt.s.w  	ft2, t2			# Conversión de 2 en 2.0
	



# -------------------------------------------------------
# Cálculo e impresión del perímetro

	fmul.s	fs0, ft2, ft1		# 2*PI
	fmul.s 	fs0, fs0, ft0		# 2*PI*radio
	
	la	t0, perimetro		# Obtiene dirección del perímetro
	fsw	fs0, 0(t0)		# Escribe el perímetro en memoria
	
	la	a0, msg1		# Obtiene dirección del msg1
	li	a7, 4			# PrintString
	ecall				# Imprime la cadena msg1
	
	fmv.s	fa0, fs0			# Pone perímetro en a0
	li	a7, 2			# PrintInt
	ecall				# Imprime el perímetro
	

# -------------------------------------------------------
# Cálculo e impresión del área

	fmul.s	ft2, ft1, ft0		# PI*radio
	fmul.s 	fs0, ft2, ft0		# PI*radio*radio
	
	la	t0, area		# Obtiene dirección del área
	fsw	fs0, 0(t0)		# Escribe el área en memoria
	
	la	a0, msg2		# Obtiene dirección del msg2
	li	a7, 4			# PrintString
	ecall				# Imprime la cadena msg2
	
	fmv.s	fa0, fs0			# Pone el área en a0
	li	a7, 2			# PrintInt
	ecall				# Imprime el perímetro
#-----------------------------------------------------------
# Fin del programa

	la	a0, msg3		# Obtiene dirección del msg3
	li	a7, 4			# PrintString
	ecall				# Imprime la cadena msg3
	
	li	a7, 10			# Exit
	ecall				# Finaliza la ejecución
