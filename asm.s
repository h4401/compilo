   .text 
.file "test.c"
.text
.global main
.type main, @function
main:
pushq  %rbp
movq %rsp, %rbp
   
movl $3, !tmp12(%rbp)
movl $5, !tmp16(%rbp)
movl $1, !tmp28(%rbp)
popq %rbp
ret
   
