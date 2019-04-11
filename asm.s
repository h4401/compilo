main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $32, %rsp
	movq %rdi, -4%(rbp)
	movq %rsi, -8%(rbp)
	movq %rdx, -12%(rbp)
   
.main_BB_main:
	movl $0, -16(%rbp)
	movl -16(%rbp), (%eax)
	jmp .main_BB_EPILOGUE
	addq $32, %rsp
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
   
