/*
 * Copyright (C) 2007-2009 ST-Ericsson AB
 * License terms: GNU General Public License (GPL) version 2
 * AB3550 core access functions
 * Author: Linus Walleij <linus.walleij@stericsson.com>
 *
 */

#include <linux/regulator/machine.h>

struct device;

#ifndef MFD_AB3550_H
#define MFD_AB3550_H

#define AB3550_P1A	0x10

/* AB3550, STR register flags */
#define AB3550_STR_ONSWA				(0x01)
#define AB3550_STR_ONSWB				(0x02)
#define AB3550_STR_ONSWC				(0x04)
#define AB3550_STR_DCIO					(0x08)
#define AB3550_STR_BOOT_MODE				(0x10)
#define AB3550_STR_SIM_OFF				(0x20)
#define AB3550_STR_BATT_REMOVAL				(0x40)
#define AB3550_STR_VBUS					(0x80)

/* Interrupt mask registers */
#define AB3550_IMR1 0x29
#define AB3550_IMR2 0x2a
#define AB3550_IMR3 0x2b
#define AB3550_IMR4 0x2c
#define AB3550_IMR5 0x2d

enum ab3550_devid {
	AB3550_DEVID_ADC,
	AB3550_DEVID_DAC,
	AB3550_DEVID_LEDS,
	AB3550_DEVID_POWER,
	AB3550_DEVID_REGULATORS,
	AB3550_DEVID_SIM,
	AB3550_DEVID_UART,
	AB3550_DEVID_RTC,
	AB3550_DEVID_CHARGER,
	AB3550_DEVID_FUELGAUGE,
	AB3550_DEVID_VIBRATOR,
	AB3550_DEVID_CODEC,
	AB3550_NUM_DEVICES,
};

/**
 * struct ab3550_platform_data
 * Data supplied to initialize board connections to the AB3550
 */
struct ab3550_platform_data {
	struct {unsigned int base; unsigned int count; } irq;
	void *dev_data[AB3550_NUM_DEVICES];
	size_t dev_data_sz[AB3550_NUM_DEVICES];
	struct abx500_init_settings *init_settings;
	unsigned int init_settings_sz;
};

#endif /*  MFD_AB3550_H */