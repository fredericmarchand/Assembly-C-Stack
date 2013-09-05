;Assembly language program  A4.ASM
;         Objective: 	Convert a string of Hex digits into a decimal number
;			after verifying that all digits are valid
;         Inputs:       A string of Hex characters
;         Output:     	A decimal value


segment .data			
segment .text
global  convert
extern	getDecimal
extern  checkDigit
	
convert: 	
			push    EBP			; push EBP
                	mov     EBP,ESP			; store the stack pointer
                	push    EDX			; push EDX
			push    EBX			; push EBX
			push	ESI			; push ESI
			xor 	ECX, ECX		; empty ECX
			xor 	EBX, EBX		; empty EBX
                	xor     EDX,EDX			; empty EDX
                	mov     EBX, [EBP+8]    	; copy the string to EBX
			mov	ECX, [EBP+12]		; get the loop counter
the_loop:
			mov 	EDX, [EBX+0]		; put the first character in EDX
			push    EDX                     ; pass character to interpret
                	call    checkDigit		; call the c function to check if the hex digit is valid
			add	ESP, 4			; clear the stack
			xor 	ESI, ESI		; empty the b register
			mov 	ESI, 1			; put 1 in ESI
			cmp 	EAX, ESI		; check if the return value of the c function was a 1
			je	invalid			; if it wasnt jump to the next digit if available
			inc 	EBX			; increment EBX
			mov	EDI, 0			; put 0 in EDI
			loop	the_loop		; otherwise, loop back
			mov	EDX, [EBP+8]		; put the string in EDX
			push	EDX			; push EDX
			call	getDecimal		; call the getDecimal function
			add	ESP,4			; clear the stack
			jmp	end			; jump to end

invalid:		
			mov 	EAX, -1			; otherwise, put -1 in EAX as the return value to the main c function
			jmp	end			; then jump to end the assembly function
end:			
			pop 	ESI			; restore ESI
			pop 	EBX			; restore EBX
			pop     EDX		        ; restore EDX
                	pop     EBP			; restore EBP
                	ret				; return



			
