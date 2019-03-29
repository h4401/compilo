.file "2.c"
.text
.global main
.type main, @function
main:
pushq  %rbp
movq %rsp, %rbp
movl $17, -4(%rbp)
movl $42, -8(%rbp)
movl -4(%rbp), (%eax)
imull -4(%rbp), (%eax)
movl (%eax), -16(%rbp)
movl -8(%rbp), (%eax)
imull -8(%rbp), (%eax)
movl (%eax), -20(%rbp)
movl -16(%rbp), (%eax)
addl -20(%rbp), (%eax)
movl (%eax), -24(%rbp)
movl -24(%rbp), (%eax)
addl $1, (%eax)
movl (%eax), -28(%rbp)
movl -28(%rbp), (%eax)
movl (%eax), -12(%rbp)
movl -4(%rbp), (%eax)
addl -8(%rbp), (%eax)
movl (%eax), -32(%rbp)
movl -32(%rbp), (%eax)
popq %rbp
ret
