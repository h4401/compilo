.file "asm.c"
.globl main
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $48, %rsp
   
.main_BB_main:
	movl $0, -8(%rbp)
	movl -8(%rbp), %eax
	movl %eax, -4(%rbp)
	movl $2, -12(%rbp)
	movl $1, -16(%rbp)
	movl -12(%rbp),  %eax
	cmpl -16(%rbp),  %eax
	setl %al
	movzbl %al, %eax
	movl %eax, -20(%rbp)
	cmpl $0, -20(%rbp)
	je .main_BB_2
	jne .main_BB_1
.main_BB_1:
	movl -4(%rbp),%eax
	movl %eax, %edi
	callq toto
	movl %eax, -24(%rbp)
	jmp .main_BB_3
.main_BB_2:
	movl -4(%rbp),%eax
	movl %eax, %edi
	callq toto
	movl %eax, -28(%rbp)
	jmp .main_BB_3
.main_BB_3:
	movl -4(%rbp),%eax
	movl %eax, %edi
	callq toto
	movl %eax, -32(%rbp)
	movl $0, -36(%rbp)
	movl -36(%rbp), %eax
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $48, %rsp
	popq %rbp
	ret
   
toto:
	pushq  %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq %edi, -4(%rbp)
   
.toto_BB_toto:
	movl -4(%rbp), %eax
	jmp .toto_BB_EPILOGUE
.toto_BB_EPILOGUE:
	addq $16, %rsp
	popq %rbp
	ret
   
