#include "keyboard_driver.h"
#include "usb.h"


static int __init keyboard_driver_init(void){
	printk(KERN_INFO MODULE_PRINT_PREFIX "Initializing...\n");

	//register USB device
	int result;
       result = usb_register(&usb_keyboard_driver);
	if (result != 0){
		//invalid result code
		printk(KERN_ERR MODULE_PRINT_PREFIX "Couldn't load USB device. Error code: %d\n", result);
		return -1;
	}
	
	printk(KERN_INFO MODULE_PRINT_PREFIX "Driver initialized successfully!\n");
	return 0;
}

static void __exit keyboard_driver_exit(void)
{
	printk(KERN_INFO MODULE_PRINT_PREFIX "Exiting...\n");

	//deregister USB device
	usb_deregister(&usb_keyboard_driver);

	printk(KERN_INFO MODULE_PRINT_PREFIX "Driver exited successfully!\n");
}


static int usb_probe(struct usb_interface* interface, const struct usb_device_id* id){
	printk(KERN_INFO MODULE_PRINT_PREFIX "USB device [ID %04x:%04x] connected\n",
			id->idVendor, id->idProduct);
	return 0;
}

static void usb_disconnect(struct usb_interface* interface){
	printk(KERN_INFO MODULE_PRINT_PREFIX "USB device disconnected\n");
}
