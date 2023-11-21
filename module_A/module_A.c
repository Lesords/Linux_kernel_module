#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

int function_A(void)
{
    printk(KERN_INFO "this is %s position.\n", __func__);
    return 0;
}

EXPORT_SYMBOL(function_A);

static int __init module_A_init(void)
{
    printk(KERN_INFO "module_A init here.\n");
    return 0;
}

static void __exit module_A_exit(void)
{
    printk(KERN_INFO "module_A exit now.\n");
}

module_init(module_A_init);
module_exit(module_A_exit);

MODULE_LICENSE("GPL");
