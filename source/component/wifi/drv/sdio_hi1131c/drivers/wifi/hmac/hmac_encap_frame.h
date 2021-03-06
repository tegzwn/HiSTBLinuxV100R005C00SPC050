/******************************************************************************

                  版权所有 (C), 2001-2011, 海思半导体有限公司

 ******************************************************************************
  文 件 名   : hmac_encap_frame.h
  版 本 号   : 初稿
  作    者   : 
  生成日期   : 2013年6月28日
  最近修改   :
  功能描述   : hmac_encap_frame.c 的头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2013年6月28日
    作    者   : 
    修改内容   : 创建文件

******************************************************************************/

#ifndef __HMAC_ENCAP_FRAME_H__
#define __HMAC_ENCAP_FRAME_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "oal_ext_if.h"
#include "hmac_user.h"
#include "mac_vap.h"

/*****************************************************************************
  2 宏定义
*****************************************************************************/


/*****************************************************************************
  3 枚举定义
*****************************************************************************/


/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/


/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/
extern oal_uint16  hmac_mgmt_encap_deauth(mac_vap_stru *pst_mac_vap, oal_uint8 *puc_data, oal_uint8 *puc_da, oal_uint16 us_err_code);
extern oal_uint16  hmac_mgmt_encap_disassoc(mac_vap_stru *pst_mac_vap, oal_uint8 *puc_data, oal_uint8 *puc_da, oal_uint16 us_err_code);
extern oal_uint16  hmac_encap_sa_query_req(mac_vap_stru *pst_mac_vap, oal_uint8 *puc_data, oal_uint8 *puc_da,oal_uint16 us_trans_id);
extern oal_uint16  hmac_encap_sa_query_rsp(mac_vap_stru *pst_mac_vap, oal_uint8 *pst_hdr, oal_uint8 *puc_data);
extern oal_void  hmac_check_sta_base_rate(oal_uint8 *pst_user, mac_status_code_enum_uint16 *pen_status_code);
extern oal_uint16 hmac_encap_notify_chan_width(mac_vap_stru *pst_mac_vap, oal_uint8 *puc_data, oal_uint8 *puc_da);










#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of hmac_encap_frame.h */
