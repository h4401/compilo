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
	movq -4(%rbp), %rdi
	callq test
	movl %eax, -12(%rbp)
	movl -12(%rbp), %eax
	movl %eax, -4(%rbp)
	movl $0, -16(%rbp)
	movl -16(%rbp), %eax
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $32, %rsp
	popq %rbp
	ret
   
test:
	pushq  %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq %rdi, -4%(rbp)
   
.test_BB_test:
	movl -4(%rbp), %eax
	jmp .test_BB_EPILOGUE
.test_BB_EPILOGUE:
	addq $16, %rsp
	popq %rbp
	ret
   
