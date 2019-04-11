.file "asm.c"
.globl main
toto:
	pushq  %rbp
	movq %rsp, %rbp
	subq $16, %rsp
   
.toto_BB_toto:
	jmp .toto_BB_EPILOGUE
.toto_BB_EPILOGUE:
	addq $16, %rsp
	popq %rbp
	ret
   
