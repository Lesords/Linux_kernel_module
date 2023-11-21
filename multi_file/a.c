#include "a.h"
#include "b.h"
#include "c.h"

#include <linux/module.h>
#include <linux/kernel.h>

void function_a(void)
{
    printk(KERN_INFO "this is %s function\n", __func__);
}

void function_a_exit(void)
{
    printk(KERN_INFO "%s function exit now\n", __func__);
}

static int __init multi_file_init(void)
{
    printk(KERN_INFO "multi_file init here\n");
    function_a();
    function_b();
    function_c();
    printk(KERN_INFO "multi_file init done here\n");

    return 0;
}

static void __exit multi_file_exit(void)
{
    printk(KERN_INFO "multi_file exit here\n");
    function_a_exit();
    function_b_exit();
    function_c_exit();
    printk(KERN_INFO "multi_file exit done here\n");
}

module_init(multi_file_init);
module_exit(multi_file_exit);

MODULE_LICENSE("GPL");
