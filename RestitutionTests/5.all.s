.file "asm.c"
.globl main
isPositif:
	pushq  %rbp
	movq %rsp, %rbp
	subq $32, %rsp
	movq %edi, -4(%rbp)
   
.isPositif_BB_isPositif:
	movl $0, -8(%rbp)
	movl -8(%rbp),  %eax
	cmpl -4(%rbp),  %eax
	setg %al
	movzbl %al, %eax
	movl %eax, -12(%rbp)
	cmpl $0, -12(%rbp)
	je .isPositif_BB_2
	jne .isPositif_BB_1
.isPositif_BB_1:
	movl $1, -16(%rbp)
	movl -16(%rbp), %eax
	jmp .isPositif_BB_3
.isPositif_BB_2:
	movl $0, -20(%rbp)
	movl -20(%rbp), %eax
	jmp .isPositif_BB_3
.isPositif_BB_3:
	jmp .isPositif_BB_EPILOGUE
.isPositif_BB_EPILOGUE:
	addq $32, %rsp
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
	callq isPositif
	movl %eax, -16(%rbp)
	movl -16(%rbp), %eax
	movl %eax, -8(%rbp)
	movl -8(%rbp), %eax
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $32, %rsp
	popq %rbp
	ret
   
