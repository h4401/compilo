   .text 
.file "test.c"
.text
.global main
.type main, @function
main:
pushq  %rbp
movq %rsp, %rbp
   
movl $2, !tmp12(%rbp)
movl $1, !tmp20(%rbp)
movl $1, !tmp36(%rbp)
popq %rbp
ret
   
