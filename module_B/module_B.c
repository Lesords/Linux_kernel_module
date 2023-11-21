#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

extern int function_A(void);

static int __init module_B_init(void)
{
    printk(KERN_INFO "module_B init here\n");
    function_A();
    return 0;
}

static void __exit module_B_exit(void)
{
    printk(KERN_INFO "module_B exit here\n");
}

module_init(module_B_init);
module_exit(module_B_exit);

MODULE_LICENSE("GPL");
