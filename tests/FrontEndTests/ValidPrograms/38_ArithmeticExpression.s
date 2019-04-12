.file "asm.c"
.globl main
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $48, %rsp
   
.main_BB_main:
	movl $4, -8(%rbp)
	movl $4, -12(%rbp)
	movl $2, -16(%rbp)
	movl -16(%rbp), %eax
	imull -12(%rbp), %eax
	movl %eax, -20(%rbp)
	movl $1, -24(%rbp)
	movl -24(%rbp), %eax
	addl -20(%rbp), %eax
	movl %eax, -28(%rbp)
	movl -28(%rbp), %eax
	subl -8(%rbp), %eax
	movl %eax, -32(%rbp)
	movl -32(%rbp), %eax
	movl %eax, -4(%rbp)
	movl -4(%rbp), %eax
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $48, %rsp
	popq %rbp
	ret
   
