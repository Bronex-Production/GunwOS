//
//  devmgr.c
//  GunwOS
//
//  Created by Artur Danielewski on 06.03.2020.
//

#include "../../../include/gunwdrv.h"
#include "devmgr.h"
#include "../../shared/log/log.h"

#define MAX_DEVICES 8

static struct gnwDeviceDescriptor devices[MAX_DEVICES];
static uint_32 devicesCount;

// TODO replace with syscall
extern enum gnwDriverError k_hal_install(struct gnwDriverDesc);
// TODO replace with syscall
extern enum gnwDriverError k_hal_start(struct gnwDriverDesc);

extern struct gnwDriverDesc s_drv_pit();
extern struct gnwDeviceUHA s_drv_pit_uha();
extern struct gnwDriverDesc s_drv_keyboard();
extern struct gnwDeviceUHA s_drv_keyboard_uha();
extern struct gnwDriverDesc s_drv_fdc();
extern struct gnwDeviceUHA s_drv_fdc_uha();

extern int s_trm_putc(const char c);
extern int s_trm_puts(const char * const s);

enum gnwDriverError s_devmgr_install(struct gnwDeviceDescriptor descriptor) {

    s_trm_puts("Device manager: Install driver named ");
    s_trm_puts(descriptor.name);
    s_trm_putc('\n');

    if (devicesCount >= MAX_DEVICES) {
        return LIMIT_REACHED;
    }

    enum gnwDriverError e;

    e = k_hal_install(descriptor.driver.descriptor);
    if (e != NO_ERROR) {
        LOG_ERR("Error: Driver initialization failed");
        return e;
    }

    devices[devicesCount++] = descriptor;  

    return NO_ERROR;
}

enum gnwDriverError s_devmgr_start(struct gnwDeviceDescriptor descriptor) {

    s_trm_puts("Device manager: ");
    s_trm_puts(descriptor.name);
    s_trm_puts(" starting\n");

    enum gnwDriverError e;

    e = k_hal_start(descriptor.driver.descriptor);
    if (e != NO_ERROR) {
        LOG_ERR("Error: Driver startup failed");
        return e;
    }

    return NO_ERROR;
}

struct gnwDeviceDescriptor createDeviceDescriptor(const enum gnwDeviceType deviceType,
                                                  const struct gnwDeviceUHA uha,
                                                  const uint_16 busBase,
                                                  const struct gnwDriverDesc driverDescriptor,
                                                  char * const name) {
    return (struct gnwDeviceDescriptor) { 
        deviceType,             // Device type
        uha,                    // UHA
        {                       // Driver
            {                   // I/O
                busBase         // Bus base address
            },                                              
            driverDescriptor    // Device driver descriptor
        }, 
        name                    // Device friendly name
    };
}

void s_devmgr_init() {

    s_trm_puts("Device manager: Init\n");

    enum gnwDriverError e;

    /*
        PIT driver for 8253/8254 chip
    */
    struct gnwDeviceDescriptor pit = createDeviceDescriptor(DEV_TYPE_SYSTEM,
                                                            s_drv_pit_uha(),
                                                            0x40,
                                                            s_drv_pit(),
                                                            "8253/8254 Programmable Interrupt Timer");
    e = s_devmgr_install(pit);
    if (e != NO_ERROR) { 
        LOG_FATAL("Fatal error: PIT driver installation failed"); 
        return; 
    }
    else {
        e = s_devmgr_start(pit);
        if (e != NO_ERROR) { LOG_FATAL("Fatal error: PIT driver startup failed"); return; }
    }

    /*
        Keyboard controller driver for 8042 PS/2 chip
    */
    struct gnwDeviceDescriptor kbd = createDeviceDescriptor(DEV_TYPE_KEYBOARD,
                                                            s_drv_keyboard_uha(),
                                                            0x60,
                                                            s_drv_keyboard(),
                                                            "8042 PS/2 Controller");
    e = s_devmgr_install(kbd);
    if (e != NO_ERROR) { 
        LOG_FATAL("Fatal error: Keyboard driver installation failed"); 
        return; 
    }
    else {
        e = s_devmgr_start(kbd);
        if (e != NO_ERROR) { LOG_FATAL("Fatal error: Keyboard driver startup failed"); return; }
    }

    /*
        Floppy disk controller driver for 82077AA chip
    */
    struct gnwDeviceDescriptor fdc = createDeviceDescriptor(DEV_TYPE_FDC,
                                                            s_drv_fdc_uha(),
                                                            0x3F0,
                                                            s_drv_fdc(),
                                                            "82077AA Floppy Disk Controller");
    e = s_devmgr_install(fdc);
    if (e != NO_ERROR) { 
        LOG_ERR("Driver error: Floppy disk controller driver installation failed");
    }
    else {
        e = s_devmgr_start(fdc);
        if (e != NO_ERROR) { LOG_ERR("Driver error: Floppy disk controller driver startup failed"); }
    }
}

size_t s_devmgr_descriptorCount() {
    return MAX_DEVICES;
}

struct gnwDeviceDescriptor s_devmgr_descriptorFor(const uint_32 descriptorID) {
    if (descriptorID >= MAX_DEVICES) {
        LOG_FATAL("Device descriptor over limit")
        __builtin_unreachable();
    }

    return devices[descriptorID];
}
