   .text 
.file "test.c"
.text
.global main
.type main, @function
main:
pushq  %rbp
movq %rsp, %rbp
   
movl $3, -24(%rbp)
movl $5, -28(%rbp)
movl $1, -40(%rbp)
movl -40(%rbp), (%eax)
imull -16, (%eax)
movl (%eax), -36(%rbp)
movl -12(%rbp), (%eax)
addl -36, (%eax)
movl (%eax), -32(%rbp)
popq %rbp
ret
   
