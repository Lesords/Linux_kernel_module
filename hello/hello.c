#include <linux/init.h>
#include <linux/module.h>

static int __init lkm_init(void)
{
    printk("Hello, Calvin!\n");
    printk(KERN_EMERG "Hello, Calvin!\n");
    printk(KERN_ALERT "Hello, Calvin!\n");
    printk(KERN_CRIT "Hello, Calvin!\n");
    printk(KERN_ERR "Hello, Calvin!\n");
    printk(KERN_WARNING "Hello, Calvin!\n");
    printk(KERN_NOTICE "Hello, Calvin!\n");
    printk(KERN_INFO "Hello, Calvin!\n");
    printk(KERN_DEBUG "Hello, Calvin!\n");
    return 0;
}

static void __exit lkm_exit(void)
{
    printk("Goodbye, Calvin!\n");
}

module_init(lkm_init);
module_exit(lkm_exit);

MODULE_LICENSE("GPL");
