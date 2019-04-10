   .text 
.file "test.c"
.text
.global main
.type main, @function
main:
pushq  %rbp
movq %rsp, %rbp
subq $-20, %rsp
   
.main_BB:
movl $3, -8(%rbp)
movl -8(%rbp), (%eax)
movl (%eax), -4(%rbp)
movl $5, -16(%rbp)
movl -16(%rbp),  %eax
cmpl -4(%rbp),  %eax
jne .2_BB
.1_BB:
movl $1, -20(%rbp)
movl -20(%rbp), (%eax)
movl (%eax), -4(%rbp)
jmp .3_BB
.2_BB:
movl $2, -24(%rbp)
movl -24(%rbp), (%eax)
movl (%eax), -4(%rbp)
jmp .3_BB
.3_BB:
movl -4(%rbp), (%eax)
jmp .EPILOGUE_BB
popq %rbp
ret
   
