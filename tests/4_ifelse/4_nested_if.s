.file "asm.c"
.globl main
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $48, %rsp
   
.main_BB_main:
	movl $4, -8(%rbp)
	movl -8(%rbp), %eax
	movl %eax, -4(%rbp)
	movl $4, -12(%rbp)
	movl -12(%rbp),  %eax
	cmpl -4(%rbp),  %eax
	sete %al
	movzbl %al, %eax
	movl %eax, -16(%rbp)
	cmpl $0, -16(%rbp)
	je .main_BB_2
	jne .main_BB_1
.main_BB_1:
	movl $3, -20(%rbp)
	movl -20(%rbp), %eax
	movl %eax, -4(%rbp)
	movl $3, -24(%rbp)
	movl -24(%rbp),  %eax
	cmpl -4(%rbp),  %eax
	sete %al
	movzbl %al, %eax
	movl %eax, -28(%rbp)
	cmpl $0, -28(%rbp)
	je .main_BB_4
	jne .main_BB_3
.main_BB_3:
	movl $2, -32(%rbp)
	movl -32(%rbp), %eax
	jmp .main_BB_4
.main_BB_4:
	movl $0, -36(%rbp)
	movl -36(%rbp), %eax
	jmp .main_BB_2
.main_BB_2:
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $48, %rsp
	popq %rbp
	ret
   
