/******************************************************************************
 *  Copyright (C) 2015 Cai Zhiyong
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Create By Cai Zhiying 2015.7.28
 *
******************************************************************************/

#include <stddef.h>

#include "hiflash.h"
#include "../nand/nand_chip.h"

/******************************************************************************/

struct nand_flash_special_dev nand_flash_ids_hisi[] = {
	{
		.name      = "TC58NVG5D2 32G 3.3V 8-bit",
		.ids.id    = {0x98, 0xD7, 0x94, 0x32, 0x76, 0x56, 0x09, 0x00},
		.id_len    = 8,
		.pagesize  = _8K,
		.chipsize  = _4G,
		.erasesize = _1M,
		.oobsize   = 640,
		.options   = 0,
	}, {
		.name      = "S34ML04G2 3.3V 8-bit",
		.ids.id    = {0x01, 0xdc, 0x90, 0x95, 0x56, 0x00, 0x00, 0x00},
		.id_len    = 5,
		.pagesize  = _2K,
		.chipsize  = _512M,
		.erasesize = _128K,
		.oobsize   = 128,
		.options   = 0,
	}, {
		.name      = "TC58NVG6D2 64G 3.3V 8-bit",
		.ids.id    = {0x98, 0xDE, 0x94, 0x82, 0x76, 0x56, 0x04, 0x20},
		.id_len    = 8,
		.pagesize  = _8K,
		.chipsize  = _8G,
		.erasesize = _2M,
		.oobsize   = 640,
		.options   = 0,
	}, {
		.name      = "SDTNRGAMA 64G 3.3V 8-bit",
		.ids.id    = {0x45, 0xDE, 0x94, 0x93, 0x76, 0x50},
		.id_len    = 6,
		.pagesize  = _16K,
		.chipsize  = _8G,
		.erasesize = _4M,
		.oobsize   = 1280,
		.options   = 0,
	}, {
		.name      = "H27UCG8T2ATR-BC 64G 3.3V 8-bit",
		.ids.id    = {0xAD, 0xDE, 0x94, 0xDA, 0x74, 0xC4},
		.id_len    = 6,
		.pagesize  = _8K,
		.chipsize  = _8G,
		.erasesize = _2M,
		.oobsize   = 640,
		.options   = 0,
		.read_retry_type = NAND_RR_HYNIX_CG_ADIE,
	}, {
		.name      = "TC58NVG3S0F 8G 3.3V 8-bit",
		.ids.id    = {0x98, 0xD3, 0x90, 0x26, 0x76, 0x15, 0x02, 0x08},
		.id_len    = 8,
		.pagesize  = _4K,
		.chipsize  = _1G,
		.erasesize = _256K,
		.oobsize   = 232,
		.options   = 0,
	}, {
		.name      = "TC58NVG2S0F 4G 3.3V 8-bit",
		.ids.id    = {0x98, 0xDC, 0x90, 0x26, 0x76, 0x15, 0x01, 0x08},
		.id_len    = 8,
		.pagesize  = _4K,
		.chipsize  = _512M,
		.erasesize = _256K,
		.oobsize   = 224,
		.options   = 0,
	}, {
		.name      = "TC58NVG2S0HBAI4",
		.ids.id        = {0x98, 0xDC, 0x90, 0x26, 0x76, 0x16, 0x08, 0x00},
		.id_len    = 8,
		.pagesize  = _4K,
		.chipsize  = _512M,
		.erasesize = _256K,
		.oobsize   = 256,
		.options   = 0,
	}, {
		.name      = "MT29F32G08CBADA",
		.ids.id    = {0x2C, 0x44, 0x44, 0x4B, 0xA9, 0x00, 0x00, 0x00},
		.id_len    = 8,
		.chipsize  = _4G,
		.pagesize  = _8K,
		.erasesize = _2M,
		.oobsize   = 744,
		.options   = 0,
		.read_retry_type = NAND_RR_MICRON,
	}, {
		.name      = "MT29F8G08ABxBA",
		.ids.id    = {0x2C, 0x38, 0x00, 0x26, 0x85, 0x00, 0x00, 0x00},
		.id_len    = 8,
		.chipsize  = _1G,
		.pagesize  = _4K,
		.erasesize = _512K,
		.oobsize   = 224,
		.options   = 0,
	}, {
		.name      = "MT29F16G08CBABx",
		.ids.id    = {0x2C, 0x48, 0x04, 0x46, 0x85, 0x00, 0x00, 0x00},
		.id_len    = 8,
		.chipsize  = _2G,
		.pagesize  = _4K,
		.erasesize = _1M,
		.oobsize   = 224,
		.options   = 0,
	}, {
		.name      = "MT29F16G08CBACA",
		.ids.id    = {0x2C, 0x48, 0x04, 0x4A, 0xA5, 0x00, 0x00, 0x00},
		.id_len    = 8,
		.chipsize  = _2G,
		.pagesize  = _4K,
		.erasesize = _1M,
		.oobsize   = 224,
		.options   = 0,
	}, {
		.name      = "MT29F32G08CBACA",
		.ids.id    = {0x2C, 0x68, 0x04, 0x4A, 0xA9, 0x00, 0x00, 0x00},
		.id_len    = 8,
		.chipsize  = _4G,
		.pagesize  = _4K,
		.erasesize = _1M,
		.oobsize   = 224,
		.options   = 0,
	}, {
		.name      = "MT29F64G08CxxAA",
		.ids.id    = {0x2C, 0x88, 0x04, 0x4B, 0xA9, 0x00, 0x00, 0x00},
		.id_len    = 8,
		.chipsize  = _8G,
		.pagesize  = _8K,
		.erasesize = _2M,
		.oobsize   = 448,
		.options   = 0,
	}, {
		.name      = "MT29F256G08CJAAA",
		.ids.id    = {0x2C, 0xA8, 0x05, 0xCB, 0xA9, 0x00, 0x00, 0x00},
		.id_len    = 8,
		.chipsize  = _16G,
		.pagesize  = _8K,
		.erasesize = _2M,
		.oobsize   = 448,
		.options   = 0,
	}, {
		.name      = "MT29F256G08CMCBB",
		.ids.id    = {0x2C, 0x64, 0x44, 0x4B, 0xA9, 0x00, 0x00, 0x00},
		.id_len    = 8,
		.chipsize  = _8G,
		.pagesize  = _8K,
		.erasesize = _2M,
		.oobsize   = 744,
		.options   = 0,
		.read_retry_type = NAND_RR_MICRON,
	}, {
		.name      = "MT29F8G08ABACA",
		.ids.id    = {0x2C, 0xD3, 0x90, 0xA6, 0x64, 0x00, 0x00, 0x00},
		.id_len    = 5,
		.chipsize  = _1G,
		.pagesize  = _4K,
		.erasesize = _256K,
		.oobsize   = 224,
		.options   = 0,
	}, {
		.name      = "MT29F4G08ABAEA",
		.ids.id    = {0x2C, 0xDC, 0x90, 0xA6, 0x54, 0x00, 0x00, 0x00},
		.id_len    = 5,
		.chipsize  = _512M,
		.pagesize  = _4K,
		.erasesize = _256K,
		.oobsize   = 224,
		.options   = 0,
	}, {
		.name      = "MT29F2G08ABAFA",
		.ids.id    = {0x2C, 0xDA, 0x90, 0x95, 0x04, 0x00, 0x00, 0x00},
		.id_len    = 5,
		.chipsize  = _256M,
		.pagesize  = _2K,
		.erasesize = _128K,
		.oobsize   = 224,
		.options   = 0,
	}, {
		.name      = "MT29F16G08ABACA",
		.ids.id    = {0x2C, 0x48, 0x00, 0x26, 0xA9, 0x00, 0x00, 0x00},
		.id_len    = 5,
		.chipsize  = _2G,
		.pagesize  = _4K,
		.erasesize = _512K,
		.oobsize   = 224,
		.options   = 0,
	}, {
		.name      = "TC58NVG4D2FTA00",
		.ids.id    = {0x98, 0xD5, 0x94, 0x32, 0x76, 0x55, 0x00, 0x00},
		.id_len    = 6,
		.chipsize  = _2G,
		.pagesize  = _8K,
		.erasesize = _1M,
		.oobsize   = 448,
		.options   = 0,
	}, {
		.name      = "TH58NVG6D2FTA20",
		.ids.id    = {0x98, 0xD7, 0x94, 0x32, 0x76, 0x55, 0x00, 0x00},
		.id_len    = 6,
		.chipsize  = _4G,
		.pagesize  = _8K,
		.erasesize = _1M,
		.oobsize   = 448,
		.options   = 0,
	}, {
		.name      = "TC58NVG5D2HTA00",
		.ids.id    = {0x98, 0xD7, 0x94, 0x32, 0x76, 0x56, 0x08, 0x00},
		.id_len    = 6,
		.chipsize  = _4G,
		.pagesize  = _8K,
		.erasesize = _1M,
		.oobsize   = 640,
		.options   = 0,
		.read_retry_type = NAND_RR_TOSHIBA_V2012,
	}, {
		.name      = "TC58NVG6D2GTA00",
		.ids.id    = {0x98, 0xDE, 0x94, 0x82, 0x76, 0x00, 0x00, 0x00},
		.id_len    = 5,
		.chipsize  = _8G,
		.pagesize  = _8K,
		.erasesize = _2M,
		.oobsize   = 640,
		.options   = 0,
	}, {
		.name      = "TC58NVG6DCJTA00",
		.ids.id    = {0x98, 0xDE, 0x84, 0x93, 0x72, 0x57, 0x08, 0x04},
		.id_len    = 8,
		.chipsize  = _8G,
		.pagesize  = _16K,
		.erasesize = _4M,
		.oobsize   = 1280,
		.options   = 0,
		.read_retry_type = NAND_RR_TOSHIBA_V2012,
	}, {
		.name      = "TC58TEG5DCJTA00",
		.ids.id    = {0x98, 0xD7, 0x84, 0x93, 0x72, 0x57, 0x08, 0x04},
		.id_len    = 6,
		.chipsize  = _4G,
		.pagesize  = _16K,
		.erasesize = _4M,
		.oobsize   = 1280,
		.options   = 0,
		.read_retry_type = NAND_RR_TOSHIBA_V2012,
	}, {
		.name      = "TC58NVG0S3HTA00",
		.ids.id    = {0x98, 0xF1, 0x80, 0x15, 0x72, 0x00, 0x00, 0x00},
		.id_len    = 5,
		.chipsize  = _128M,
		.pagesize  = _2K,
		.erasesize = _128K,
		.oobsize   = 128,
		.options   = 0,
	}, {
		.name      = "TC58NVG1S3HTA00/QSV256M3THE",
		.ids.id    = {0x98, 0xDA, 0x90, 0x15, 0x76, 0x00, 0x00, 0x00},
		.id_len    = 5,
		.chipsize  = _256M,
		.pagesize  = _2K,
		.erasesize = _128K,
		.oobsize   = 128,
		.options   = 0,
	}, {
		.name      = "TC58NVG1S3ETA00",
		.ids.id        = {0x98, 0xDA, 0x90, 0x15, 0x76, 0x14, 0x03, 0x00},
		.id_len    = 8,
		.chipsize  = _256M,
		.pagesize  = _2K,
		.erasesize = _128K,
		.oobsize   = 64,
		.options   = 0,
	}, {
		.name      = "TC58NVG5T2JTA00",
		.ids.id    = {0x98, 0xD7, 0x98, 0x92, 0x72, 0x57, 0x08, 0x10},
		.id_len    = 6,
		.chipsize  = _4G,
		.pagesize  = _8K,
		.erasesize = _4M,
		.oobsize   = 1024,
		.options   = 0,
		.read_retry_type = NAND_RR_TOSHIBA_V2012,
	}, {
		.name      = "TC58TEG5DCKTAx0",
		.ids.id    = {0x98, 0xD7, 0x84, 0x93, 0x72, 0x50, 0x08, 0x04},
		.id_len    = 6,
		.chipsize  = _4G,
		.pagesize  = _16K,
		.erasesize = _4M,
		.oobsize   = 1280,
		.options   = 0,
		.read_retry_type = NAND_RR_TOSHIBA_V2013,
	}, {
		.name      = "Tx58TEGxDDKTAx0",
		.ids.id    = {0x98, 0xDE, 0x94, 0x93, 0x76, 0x50},
		.id_len    = 6,
		.chipsize  = _4G,
		.pagesize  = _16K,
		.erasesize = _4M,
		.oobsize   = 1280,
		.options   = 0,
		.read_retry_type = NAND_RR_TOSHIBA_V2013,
	}, {
		.name      = "K9GAG08U0F",
		.ids.id    = {0xEC, 0xD5, 0x94, 0x76, 0x54, 0x43, 0x00, 0x00},
		.id_len    = 6,
		.chipsize  = _2G,
		.pagesize  = _8K,
		.erasesize = _1M,
		.oobsize   = 512,
		.options   = 0,
	}, {
		.name      = "K9LBG08U0M",
		.ids.id    = {0xEC, 0xD7, 0x55, 0xB6, 0x78, 0x00, 0x00, 0x00},
		.id_len    = 5,
		.chipsize  = _4G,
		.pagesize  = _4K,
		.erasesize = _512K,
		.oobsize   = 128,
		.options   = 0,
	}, {
		.name      = "K9GBG08U0A",
		.ids.id    = {0xEC, 0xD7, 0x94, 0x7A, 0x54, 0x43, 0x00, 0x00},
		.id_len    = 6,
		.chipsize  = _4G,
		.pagesize  = _8K,
		.erasesize = _1M,
		.oobsize   = 640,
		.options   = 0,
		.read_retry_type = NAND_RR_SAMSUNG,
	}, {
		.name      = "K9GBG08U0B",
		.ids.id    = {0xEC, 0xD7, 0x94, 0x7E, 0x64, 0x44, 0x00, 0x00},
		.id_len    = 6,
		.chipsize  = _4G,
		.pagesize  = _8K,
		.erasesize = _1M,
		.oobsize   = 1024,
		.options   = 0,
		.read_retry_type = NAND_RR_SAMSUNG,
	}, {
		.name      = "H27UBG8T2C",
		.ids.id    = {0xAD, 0xD7, 0x94, 0x91, 0x60, 0x44, },
		.id_len    = 6,
		.chipsize  = _4G,
		.pagesize  = _8K,
		.erasesize = _2M,
		.oobsize   = 640,
		.options   = 0,
		.read_retry_type = NAND_RR_HYNIX_BG_CDIE,
	}, {
		.name      = "P1UAGA30AT-GCA",
		.ids.id    = {0xC8, 0xD5, 0x14, 0x29, 0x34, 0x01, },
		.id_len    = 6,
		.chipsize  = _2G,
		.pagesize  = _4K,
		.erasesize = _512K,
		.oobsize   = 218,
		.options   = 0,
	}, {   
		.name      = "PSU8GA30AT-GIA/ASU8GA30IT-G30CA",
		.ids.id    = {0xC8, 0xD3, 0x90, 0x19, 0x34, 0x01, },
		.id_len    = 6,
		.chipsize  = _1G,
		.pagesize  = _4K,
		.erasesize = _256K,
		.oobsize   = 218,
		.options   = 0,
	}, {        /* SLC 1bit/512 */
		.name      = "PSU2GA30AT",
		.ids.id    = {0x7F, 0x7F, 0x7F, 0x7F, 0xC8, 0xDA, 0x00, 0x15, },
		.id_len    = 8,
		.chipsize  = _256M,
		.pagesize  = _2K,
		.erasesize = _128K,
		.oobsize   = 64,
		.options   = 0,
	}, {        /* SLC 4bit/512 */
		.name      = "FMND1G08U3B",
		.ids.id    = {0xF8, 0xF1, 0x80, 0x91, 0xC8, },
		.id_len    = 4,
		.chipsize  = _128M,
		.pagesize  = _2K,
		.erasesize = _128K,
		.oobsize   = 64,
		.options   = 0,
 	},

	{
		.name = "NAND 1MiB 5V 8-bit",
		.ids.id = {0x00, 0x6e,},
		.pagesize = 256,
		.chipsize = (1 << 20),
		.erasesize = 0x1000,
		.options = 0,
	},
	{
		.name = "NAND 2MiB 5V 8-bit",
		.ids.id = {0x00, 0x64,},
		.pagesize = 256,
		.chipsize = (2 << 20),
		.erasesize = 0x1000,
		.options = 0,
	},
	{
		.name = "NAND 4MiB 5V 8-bit",
		.ids.id = {0x00, 0x6b,},
		.pagesize = 512,
		.chipsize = (4 << 20),
		.erasesize = 0x2000,
		.options = 0,
	},
	{
		.name = "NAND 1MiB 3,3V 8-bit",
		.ids.id = {0x00, 0xe8,},
		.pagesize = 256,
		.chipsize = (1 << 20),
		.erasesize = 0x1000,
		.options = 0,
	},
	{
		.name = "NAND 1MiB 3,3V 8-bit",
		.ids.id = {0x00, 0xec,},
		.pagesize = 256,
		.chipsize = (1 << 20),
		.erasesize = 0x1000,
		.options = 0,
	},
	{
		.name = "NAND 2MiB 3,3V 8-bit",
		.ids.id = {0x00, 0xea,},
		.pagesize = 256,
		.chipsize = (2 << 20),
		.erasesize = 0x1000,
		.options = 0,
	},
	{
		.name = "NAND 4MiB 3,3V 8-bit",
		.ids.id = {0x00, 0xd5,},
		.pagesize = 512,
		.chipsize = (4 << 20),
		.erasesize = 0x2000,
		.options = 0,
	},
	{
		.name = "NAND 4MiB 3,3V 8-bit",
		.ids.id = {0x00, 0xe3,},
		.pagesize = 512,
		.chipsize = (4 << 20),
		.erasesize = 0x2000,
		.options = 0,
	},
	{
		.name = "NAND 4MiB 3,3V 8-bit",
		.ids.id = {0x00, 0xe5,},
		.pagesize = 512,
		.chipsize = (4 << 20),
		.erasesize = 0x2000,
		.options = 0,
	},
	{
		.name = "NAND 8MiB 3,3V 8-bit",
		.ids.id = {0x00, 0xd6,},
		.pagesize = 512,
		.chipsize = (8 << 20),
		.erasesize = 0x2000,
		.options = 0,
	},
	{
		.name = "NAND 8MiB 1,8V 8-bit",
		.ids.id = {0x00, 0x39,},
		.pagesize = 512,
		.chipsize = (8 << 20),
		.erasesize = 0x2000,
		.options = 0,
	},
	{
		.name = "NAND 8MiB 3,3V 8-bit",
		.ids.id = {0x00, 0xe6,},
		.pagesize = 512,
		.chipsize = (8 << 20),
		.erasesize = 0x2000,
		.options = 0,
	},
	{
		.name = "NAND 16MiB 1,8V 8-bit",
		.ids.id = {0x00, 0x33,},
		.pagesize = 512,
		.chipsize = (16 << 20),
		.erasesize = 0x4000,
		.options = 0,
	},
	{
		.name = "NAND 16MiB 3,3V 8-bit",
		.ids.id = {0x00, 0x73,},
		.pagesize = 512,
		.chipsize = (16 << 20),
		.erasesize = 0x4000,
		.options = 0,
	},
	{
		.name = "NAND 32MiB 1,8V 8-bit",
		.ids.id = {0x00, 0x35,},
		.pagesize = 512,
		.chipsize = (32 << 20),
		.erasesize = 0x4000,
		.options = 0,
	},
	{
		.name = "NAND 32MiB 3,3V 8-bit",
		.ids.id = {0x00, 0x75,},
		.pagesize = 512,
		.chipsize = (32 << 20),
		.erasesize = 0x4000,
		.options = 0,
	},
	{
		.name = "NAND 64MiB 1,8V 8-bit",
		.ids.id = {0x00, 0x36,},
		.pagesize = 512,
		.chipsize = (64 << 20),
		.erasesize = 0x4000,
		.options = 0,
	},
	{
		.name = "NAND 64MiB 3,3V 8-bit",
		.ids.id = {0x00, 0x76,},
		.pagesize = 512,
		.chipsize = (64 << 20),
		.erasesize = 0x4000,
		.options = 0,
	},
	{
		.name = "NAND 128MiB 1,8V 8-bit",
		.ids.id = {0x00, 0x78,},
		.pagesize = 512,
		.chipsize = (128 << 20),
		.erasesize = 0x4000,
		.options = 0,
	},
	{
		.name = "NAND 128MiB 1,8V 8-bit",
		.ids.id = {0x00, 0x39,},
		.pagesize = 512,
		.chipsize = (128 << 20),
		.erasesize = 0x4000,
		.options = 0,
	},
	{
		.name = "NAND 128MiB 3,3V 8-bit",
		.ids.id = {0x00, 0x79,},
		.pagesize = 512,
		.chipsize = (128 << 20),
		.erasesize = 0x4000,
		.options = 0,
	},
	{
		.name = "NAND 64MiB 1,8V 8-bit",
		.ids.id = {0x00, 0xA2,},
		.pagesize = 0,
		.chipsize = (64 << 20),
		.erasesize = 0,
		.options = 0,
	},
	{
		.name = "NAND 64MiB 3,3V 8-bit",
		.ids.id = {0x00, 0xF2,},
		.pagesize = 0,
		.chipsize = (64 << 20),
		.erasesize = 0,
		.options = 0,
	},
	{
		.name = "NAND 128MiB 1,8V 8-bit",
		.ids.id = {0x00, 0xA1,},
		.pagesize = 0,
		.chipsize = (128 << 20),
		.erasesize = 0,
		.options = 0,
	},
	{
		.name = "NAND 128MiB 3,3V 8-bit",
		.ids.id = {0x00, 0xF1,},
		.pagesize = 0,
		.chipsize = (128 << 20),
		.erasesize = 0,
		.options = 0,
	},
	{
		.name = "NAND 128MiB 3,3V 8-bit",
		.ids.id = {0x00, 0xD1,},
		.pagesize = 0,
		.chipsize = (128 << 20),
		.erasesize = 0,
		.options = 0,
	},
	{
		.name = "NAND 256MiB 1,8V 8-bit",
		.ids.id = {0x00, 0xAA,},
		.pagesize = 0,
		.chipsize = (256 << 20),
		.erasesize = 0,
		.options = 0,
	},
	{
		.name = "NAND 256MiB 3,3V 8-bit",
		.ids.id = {0x00, 0xDA,},
		.pagesize = 0,
		.chipsize = (256 << 20),
		.erasesize = 0,
		.options = 0,
	},
	{
		.name = "NAND 512MiB 1,8V 8-bit",
		.ids.id = {0x00, 0xAC,},
		.pagesize = 0,
		.chipsize = (512 << 20),
		.erasesize = 0,
		.options = 0,
	},
	{
		.name = "NAND 512MiB 3,3V 8-bit",
		.ids.id = {0x00, 0xDC,},
		.pagesize = 0,
		.chipsize = (512 << 20),
		.erasesize = 0,
		.options = 0,
	},
	{
		.name = "NAND 1GiB 1,8V 8-bit",
		.ids.id = {0x00, 0xA3,},
		.pagesize = 0,
		.chipsize = (1024 << 20),
		.erasesize = 0,
		.options = 0,
	},
	{
		.name = "NAND 1GiB 3,3V 8-bit",
		.ids.id = {0x00, 0xD3,},
		.pagesize = 0,
		.chipsize = (1024 << 20),
		.erasesize = 0,
		.options = 0,
	},
	{
		.name = "NAND 2GiB 1,8V 8-bit",
		.ids.id = {0x00, 0xA5,},
		.pagesize = 0,
		.chipsize = (2048 << 20),
		.erasesize = 0,
		.options = 0,
	},
	{
		.name = "NAND 2GiB 3,3V 8-bit",
		.ids.id = {0x00, 0xD5,},
		.pagesize = 0,
		.chipsize = (2048 << 20),
		.erasesize = 0,
		.options = 0,
	},
	{NULL},

};
