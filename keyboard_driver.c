#include "keyboard_driver.h"


static int __init keyboard_driver_init(void){
	printk(KERN_INFO "keyboard_driver: initializing...");

	//register USB device
	int result = usb_register(&usb_keyboard_driver);
	if (result != 0){
		//invalid result code
		printk(KERN_ERR "keyboard_driver: Error in loading usb device. Error code: %d\n", result);
		return -1;
	}
	
	printk(KERN_INFO "keyboard_driver: Driver initialized!\n");
	return 0;
}

static void __exit keyboard_driver_exit(void)
{
	printk(KERN_INFO "keyboard_driver: exiting...");

	//deregistre USB device
	usb_deregister(&usb_keyboard_driver);

	printk(KERN_INFO "keyboard_driver: Driver exited successfully!\n");
}


static int usb_probe(struct usb_interface* interface, const struct usb_device_id* id){
	printk(KERN_INFO "keyboard_driver: USB device probed");
	return 0;
}

static void usb_disconnect(struct usb_interface* interface){
	printk(KERN_INFO "keyboard_driver: USB device disconnected");
}

module_init(keyboard_driver_init);
module_exit(keyboard_driver_exit);
