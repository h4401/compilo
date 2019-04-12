.file "asm.c"
.globl main
toto:
	pushq  %rbp
	movq %rsp, %rbp
	subq $32, %rsp
	movl %edi, -4(%rbp)
	movl %esi, -8(%rbp)
   
.toto_BB_toto:
	movl -4(%rbp), %eax
	addl -8(%rbp), %eax
	movl %eax, -16(%rbp)
	movl -16(%rbp), %eax
	movl %eax, -12(%rbp)
	movl -12(%rbp), %eax
	jmp .toto_BB_EPILOGUE
.toto_BB_EPILOGUE:
	addq $32, %rsp
	popq %rbp
	ret
   
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $32, %rsp
   
.main_BB_main:
	movl $89, -12(%rbp)
	movl $45, -16(%rbp)
	movl -12(%rbp), %edi
	movl -16(%rbp), %esi
	callq toto
	movl %eax, -8(%rbp)
	movl -8(%rbp), %eax
	movl %eax, -4(%rbp)
	movl -4(%rbp), %eax
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $32, %rsp
	popq %rbp
	ret
   
