.file "asm.c"
.globl main
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $16, %rsp
   
.main_BB_main:
	movl $0, -12(%rbp)
	movl -12(%rbp), %eax
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $16, %rsp
	popq %rbp
	ret
   
