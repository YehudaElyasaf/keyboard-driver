#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>


MODULE_LICENSE("MIT");


static int __init init1(void){
	printk(KERN_INFO "Hi!\n");
	return 0;
}

static void __exit exit1(void){
	printk(KERN_INFO "Bye!\n");
}

module_init(init1);
module_exit(exit1);
