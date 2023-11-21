# 从内核构造系统调用
ifneq ($(KERNELRELEASE),)
    obj-m := module_A.o

# 从命令行调用
else
    CURRENT_PATH := $(shell pwd)
    include $(CURRENT_PATH)/../Makefile.config

all:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules
clean:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) clean

endif
