	.file	"basic.1_dweight.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"> Enter Height of Box \t: "
.LC1:
	.string	"%d"
.LC2:
	.string	"> Enter Width of Box \t: "
.LC3:
	.string	"> Enter Lenght of Box \t: "
.LC4:
	.string	"Dimentions \t: %dx%dx%d \n"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC5:
	.string	"Volume (cubic inchces)  \t: %d \n"
	.align 8
.LC6:
	.string	"Dimensional weight (pound)  \t: %d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$40, %rsp
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rdi
	call	printf@PLT
	leaq	12(%rsp), %rsi
	leaq	.LC1(%rip), %rbx
	movq	%rbx, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	20(%rsp), %rsi
	movq	%rbx, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	16(%rsp), %rsi
	movq	%rbx, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	12(%rsp), %esi
	movl	20(%rsp), %edx
	movl	%esi, %ebp
	imull	%edx, %ebp
	movl	16(%rsp), %ecx
	imull	%ecx, %ebp
	leal	165(%rbp), %eax
	movslq	%eax, %rbx
	imulq	$827945503, %rbx, %rbx
	sarq	$37, %rbx
	sarl	$31, %eax
	subl	%eax, %ebx
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	%ebp, %esi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	%ebx, %esi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	24(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L4
	movl	$0, %eax
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L4:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE11:
	.size	main, .-main
	.ident	"GCC: (GNU) 14.2.1 20250405"
	.section	.note.GNU-stack,"",@progbits
