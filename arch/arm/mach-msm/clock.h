/* arch/arm/mach-msm/clock.h
 *
 * Copyright (C) 2007 Google, Inc.
 * Copyright (c) 2007-2009, Code Aurora Forum. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __ARCH_ARM_MACH_MSM_CLOCK_H
#define __ARCH_ARM_MACH_MSM_CLOCK_H

#include <linux/list.h>

#include "clock-pcom.h"

#define CLKFLAG_INVERT			0x00000001
#define CLKFLAG_NOINVERT		0x00000002
#define CLKFLAG_NONEST			0x00000004
#define CLKFLAG_NORESET			0x00000008

#define CLK_FIRST_AVAILABLE_FLAG	0x00000100
#define CLKFLAG_AUTO_OFF		0x00000200
#define CLKFLAG_MIN			0x00000400
#define CLKFLAG_MAX			0x00000800

struct clk_ops {
	int (*enable)(unsigned id);
	void (*disable)(unsigned id);
	int (*set_rate)(unsigned id, unsigned rate);
	int (*set_min_rate)(unsigned id, unsigned rate);
	int (*set_max_rate)(unsigned id, unsigned rate);
	int (*set_flags)(unsigned id, unsigned flags);
	unsigned (*get_rate)(unsigned id);
	unsigned (*is_enabled)(unsigned id);
};

struct clk {
	uint32_t id;
	uint32_t count;
	uint32_t flags;
	const char *name;
	struct clk_ops *ops;
	const char *dbg_name;
	struct list_head list;
	struct device *dev;
};

#define A11S_CLK_CNTL_ADDR		(MSM_CSR_BASE + 0x100)
#define A11S_CLK_SEL_ADDR		(MSM_CSR_BASE + 0x104)
#define A11S_VDD_SVS_PLEVEL_ADDR	(MSM_CSR_BASE + 0x124)

#ifdef CONFIG_DEBUG_FS
#define CLOCK_DBG_NAME(x) .dbg_name = x,
#else
#define CLOCK_DBG_NAME(x)
#endif

#define CLOCK(clk_name, clk_id, clk_dev, clk_flags) {	\
	.name = clk_name, \
	.id = clk_id, \
	.flags = clk_flags, \
	.dev = clk_dev, \
	 CLOCK_DBG_NAME(#clk_id) \
	}

#define OFF CLKFLAG_AUTO_OFF
#define CLK_MIN CLKFLAG_MIN
#define CLK_MAX CLKFLAG_MAX
#define CLK_MINMAX (CLK_MIN | CLK_MAX)
#define NR_CLKS	P_NR_CLKS

enum clkvote_client {
	CLKVOTE_ACPUCLK = 0,
	CLKVOTE_PMQOS,
	CLKVOTE_MAX,
};

int msm_clock_require_tcxo(unsigned long *reason, int nbits);
int msm_clock_get_name(uint32_t id, char *name, uint32_t size);
int ebi1_clk_set_min_rate(enum clkvote_client client, unsigned long rate);

#endif

