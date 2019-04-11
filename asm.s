.file "asm.c"
.globl main
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $16, %rsp
   
.main_BB_main:
	movl $2, -4(%rbp)
	movl $1, -8(%rbp)
	movl -8(%rbp), %eax
	addl -4, %eax
	movl %eax, -12(%rbp)
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $16, %rsp
	popq %rbp
	ret
   
