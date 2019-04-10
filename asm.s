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
   
movl $3, -16(%rbp)
movl -16(%rbp), (%eax)
movl (%eax), -4(%rbp)
movl $5, -20(%rbp)
movl -20(%rbp), (%eax)
movl (%eax), -8(%rbp)
movl $1, -32(%rbp)
movl -32(%rbp), (%eax)
imull -8, (%eax)
movl (%eax), -28(%rbp)
movl -4(%rbp), (%eax)
addl -28, (%eax)
movl (%eax), -24(%rbp)
movl -24(%rbp), (%eax)
movl (%eax), -12(%rbp)
movl -4(%rbp), (%eax)
popq %rbp
ret
   
.file "test.c"
.text
.global main
.type main, @function
main:
pushq  %rbp
movq %rsp, %rbp
subq $0, %rsp
movq %rdi, 8%(rbp)
movq %rsi, 12%(rbp)
   
movl $0, -4(%rbp)
movl -4(%rbp), (%eax)
popq %rbp
ret
   
