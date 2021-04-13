section	.text
	extern	_ft_strlen
	global	_ft_atoi_base

_ft_atoi_base:
	; xor : 명령어의 크기가 mov 명령어보다 작다.
	; r8 = 문자열 str 포인터 
	; r9 = 진법 변환된 숫자를 저장할 변수
	; r10 = 진수
	xor	rcx, rcx	; rcx = 0
	call	ft_isspace
	mov	rdi, rax
	
	push	rdi
	push	rsi
	mov	rdi, rsi
	call	_ft_strlen
	
	mov	r10, rax
	
	pop	rsi
	pop	rdi

	xor	r9, r9
	call	set_number
	
	mov	rax, r9
	ret

ft_isspace:
	cmp	BYTE [rdi], 0x00
	je	exit

	cmp	BYTE [rdi], 0x20 ; SP(Space)
	je	increase_count

	cmp	BYTE [rdi], 0x09 ; HT(Horizontal Tab)
	je	increase_count

	cmp	BYTE [rdi], 0x0A ; LF(Line Feed)
	je	increase_count

	cmp	BYTE [rdi], 0x0B ; VT(Vertical Tab)
	je	increase_count
	
	cmp	BYTE [rdi], 0x0C ; FF(Form Feed)
	je	increase_count
	
	cmp	BYTE [rdi], 0x0D ; CR(Carriage Return)
	je	increase_count
	
	mov	rax, rdi
	ret

increase_count:
	inc	rdi
	jmp	ft_isspace

set_number:
	cmp	BYTE [rdi], 0x00
	je	exit

	xor	rcx, rcx
	call	ft_convertion
	mov	rax, r10
	mul	r9
	
	mov	r9, rax

	add	r9, rcx

	inc	rdi
	jmp	set_number

ft_convertion:
	mov	al, BYTE [rdi]
	mov	bl, BYTE [rsi + rcx]
	
	cmp	al, bl
	je	exit

	inc	rcx
	jmp	ft_convertion

exit:
	ret
