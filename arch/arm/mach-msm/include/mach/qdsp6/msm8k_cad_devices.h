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

#ifndef CADDEVICES_H
#define CADDEVICES_H


#define CAD_HW_DEVICE_ID_HANDSET_MIC		0x01
#define CAD_HW_DEVICE_ID_HANDSET_SPKR		0x02
#define CAD_HW_DEVICE_ID_HEADSET_MIC		0x03
#define CAD_HW_DEVICE_ID_HEADSET_SPKR_MONO	0x04
#define CAD_HW_DEVICE_ID_HEADSET_SPKR_STEREO	0x05
#define CAD_HW_DEVICE_ID_SPKR_PHONE_MIC		0x06
#define CAD_HW_DEVICE_ID_SPKR_PHONE_MONO	0x07
#define CAD_HW_DEVICE_ID_SPKR_PHONE_STEREO	0x08
#define CAD_HW_DEVICE_ID_BT_SCO_MIC		0x09
#define CAD_HW_DEVICE_ID_BT_SCO_SPKR		0x0A
#define CAD_HW_DEVICE_ID_BT_A2DP_SPKR		0x0B
#define CAD_HW_DEVICE_ID_TTY_HEADSET_MIC	0x0C
#define CAD_HW_DEVICE_ID_TTY_HEADSET_SPKR	0x0D

#define CAD_HW_DEVICE_ID_DEFAULT_TX		0x0E
/*Starts with CAD_HW_DEVICE_ID_HANDSET_MIC*/
#define CAD_HW_DEVICE_ID_DEFAULT_RX		0x0F
/*Starts with CAD_HW_DEVICE_ID_HANDSET_SPKR*/

/* Logical Device to indicate A2DP routing */
#define CAD_HW_DEVICE_ID_BT_A2DP_TX             0x10
#define CAD_HW_DEVICE_ID_HEADSET_MONO_PLUS_SPKR_MONO_RX		0x11
#define CAD_HW_DEVICE_ID_HEADSET_MONO_PLUS_SPKR_STEREO_RX	0x12
#define CAD_HW_DEVICE_ID_HEADSET_STEREO_PLUS_SPKR_MONO_RX	0x13
#define CAD_HW_DEVICE_ID_HEADSET_STEREO_PLUS_SPKR_STEREO_RX	0x14

#define CAD_HW_DEVICE_ID_I2S_RX                 0x20
#define CAD_HW_DEVICE_ID_I2S_TX                 0x21

/* AUXPGA */
#define CAD_HW_DEVICE_ID_HEADSET_SPKR_STEREO_LB 0x22
#define CAD_HW_DEVICE_ID_HEADSET_SPKR_MONO_LB   0x23
#define CAD_HW_DEVICE_ID_SPEAKER_SPKR_STEREO_LB 0x24
#define CAD_HW_DEVICE_ID_SPEAKER_SPKR_MONO_LB   0x25

#define CAD_HW_DEVICE_ID_MAX_NUM                0x2F

#define CAD_HW_DEVICE_ID_INVALID                0xFF

#define CAD_RX_DEVICE  0x00
#define CAD_TX_DEVICE  0x01
#define CAD_AUXPGA_DEVICE 0x02

#endif
