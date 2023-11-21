# 从内核构造系统调用
ifneq ($(KERNELRELEASE),)
    obj-m := dev_fifo.o

# 从命令行调用
else
    CURRENT_PATH := $(shell pwd)
    include $(CURRENT_PATH)/../Makefile.config

all:
	$(MAKE) -C $(LINUX_KERNEL_PATH) M=$(PWD) modules
clean:
	$(MAKE) -C $(LINUX_KERNEL_PATH) M=$(PWD) clean

endif
