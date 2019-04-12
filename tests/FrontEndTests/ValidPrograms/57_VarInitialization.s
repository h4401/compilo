.file "asm.c"
.globl main
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $16, %rsp
   
.main_BB_main:
	movl $5, -8(%rbp)
	movl -8(%rbp), %eax
	movl %eax, -4(%rbp)
	movl -4(%rbp), %eax
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $16, %rsp
	popq %rbp
	ret
   
