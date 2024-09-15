#include <linux/module.h>

#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/miscdevice.h>
#include <linux/kernel.h>
#include <linux/major.h>
#include <linux/mutex.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/stat.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/tty.h>
#include <linux/kmod.h>
#include <linux/gfp.h>
#include <asm/io.h>

#include "led_opr.h"

/* registers */
// CCM_CCGR1 地址：0x20C406C
static volatile unsigned int *CCM_CCGR1;

// IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER3 地址：0x02290000 + 0x14
static volatile unsigned int *IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER3;

// GPIO5_GDIR 地址：0x020AC004
static volatile unsigned int *GPIO5_GDIR;

// GPIO5_DR 地址：0x020AC000
static volatile unsigned int *GPIO5_DR;

// GPIO5_PSR 地址：0x020AC008
static volatile unsigned int *GPIO5_PSR;

static int board_demo_led_init(int which) /* 初始化LED, which-哪个LED */
{
	unsigned int val;

	printk(KERN_DEBUG "%s %s line %d, led %d\n", __FILE__, __FUNCTION__, __LINE__, which);

	/* ioremap */
	CCM_CCGR1 = ioremap(0x20C406C, 4);
	IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER3 = ioremap(0x02290000 + 0x14, 4);
	GPIO5_GDIR = ioremap(0x020AC004, 4);
	GPIO5_DR = ioremap(0x020AC000, 4);
	GPIO5_PSR = ioremap(0x020AC008, 4);

	/* GPIO5_IO03 */
	/* a. 使能GPIO5
	 * set CCM to enable GPIO5
	 * CCM_CCGR1[CG15] 0x20C406C
	 * bit[31:30] = 0b11
	 */
	*CCM_CCGR1 |= (3 << 30);

	/* b. 设置GPIO5_IO03用于GPIO
	 * set IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER3
	 *      to configure GPIO5_IO03 as GPIO
	 * IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER3  0x2290014
	 * bit[3:0] = 0b0101 alt5
	 */
	val = *IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER3;
	val &= ~(0xf);
	val |= (5);
	*IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER3 = val;

	/* b. 设置GPIO5_IO03作为output引脚
	 * set GPIO5_GDIR to configure GPIO5_IO03 as output
	 * GPIO5_GDIR  0x020AC000 + 0x4
	 * bit[3] = 0b1
	 */
	*GPIO5_GDIR |= (1 << 3);

	return 0;
}

/* 控制LED, 
	which:哪个LED,0-GPIO1,1-GPIO5, 
	status:1-亮,0-灭,
	operation:0-读寄存器,1-写寄存器 */
static int board_demo_led_ctl(int which, char * status, char operation)
{
	printk(KERN_DEBUG "%s %s line %d, led %d, %s\n", __FILE__, __FUNCTION__, __LINE__,
			which, status ? "on" : "off");

	if (which)	// GPIO5
	{
		if (operation)	// 写寄存器
		{
			if (*status) /* on: output 0*/
			{
				/* d. 设置GPIO5_DR输出低电平
				* set GPIO5_DR to configure GPIO5_IO03 output 0
				* GPIO5_DR 0x020AC000 + 0
				* bit[3] = 0b0
				*/
				*GPIO5_DR &= ~(1 << 3);
			}
			else /* off: output 1*/
			{
				/* e. 设置GPIO5_IO3输出高电平
				* set GPIO5_DR to configure GPIO5_IO03 output 1
				* GPIO5_DR 0x020AC000 + 0
				* bit[3] = 0b1
				*/
				*GPIO5_DR |= (1 << 3);
			}
		}
		else	// 读寄存器GPIO5_DR,返回的是PSR的值
		{
			*status = (((*GPIO5_DR) & (1 << 3)) >> 3);
		}
	}

	return 0;
}

static struct led_operations board_demo_led_opr = {
	.init = board_demo_led_init,
	.ctl = board_demo_led_ctl,
};

struct led_operations *get_board_led_opr(void)
{
	return &board_demo_led_opr;
}
