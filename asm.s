main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $48, %rsp
	movq %rdi, -4%(rbp)
	movq %rsi, -8%(rbp)
	movq %rdx, -12%(rbp)
	movq %rcx, -16%(rbp)
   
.main_BB_main:
	movl $1, -24(%rbp)
	movl -24(%rbp), (%eax)
	movl (%eax), -20(%rbp)
	movl $1, -32(%rbp)
	movq -32(%rbp), %rdi
	callq test
	movl %eax, (%rbp)-28
	movl -20(%rbp), (%eax)
	jmp .main_BB_EPILOGUE
	addq $48, %rsp
	popq %rbp
	ret
   
test:
	pushq  %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq %rdi, -4%(rbp)
   
.test_BB_test:
	movl -4(%rbp), (%eax)
	jmp .test_BB_EPILOGUE
	addq $16, %rsp
	popq %rbp
	ret
   
