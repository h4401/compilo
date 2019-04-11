.file "asm.c"
.globl main
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $48, %rsp
   
.main_BB_main:
	movl $2, -8(%rbp)
	movl $1, -12(%rbp)
	cmpl $0, -16(%rbp)
	je .main_BB_2
	jne .main_BB_1
.main_BB_1:
	movl $0, -20(%rbp)
	movl -20(%rbp), %eax
	movl %eax, -8(%rbp)
	movq -8(%rbp), %rdi
	callq toto
	movl %eax, -24(%rbp)
	jmp .main_BB_3
.main_BB_2:
	movq -8(%rbp), %rdi
	callq toto
	movl %eax, -28(%rbp)
	jmp .main_BB_3
.main_BB_3:
	movq -8(%rbp), %rdi
	callq toto
	movl %eax, -32(%rbp)
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $48, %rsp
	popq %rbp
	ret
   
toto:
	pushq  %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq %rdi, -4(%rbp)
   
.toto_BB_toto:
	movl -4(%rbp), %eax
	jmp .toto_BB_EPILOGUE
.toto_BB_EPILOGUE:
	addq $16, %rsp
	popq %rbp
	ret
   
