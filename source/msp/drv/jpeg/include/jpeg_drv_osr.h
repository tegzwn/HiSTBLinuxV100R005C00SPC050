/******************************************************************************
*
* Copyright (C) 2017 Hisilicon Technologies Co., Ltd.  All rights reserved.
*
* This program is confidential and proprietary to Hisilicon  Technologies Co., Ltd. (Hisilicon),
* and may not be copied, reproduced, modified, disclosed to others, published or used, in
* whole or in part, without the express prior written permission of Hisilicon.
*
******************************************************************************
File Name        : jpeg_drv_osr.h
Version           : Initial Draft
Author            :
Created          : 2017/07/05
Description     : The user will use this api to realize some function
Function List   :


History           :
Date                    Author                Modification
2017/07/05           sdk                   Created file
******************************************************************************/
#ifndef __JPEG_DRV_OSR_H__
#define __JPEG_DRV_OSR_H__


/*********************************add include here******************************/
#include <linux/syscalls.h>
#include <linux/ipc.h>

#include "hi_jpeg_config.h"
#include "hi_drv_jpeg.h"
#include "hi_type.h"
/*****************************************************************************/


#ifdef __cplusplus
#if __cplusplus
   extern "C" {
#endif
#endif /* __cplusplus */



     /***************************** Macro Definition ******************************/

     #define CONFIG_JPEG_FIND_SYSTEM_ABNORMAL_TIMES   100

     /*************************** Enum Definition *********************************/

    /*************************** Structure Definition *****************************/
    /** jpeg device imformation */
    /** CNcomment:jpeg设备信息 */
    typedef struct hiJPG_OSRDEV_S
    {
        HI_BOOL bSuspendSignal;        /**< whether get suspend signal  *//**<CNcomment:获取待机信号         */
        HI_BOOL bResumeSignal;         /**< whether get resume signal   *//**<CNcomment:获取待机唤醒信号  */
        HI_BOOL bLock;                 /**< 已经处于锁状态              **/
        HI_U32  LockCnt;
        HI_U32  SystemAbnormalTimes;
        wait_queue_head_t  QWaitInt;   /**< waite halt queue              **/
        wait_queue_head_t  QWaitMutex; /**< 释放信号量           **/
        JPEG_INTTYPE_E IntType;        /**< lately happened halt type  **/
    }JPG_OSRDEV_S;

    /** \addtogroup      JPEG */
    /** @{ */    /** <!--[JPEG]*/


    /** @} */  /** <!-- ==== Structure Definition End ==== */

    /********************** Global Variable declaration **************************/

    /******************************* API declaration *****************************/

    /** \addtogroup      JPEG */
    /** @{ */    /** <!--[JPEG]*/

    /***************************************************************************************
    * func          : DRV_JPEG_OffClock
    * description   : close the jpeg clock
                      CNcomment: 关闭jpeg时钟 CNend\n
    * param[in]     : HI_VOID
    * retval        : NA
    * others:       : NA
    ***************************************************************************************/
    HI_VOID DRV_JPEG_OffClock(HI_VOID);


    /***************************************************************************************
    * func          : DRV_JPEG_OnClock
    * description   : open the jpeg clock
                      CNcomment: 打开jpeg时钟 CNend\n
    * param[in]     : HI_VOID
    * retval        : NA
    * others:       : NA
    ***************************************************************************************/
    HI_VOID DRV_JPEG_OnClock(HI_VOID);

    /** @} */  /** <!-- ==== API Declaration End ==== */

    /****************************************************************************/



#ifdef __cplusplus

#if __cplusplus

}
#endif
#endif /* __cplusplus */

#endif /* __JPEG_DRV_OSR_H__*/
