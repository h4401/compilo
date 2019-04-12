.file "asm.c"
.globl main
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $64, %rsp
   
.main_BB_main:
	movl $2, -8(%rbp)
	movl $2, -12(%rbp)
	movl $4, -16(%rbp)
	movl -16(%rbp), %eax
	idivl -12(%rbp), %eax
	movl %eax, -20(%rbp)
	movl -20(%rbp), %eax
	subl -8(%rbp), %eax
	movl %eax, -24(%rbp)
	movl $4, -28(%rbp)
	movl $2, -32(%rbp)
	movl -32(%rbp), %eax
	imull -28(%rbp), %eax
	movl %eax, -36(%rbp)
	movl $1, -40(%rbp)
	movl -40(%rbp), %eax
	addl -36(%rbp), %eax
	movl %eax, -44(%rbp)
	movl -44(%rbp), %eax
	subl -24(%rbp), %eax
	movl %eax, -48(%rbp)
	movl -48(%rbp), %eax
	movl %eax, -4(%rbp)
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $64, %rsp
	popq %rbp
	ret
   
