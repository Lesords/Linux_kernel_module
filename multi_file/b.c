#include "b.h"

#include <linux/module.h>

void function_b(void)
{
    printk(KERN_INFO "this is %s function\n", __func__);
}

void function_b_exit(void)
{
    printk(KERN_INFO "%s fucntion exit now\n", __func__);
}
