.file "asm.c"
.globl main
factoriel:
	pushq  %rbp
	movq %rsp, %rbp
	subq $48, %rsp
	movl %edi, -4(%rbp)
   
.factoriel_BB_factoriel:
	movl $1, -8(%rbp)
	movl -4(%rbp),  %eax
	cmpl -8(%rbp),  %eax
	setle %al
	movzbl %al, %eax
	movl %eax, -12(%rbp)
	cmpl $0, -12(%rbp)
	je .factoriel_BB_2
	jne .factoriel_BB_1
.factoriel_BB_1:
	movl $1, -16(%rbp)
	movl -16(%rbp), %eax
	jmp .factoriel_BB_3
.factoriel_BB_2:
	movl $1, -24(%rbp)
	movl -4(%rbp), %eax
	subl -24(%rbp), %eax
	movl %eax, -28(%rbp)
	movl -28(%rbp),%eax
	movl %eax, %edi
	callq factoriel
	movl %eax, -20(%rbp)
	movl -4(%rbp), %eax
	imull -20(%rbp), %eax
	movl %eax, -32(%rbp)
	movl -32(%rbp), %eax
	jmp .factoriel_BB_3
.factoriel_BB_3:
	jmp .factoriel_BB_EPILOGUE
.factoriel_BB_EPILOGUE:
	addq $48, %rsp
	popq %rbp
	ret
   
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $32, %rsp
   
.main_BB_main:
	movl $5, -12(%rbp)
	movl -12(%rbp), %eax
	movl %eax, -4(%rbp)
	movl -4(%rbp),%eax
	movl %eax, %edi
	callq factoriel
	movl %eax, -16(%rbp)
	movl -16(%rbp), %eax
	movl %eax, -8(%rbp)
	movl -8(%rbp), %eax
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $32, %rsp
	popq %rbp
	ret
   
