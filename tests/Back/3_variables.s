.file "asm.c"
.globl main
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $32, %rsp
   
.main_BB_main:
	movl $0, -16(%rbp)
	movl -16(%rbp), %eax
	movl %eax, -4(%rbp)
	movl -4(%rbp), %eax
	movl %eax, -8(%rbp)
	movl -8(%rbp), %eax
	movl %eax, -12(%rbp)
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $32, %rsp
	popq %rbp
	ret
   