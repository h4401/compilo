.file "asm.c"
.globl main
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $32, %rsp
   
.main_BB_main:
	movl $3, -8(%rbp)
	movl $2, -12(%rbp)
	movl $1, -16(%rbp)
	movl -16(%rbp), %eax
	addl -12(%rbp), %eax
	movl %eax, -20(%rbp)
	movl -20(%rbp), %eax
	imull -8(%rbp), %eax
	movl %eax, -24(%rbp)
	movl -24(%rbp), %eax
	movl %eax, -4(%rbp)
	movl -4(%rbp), %eax
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $32, %rsp
	popq %rbp
	ret
   
