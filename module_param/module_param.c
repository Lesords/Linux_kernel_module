#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("lese");
MODULE_DESCRIPTION("This is a param test module.");
MODULE_VERSION("V1.0");
MODULE_ALIAS("a simple module.");

static char *name = "lese";
static int age = 23;

static int val[10] = {0};
static int num = 0;

module_param(name, charp, S_IRUGO);
module_param(age, int, S_IRUGO);
module_param_array(val, int, &num, 0644);

MODULE_PARM_DESC(name, "this is name variable.");
MODULE_PARM_DESC(age, "this is age variable.");
MODULE_PARM_DESC(val, "this is array variable.");

static int __init module_param_init(void)
{
    int i = 0;
    printk(KERN_INFO "module_param (init) here\n");
    printk(KERN_INFO "name = %s, age = %d\n", name, age);
    for (i = 0; i < num; ++i) {
        printk(KERN_INFO "val[%d] = %d\n", i, val[i]);
    }
    printk(KERN_INFO "module_param (init) done here\n");
    return 0;
}

static void __exit module_param_exit(void)
{
    printk(KERN_INFO "module_param (exit) here\n");
}

module_init(module_param_init);
module_exit(module_param_exit);
