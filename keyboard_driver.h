#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/usb.h>

#define MODULE_NAME	"keyboard_driver"
#define MODULE_PRINT_PREFIX	MODULE_NAME ": "

#define VENDOR_ID	0x03f0
#define PRODUCT_ID	0x0024


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("USB keyboard driver for Linux");
MODULE_AUTHOR("Yehuda Elyasaf");

static struct usb_device_id usb_id_table[] = {
	// TODO: use USE_DEVICE_INFO INSTED? (for compatibility)
	{ USB_DEVICE(VENDOR_ID, PRODUCT_ID) },
	{ },
};
MODULE_DEVICE_TABLE(usb, usb_id_table);


static int __init keyboard_driver_init(void);
static void __exit keyboard_driver_exit(void);
static int usb_probe(struct usb_interface* interface, const struct usb_device_id* id);
static void usb_disconnect(struct usb_interface* interface);

static struct usb_driver usb_keyboard_driver = {
	.name		= MODULE_NAME,
	.probe		= usb_probe,
	.disconnect	= usb_disconnect,
	.id_table	= usb_id_table,
};
