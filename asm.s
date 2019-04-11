   .text 
	pushq  %rbp
	movq %rsp, %rbp
	subq $32, %rsp
   
.main_BB_main:
	movl $2, -12(%rbp)
	movl -12(%rbp), (%eax)
	movl (%eax), -4(%rbp)
	movl $3, -16(%rbp)
	movl -16(%rbp), (%eax)
	movl (%eax), -8(%rbp)
	movq -4(%rbp), %rdi
	movq -8(%rbp), %rsi
	callq test
	movl %eax, (%rbp)-20
	movl $2, -24(%rbp)
	movl -24(%rbp), (%eax)
	jmp .main_BB_EPILOGUE
	addq $32, %rsp
	popq %rbp
	ret
   
	pushq  %rbp
	movq %rsp, %rbp
	subq $16, %rsp
   
.test_BB_test:
	movl $0, -4(%rbp)
	movl -4(%rbp), (%eax)
	jmp .test_BB_EPILOGUE
	addq $16, %rsp
	popq %rbp
	ret
   
