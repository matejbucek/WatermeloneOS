section .multiboot_header
header_start:
    dd 0xe85250d6 ; magic number - multiboot2
    dd 0 ; architecture - protected mode i386 
    dd header_end - header_start ; header length
    dd 0x100000000 - (0xe85250d6 + 0 + header_end - header_start) ; checksum

    ; end tag
    ;dw 0
    ;dw 0
    ;dd 8
    dd 0   ; header_addr
    dd 0   ; load_addr
    dd 0   ; load_end_addr
    dd 0   ; bss_end_addr
    dd 0   ; entry_addr

    ; graphics tag
    dd 0   ; mode_type
    dd 800 ; width
    dd 600 ; height
    dd 32  ; depth
header_end:
