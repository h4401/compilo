.file "asm.c"
.globl main
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $32, %rsp
   
.main_BB_main:
	movl $1, -8(%rbp)
	movl $2, -12(%rbp)
	movl -12(%rbp), %eax
	subl -8(%rbp), %eax
	movl %eax, !tmp-16(%rbp)
	movl -16(%rbp), %eax
	movl %eax, -4(%rbp)
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $32, %rsp
	popq %rbp
	ret
   
