.file "2.c"
.text
.global main
.type main, @function
main:
pushq  %rbp
movq %rsp, %rbp
movl $18, -4(%rbp)
movl $0, (%eax)
popq %rbp
ret
