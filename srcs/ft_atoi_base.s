section	.text
	extern	_ft_strlen
	global	_ft_atoi_base

_ft_atoi_base:
	; xor : 명령어의 크기가 mov 명령어보다 작다.
	; r8 = 진수
	; r9 = 부호 처리 변수
	; r10 = 진법 변환된 숫자를 저장할 변수

	push	rdi
	push	rsi
	mov	rdi, rsi
	call	_ft_strlen
	mov	r8, rax		; r8에 진수 저장

	xor	rcx, rcx
	pop	rsi
	pop	rdi
	call	ft_isspace
	mov	rdi, rax	; 공백 제거된 str 포인터
	
	mov	r9, 1
	call	set_sign

	xor	r10, r10	
	call	set_number
	
	mov	rax, r10
	mul	r9
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

set_sign:
	cmp	BYTE [rdi], 0x00
	je	exit

	cmp	BYTE [rdi], 0x2B
	je	multi_postive
	cmp	BYTE [rdi], 0x2D
	je	multi_negative

	ret

multi_postive:
	imul	r9, 1

	inc	rdi
	jmp	set_sign

multi_negative:
	imul	r9, -1

	inc	rdi
	jmp	set_sign

set_number:
	cmp	BYTE [rdi], 0x00
	je	exit

	xor	rcx, rcx
	call	base_convertion
	mov	rax, r8
	mul	r10
	
	mov	r10, rax

	add	r10, rcx

	inc	rdi
	jmp	set_number

base_convertion:
	mov	al, BYTE [rdi]
	mov	bl, BYTE [rsi + rcx]
	
	cmp	al, bl
	je	exit

	inc	rcx
	jmp	base_convertion

exit:
	ret
