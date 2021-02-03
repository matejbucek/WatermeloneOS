[extern _idt]
idtDescriptor:
	dw 4095
	dq _idt

%macro PUSHALL 0
push rax
push rcx
push rdx
push r8
push r9
push r10
push r11
%endmacro

%macro POPALL 0
pop r11
pop r10
pop r9
pop r8
pop rdx
pop rcx
pop rax
%endmacro

;[extern isr0_handler]
;global isr0
;isr0:
;	cli
;	PUSHALL
;	call isr0_handler
;	POPALL
;	sti
;	iretq

;[extern isr1_handler]
;global isr1
;isr1:
	;cli
	;PUSHALL
	;call isr1_handler
	;POPALL
	;sti
	;iretq
extern _fault_handler
global isr0
isr0:
	cli
	PUSHALL
	mov rdi, 0x0 ;first C param
	mov rsi, 0x0 ;second C param
	call _fault_handler
	POPALL
	sti
	iretq

extern _fault_handler
global isr1
isr1:
	cli
	PUSHALL
	mov rdi, 0x1 ;first C param
	mov rsi, 0x0 ;second C param
	call _fault_handler
	POPALL
	sti
	iretq


global LoadIDT
LoadIDT:
	lidt[idtDescriptor]
	sti
	ret