   .text 
.file "test.c"
.text
.global main
.type main, @function
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $-36, %rsp
   
.main_BB_main:
	movl $1, -8(%rbp)
	movl -8(%rbp), (%eax)
	movl (%eax), -4(%rbp)
	movl $2, -12(%rbp)
	movl -12(%rbp),  %(eax)
	cmpl -4(%rbp),  %(eax)
	sete %al
	movzbl %al, %eax
	movl %(eax), -16(%rbp)
	cmpl $0, -16(%rbp)
	je .main_BB_2:
	jne .main_BB_1:
.main_BB_1:
	movl $3, -20(%rbp)
	movl -20(%rbp), (%eax)
	movl (%eax), -4(%rbp)
	movl $4, -24(%rbp)
	movl -24(%rbp),  %(eax)
	cmpl -4(%rbp),  %(eax)
	sete %al
	movzbl %al, %eax
	movl %(eax), -28(%rbp)
	cmpl $0, -28(%rbp)
	je .main_BB_5:
	jne .main_BB_4:
.main_BB_4:
	movl $5, -32(%rbp)
	movl -32(%rbp), (%eax)
	movl (%eax), -4(%rbp)
	jmp .main_BB_6:
.main_BB_5:
	movl $6, -36(%rbp)
	movl -36(%rbp), (%eax)
	movl (%eax), -4(%rbp)
	jmp .main_BB_6:
.main_BB_6:
	jmp .main_BB_3:
.main_BB_2:
	movl $7, -40(%rbp)
	movl -40(%rbp), (%eax)
	movl (%eax), -4(%rbp)
	jmp .main_BB_3:
.main_BB_3:
	movl -4(%rbp), (%eax)
	jmp .main_BB_EPILOGUE:

.main_BB_EPILOGUE:
	popq %rbp
	ret
   
