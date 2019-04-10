   .text 
.file "test.c"
.text
.global main
.type main, @function
main:
pushq  %rbp
movq %rsp, %rbp
   
movl $3, -12(%rbp)
movl $5, -16(%rbp)
movl $1, -28(%rbp)
movl -28(%rbp), (%eax)
imull -8, (%eax)
movl (%eax), -24(%rbp)
movl -4(%rbp), (%eax)
addl -24, (%eax)
movl (%eax), -20(%rbp)
popq %rbp
ret
   
