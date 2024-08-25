#pragma once

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/usb.h>

#define MODULE_NAME		"keyboard_driver"
#define MODULE_PRINT_PREFIX	MODULE_NAME ": "


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("USB keyboard driver for Linux");
MODULE_AUTHOR("Yehuda Elyasaf");


static int __init keyboard_driver_init(void);
static void __exit keyboard_driver_exit(void);

module_init(keyboard_driver_init);
module_exit(keyboard_driver_exit);
