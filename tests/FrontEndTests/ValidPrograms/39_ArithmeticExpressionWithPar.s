.file "asm.c"
.globl main
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $48, %rsp
   
.main_BB_main:
	movl $2, -8(%rbp)
	movl $4, -12(%rbp)
	movl -12(%rbp), %eax
	subl -8(%rbp), %eax
	movl %eax, -16(%rbp)
	movl $4, -20(%rbp)
	movl $2, -24(%rbp)
	movl -24(%rbp), %eax
	imull -20(%rbp), %eax
	movl %eax, -28(%rbp)
	movl -28(%rbp), %eax
	imull -16(%rbp), %eax
	movl %eax, -32(%rbp)
	movl $1, -36(%rbp)
	movl -36(%rbp), %eax
	addl -32(%rbp), %eax
	movl %eax, -40(%rbp)
	movl -40(%rbp), %eax
	movl %eax, -4(%rbp)
	movl -4(%rbp), %eax
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $48, %rsp
	popq %rbp
	ret
   
