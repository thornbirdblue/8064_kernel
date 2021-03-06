/* Copyright (c) 2009, Code Aurora Forum. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Code Aurora Forum nor
 *       the names of its contributors may be used to endorse or promote
 *       products derived from this software without specific prior written
 *       permission.
 *
 * Alternatively, provided that this notice is retained in full, this software
 * may be relicensed by the recipient under the terms of the GNU General Public
 * License version 2 ("GPL") and only version 2, in which case the provisions of
 * the GPL apply INSTEAD OF those given above.  If the recipient relicenses the
 * software under the GPL, then the identification text in the MODULE_LICENSE
 * macro must be changed to reflect "GPLv2" instead of "Dual BSD/GPL".  Once a
 * recipient changes the license terms to the GPL, subsequent recipients shall
 * not relicense under alternate licensing terms, including the BSD or dual
 * BSD/GPL terms.  In addition, the following license statement immediately
 * below and between the words START and END shall also then apply when this
 * software is relicensed under the GPL:
 *
 * START
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License version 2 and only version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * END
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef CADITYPES_H
#define CADITYPES_H

#include <mach/qdsp6/msm8k_cad_event.h>
#include <mach/qdsp6/msm8k_cad_ioctl.h>


#define CADI_IOCTL_CMD_OPEN             0x0105c3f0
#define CADI_IOCTL_CMD_CLOSE            0x01075ab1
#define CADI_IOCTL_CMD_STOP             0x01075c54

#define CADI_IOCTL_CMD_DSP_PREP_DEV_CHG		0x01081d29
#define CADI_IOCTL_CMD_DSP_STANDBY		0x01081d2a
#define CADI_IOCTL_CMD_DSP_START		0x01081d2b


struct cadi_dev_chg_struct_type {
	u8	cad_dev_class;
	u8	cad_dev_type;
	u32	cad_old_device;
	u32	cad_new_device;
};


struct cadi_open_struct_type {
	struct cad_open_struct_type		cad_open;
	struct cad_stream_config_struct_type	cad_config;
	struct cad_stream_info_struct_type	cad_stream;
	struct cad_stream_device_struct_type	cad_device;
};


struct cadi_evt_data_struct_type {
	union {
		s32                                     svalue;
		u32                                     uvalue;
		struct cad_evt_avsync_struct_type       av_sync_data;
		struct cad_buf_struct_type              buf_data;
	};
};

struct cadi_evt_hdr_struct_type {
	s32             cad_handle;
	u32             cmd_event_id;
	s32             status;
};

struct cadi_evt_struct_type {
	struct cadi_evt_hdr_struct_type         cad_event_header;
	u32                                     data_len;
	struct cadi_evt_data_struct_type        cad_event_data;
};


typedef void (*cadi_evt_cb_func_type)(struct cadi_evt_struct_type *evt_packet,
	void *client_data);

struct cadi_evt_cb_struct_type {
	cadi_evt_cb_func_type   callback;
	void                    *client_data;
};

#endif
