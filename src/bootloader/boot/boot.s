;
;  boot.s
;  GunwOS Bootloader
;  Part of GunwOS project
;
;  Created by Artur Danielewski on 08.01.2018.
;

ORG 0x7c00

BITS 16

RMODE_STACK_ADDR            equ 0x700
FAT_HEADER_ADDR             equ 0x1000
SECOND_STAGE_SEG            equ 0x1000

%include "../shared/data.s"

jmp boot_init

    ; ---------------------------------------
    ; IMPORTANT NOTE
    ; 
    ; DL register contains boot drive number
    ; remember not to overwrite it
    ; ---------------------------------------

    ; ---------------------------------------
    ; FAT reserved sectors
    ; 
    ; OEM name
    ; ---------------------------------------
oem_name:   db "GunwOS  "
    
    ; ---------------------------------------
    ; FAT reserved sectors
    ; 
    ; BIOS parameter block
    ; ---------------------------------------
%include "bpb.s"

BITS 16

boot_init:
    ; ---------------------------------------
    ; Clear accumulator and segment registers
    ; ---------------------------------------
    mov ax, 0x00
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; ---------------------------------------
    ; Configure stack
    ; ---------------------------------------
    mov bp, RMODE_STACK_ADDR
    mov sp, bp
    xor bp, bp

boot_load_2nd_stage:
    ; ---------------------------------------
    ; Fetch 2nd stage loader from filesystem 
    ; ---------------------------------------
    mov ax, BOOT_2ND_STAGE_FILENAME
    mov si, FAT_HEADER_ADDR
    mov di, SECOND_STAGE_SEG
    call fat12_loadFile

boot_2nd_stage:
    ; ---------------------------------------
    ; Jump to preloader (2-nd stage)
    ; ---------------------------------------
    jmp SECOND_STAGE_SEG

    ; ---------------------------------------
    ; Additional routines and utilities
    ; ---------------------------------------

%include "print.s"
%include "io.s"
%include "../shared/fat12/fat12.s"
%include "msg.s"

BOOT_2ND_STAGE_FILENAME db "BOOT    GFB"

boot_fill:
    times 510-($-$$) db 0

    ; ---------------------------------------
    ; FAT reserved sectors
    ;
    ; Boot sector signature
    ; ---------------------------------------
    dw 0xaa55
