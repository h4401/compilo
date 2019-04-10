   .text 
.file "test.c"
.text
.global main
.type main, @function
main:
pushq  %rbp
movq %rsp, %rbp
subq $-28, %rsp
movq %rdi, 8%(rbp)
movq %rsi, 12%(rbp)
   
<<<<<<< Updated upstream
movl $3, -24(%rbp)
movl -24(%rbp), (%eax)
movl (%eax), -12(%rbp)
movl $5, -28(%rbp)
movl -28(%rbp), (%eax)
movl (%eax), -16(%rbp)
movl $1, -40(%rbp)
movl -40(%rbp), (%eax)
imull -16, (%eax)
movl (%eax), -36(%rbp)
movl -12(%rbp), (%eax)
addl -36, (%eax)
movl (%eax), -32(%rbp)
movl -32(%rbp), (%eax)
movl (%eax), -20(%rbp)
movl -12(%rbp), (%eax)
popq %rbp
ret
   
.file "test.c"
.text
.global main
.type main, @function
main:
pushq  %rbp
movq %rsp, %rbp
   
movl $0, -4(%rbp)
movl -4(%rbp), (%eax)
=======
movl $3, -16(%rbp)
movl $5, -20(%rbp)
movl $1, -32(%rbp)
movl -32(%rbp), (%eax)
imull -8, (%eax)
movl (%eax), -28(%rbp)
movl -4(%rbp), (%eax)
addl -28, (%eax)
movl (%eax), -24(%rbp)
>>>>>>> Stashed changes
popq %rbp
ret
   
