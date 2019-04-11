.file "asm.c"
.globl main
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $32, %rsp
   
.main_BB_main:
	movl $1, -8(%rbp)
	movl -8(%rbp), %eax
	movl %eax, -4(%rbp)
	movl $1, -12(%rbp)
	movl -12(%rbp),  %eax
	cmpl -4(%rbp),  %eax
	sete %al
	movzbl %al, %eax
	movl %eax, -16(%rbp)
	cmpl $0, -16(%rbp)
	je .main_BB_2
	jne .main_BB_1
.main_BB_1:
	movl $2, -20(%rbp)
	movl -20(%rbp), %eax
	movl %eax, -4(%rbp)
	jmp .main_BB_3
.main_BB_2:
	movl $3, -24(%rbp)
	movl -24(%rbp), %eax
	movl %eax, -4(%rbp)
	jmp .main_BB_3
.main_BB_3:
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $32, %rsp
	popq %rbp
	ret
   
