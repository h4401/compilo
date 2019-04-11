.file "asm.c"
.globl main
function:
	pushq  %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq %rdi, -4(%rbp)
   
.function_BB_function:
	movl $1, -8(%rbp)
	movl -4(%rbp), %eax
	addl -8(%rbp), %eax
	movl %eax, -12(%rbp)
	movl -12(%rbp), %eax
	jmp .function_BB_EPILOGUE
.function_BB_EPILOGUE:
	addq $16, %rsp
	popq %rbp
	ret
   
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $16, %rsp
   
.main_BB_main:
	movl $1, -8(%rbp)
	movl -8(%rbp), %eax
	movl %eax, -4(%rbp)
	movq -4(%rbp), %rdi
	callq function
	movl %eax, -12(%rbp)
	movl -12(%rbp), %eax
	movl %eax, -4(%rbp)
	jmp .main_BB_EPILOGUE
.main_BB_EPILOGUE:
	addq $16, %rsp
	popq %rbp
	ret
   
