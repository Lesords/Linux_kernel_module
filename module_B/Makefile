# 从内核构造系统调用
ifneq ($(KERNELRELEASE),)
    obj-m := module_B.o
    KBUILD_EXTRA_SYMBOLS := \
		$(shell pwd)/Linux_kernel_module/module_A/Module.symvers

# 从命令行调用
else
    CURRENT_PATH := $(shell pwd)
    include $(CURRENT_PATH)/../Makefile.config

all:
	echo "[path] = $(KBUILD_EXTRA_SYMBOLS)"
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules
clean:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) clean

endif
