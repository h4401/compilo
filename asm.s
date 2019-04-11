   .text 
.file "test.c"
.text
.global main
.type main, @function
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $-16, %rsp
   
.main_BB_main:
	movl $3, -8(%rbp)
	movl -8(%rbp), (%eax)
	movl (%eax), -4(%rbp)
	movl $3, -12(%rbp)
	movl -12(%rbp),  %(eax)
	cmpl -4(%rbp),  %(eax)
	sete %al
	movzbl %al, %eax
	movl %(eax), -16(%rbp)
	cmpl $0, -16(%rbp)
	je .main_BB_2:
	jne .main_BB_1:
.main_BB_1:
	movl $2, -20(%rbp)
	movl -20(%rbp), (%eax)
	movl (%eax), -4(%rbp)
	jmp .main_BB_3:
.main_BB_2:
	jmp .main_BB_3:
.main_BB_3:
	movl -4(%rbp), (%eax)
	jmp .main_BB_EPILOGUE:

.main_BB_EPILOGUE:
	popq %rbp
	ret
   
.file "test.c"
.text
.global main
.type main, @function
main:
	pushq  %rbp
	movq %rsp, %rbp
	subq $-16, %rsp
   
.x_BB_x:
	movl $3, -8(%rbp)
	movl -8(%rbp), (%eax)
	movl (%eax), -4(%rbp)
	movl $2, -12(%rbp)
	movl -12(%rbp),  %(eax)
	cmpl -4(%rbp),  %(eax)
	sete %al
	movzbl %al, %eax
	movl %(eax), -16(%rbp)
	cmpl $0, -16(%rbp)
	je .x_BB_2:
	jne .x_BB_1:
.x_BB_1:
	jmp .x_BB_2:
.x_BB_2:
	movl $2, -20(%rbp)
	movl -20(%rbp), (%eax)
	jmp .x_BB_EPILOGUE:

.x_BB_EPILOGUE:
	popq %rbp
	ret
   
