#include "led_resource.h"

static struct led_resource board_A_led = {
	.pin = GROUP_PIN(5, 3),
};

struct led_resource *get_led_resouce(void)
{
	return &board_A_led;
}