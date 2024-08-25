#pragma once

#include "keyboard_driver.h"

#define VENDOR_ID		0x03f0
#define PRODUCT_ID		0x0024


static struct usb_device_id usb_id_table[] = {
	// TODO: use USE_DEVICE_INFO INSTED? (for compatibility)
	{ USB_DEVICE(VENDOR_ID, PRODUCT_ID) },
	{ },
};
MODULE_DEVICE_TABLE(usb, usb_id_table);


static int usb_probe(struct usb_interface* interface, const struct usb_device_id* id);
static void usb_disconnect(struct usb_interface* interface);

static struct usb_driver usb_keyboard_driver = {
	.name		= MODULE_NAME,
	.probe		= usb_probe,
	.disconnect	= usb_disconnect,
	.id_table	= usb_id_table,
};
