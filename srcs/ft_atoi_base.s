section .data
	arg1	db	"%s\n"
	arg2	db	"12345"

section	.text
	extern	_ft_write
	extern	_ft_strlen
	global	_ft_atoi_base

_ft_atoi_base:
	; xor : 명령어의 크기가 mov 명령어보다 작다.
	; r8 = 문자열 str 포인터 
	; r9 = 진법 변환된 숫자를 저장할 변수
	xor	rcx, rcx	; rcx = 0
	call	ft_isspace
	mov	rdi, rax
	
	xor	r9, r9
	
	push	rdi
	push	rsi
	mov	rdi, rsi
	call	_ft_strlen
	
	mul	r9
	
	xor	rcx, rcx
	pop	rsi
	pop	rdi

	;call	ft_convertion
	
	add	r9, rcx

	mov	rax, r9
	mov	rax, 0
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
	call	ft_isspace

ft_convertion:
	;cmp	BYTE [rdi], BYTE [rsi + rcx]
	;je	exit

	inc	rcx
	call	ft_convertion

test:	
	mov	rdi, 1
	pop	rsi
	mov	rdx, 5
	call	_ft_write

;ft_getnbr:

exit:
	ret
