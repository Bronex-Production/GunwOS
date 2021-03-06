;
;  msg.s
;  GunwOS Bootloader
;  Part of GunwOS project
;
;  Created by Artur Danielewski on 04.01.2021.
;

MSG_PRELOADER_START db 'GunwOS preloader starting...', 0xa, 0xd, 0
MSG_KERNEL_START db 'GunwOS kernel starting...', 0xa, 0xd, 0
MSG_KERNEL_PATTERN_ERR db 'Kernel pattern verification failed', 0
MSG_KERNEL_END_OF_DRIVE_ERR db 'Loading failed: reached end of drive!', 0
MSG_KERNEL_LOAD_SUCCESS db 'Kernel loaded successfully', 0xa, 0xd, 0
MSG_A20_15H_ACTIVATED db 'A20 line activated using BIOS interrupt', 0xa, 0xd, 0
MSG_A20_15H_ALREADY_ACTIVATED db 'A20 line already activated during BIOS interrupt check', 0xa, 0xd, 0
MSG_A20_15H_NOT_SUPPORTED db 'A20 BIOS interrupt not supported', 0xa, 0xd, 0
MSG_A20_15H_FAILED db 'A20 activation by BIOS interrupt failed', 0xa, 0xd, 0
MSG_A20_KEYBOARD_END db 'A20 activation attempt using keyboard controller finished', 0xa, 0xd, 0
MSG_A20_KEYBOARD_TIMEOUT db 'A20 activation using keyboard controler timed out', 0xa, 0xd, 0
MSG_A20_FAST_NOT_SUPPORTED db 'Fast A20 not supported', 0xa, 0xd, 0
MSG_A20_FAST_END db 'A20 activation attempt using Fast A20 method finished', 0xa, 0xd, 0
MSG_A20_ENABLED db 'A20 line: enabled', 0xa, 0xd, 0
MSG_A20_DISABLED_ERROR db 'A20 line disabled - what are you trying to run me on, a toothbrush?!', 0
MSG_PMODE_SWITCH db 'Switched to protected mode', 0xa, 0xd, 0
MSG_BOOT_DRIVE db 'Boot drive:', 0xa, 0xd, 0
MSG_BOOT_DRIVE_INDEX db ' * drive: ', 0
MSG_BOOT_DRIVE_SECTORS_PER_TRACK db ' * sectors per track: ', 0
MSG_BOOT_DRIVE_CYLINDERS db ' * cylinders: ', 0
MSG_BOOT_DRIVE_HEADS db ' * heads: ', 0
MSG_DEBUG db 'Debug', 0xa, 0xd, 0
