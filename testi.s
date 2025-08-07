	.file	"cQueue.c"
	.comm	_queue, 20, 2
	.globl	_front
	.data
	.align 4
_front:
	.long	-1
	.globl	_rear
	.align 4
_rear:
	.long	-1
	.section .rdata,"dr"
LC0:
	.ascii "Queue Overflow\0"
LC1:
	.ascii "%d Inserted\12\0"
	.text
	.globl	_enqueue
	.def	_enqueue;	.scl	2;	.type	32;	.endef
_enqueue:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	_rear, %eax
	leal	1(%eax), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	movl	_front, %eax
	cmpl	%eax, %edx
	jne	L2
	movl	$LC0, (%esp)
	call	_puts
	jmp	L6
L2:
	movl	_front, %eax
	cmpl	$-1, %eax
	jne	L4
	movl	$0, _rear
	movl	_rear, %eax
	movl	%eax, _front
	jmp	L5
L4:
	movl	_rear, %eax
	leal	1(%eax), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	%ecx, %eax
	subl	%edx, %eax
	movl	%eax, _rear
L5:
	movl	_rear, %eax
	movl	8(%ebp), %edx
	movl	%edx, _queue(,%eax,4)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
L6:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.section .rdata,"dr"
LC2:
	.ascii "Queue Underflow\0"
LC3:
	.ascii "%d deleted\12\0"
	.text
	.globl	_dequeue
	.def	_dequeue;	.scl	2;	.type	32;	.endef
_dequeue:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	_front, %eax
	cmpl	$-1, %eax
	jne	L8
	movl	$LC2, (%esp)
	call	_puts
	jmp	L11
L8:
	movl	_front, %eax
	movl	_queue(,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	_front, %edx
	movl	_rear, %eax
	cmpl	%eax, %edx
	jne	L10
	movl	$-1, _rear
	movl	_rear, %eax
	movl	%eax, _front
	jmp	L11
L10:
	movl	_front, %eax
	leal	1(%eax), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	%ecx, %eax
	subl	%edx, %eax
	movl	%eax, _front
L11:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.section .rdata,"dr"
LC4:
	.ascii "Queue is empty\0"
LC5:
	.ascii "Queue elements: \0"
LC6:
	.ascii "%d \0"
	.text
	.globl	_display
	.def	_display;	.scl	2;	.type	32;	.endef
_display:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	_front, %eax
	cmpl	$-1, %eax
	jne	L13
	movl	$LC4, (%esp)
	call	_puts
	jmp	L20
L13:
	movl	$LC5, (%esp)
	call	_printf
	movl	_front, %eax
	movl	%eax, -12(%ebp)
L17:
	movl	-12(%ebp), %eax
	movl	_queue(,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	_rear, %eax
	cmpl	%eax, -12(%ebp)
	je	L19
	movl	-12(%ebp), %eax
	leal	1(%eax), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -12(%ebp)
	jmp	L17
L19:
	nop
	movl	$10, (%esp)
	call	_putchar
L20:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	$10, (%esp)
	call	_enqueue
	movl	$20, (%esp)
	call	_enqueue
	movl	$30, (%esp)
	call	_enqueue
	movl	$40, (%esp)
	call	_enqueue
	call	_display
	call	_dequeue
	call	_dequeue
	call	_display
	movl	$50, (%esp)
	call	_enqueue
	movl	$60, (%esp)
	call	_enqueue
	call	_display
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
