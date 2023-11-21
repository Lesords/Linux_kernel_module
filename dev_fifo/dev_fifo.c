#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
 
#define MAJOR_NUM 168
struct mycdev
{
    unsigned char buffer[50];
    struct cdev cdev;
}dev_fifo;
 
MODULE_LICENSE("GPL");
 
static int dev_fifo_open(struct inode *inode,struct file *file){
 
	printk("dev_fifo_open success!");
 
	return 0;
}
 
static ssize_t dev_fifo_read(struct file *file,char __user *buf,size_t size,loff_t *ppos)
{
	printk("dev_fifo_read success");
	return 0;
}
 
static ssize_t dev_fifo_write(struct file *file,const char __user *buf,size_t size,loff_t *ppos)
{
	printk("dev_fifo_write success");
	return 0;
}
 
static const struct file_operations fifo_operations = {
.owner = THIS_MODULE,
.open = dev_fifo_open,
.read = dev_fifo_read,
.write = dev_fifo_write,
};
 
int __init dev_fifo_init(void)
{
	int ret;
	dev_t dev_num;
 
	//初始化字符设备
	cdev_init(&dev_fifo.cdev,&fifo_operations);
 
	//设备号：主设备号（12Bit）|次设备号（20BIT）
	dev_num = MKDEV(MAJOR_NUM,0);
	//注册设备号
	ret = register_chrdev_region(dev_num,1,"dev_fifo");
	if(ret < 0)
	{
		printk("Fail to register_chrdev_region");
		return -EIO;
	}
	//添加设备到操作系统。
 
	ret = cdev_add(&dev_fifo.cdev,dev_num,1);
	if(ret < 0)
	{
		printk("fail to cdev_add");
		goto unregister_chrdev;
	}
 
	printk("Register dev_fifo to system.ok!\n");
 
	return 0;
 
    unregister_chrdev:
        unregister_chrdev_region(MKDEV(MAJOR_NUM,0),1);
        return -1;
}
 
void __exit dev_fifo_exit(void)
{
    //从系统中删除添加的字符设备
    cdev_del(&dev_fifo.cdev);
    //释放申请的设备号
    unregister_chrdev_region(MKDEV(MAJOR_NUM,0),1);
    printk("Exit dev_fifo ok!");
    return;
}
 
module_init(dev_fifo_init);
module_exit(dev_fifo_exit);
