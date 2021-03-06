/******************************************************************************
*
* Copyright (C) 2017 Hisilicon Technologies Co., Ltd.  All rights reserved.
*
* This program is confidential and proprietary to Hisilicon  Technologies Co., Ltd. (Hisilicon),
* and may not be copied, reproduced, modified, disclosed to others, published or used, in
* whole or in part, without the express prior written permission of Hisilicon.
*
******************************************************************************
File Name        : jpeg_hdec_mem.h
Version           : Initial Draft
Author            :
Created          : 2017/07/05
Description     :
Function List   :


History           :
Date                      Author           Modification
2017/07/05            sdk              Created file
******************************************************************************/
#ifndef __JPEG_HDEC_API_H__
#define __JPEG_HDEC_API_H__


/*********************************add include here********************************/
#include  "jpeglib.h"

#include  "hi_jpeg_config.h"
#include  "hi_jpeg_api.h"

#include  "hi_drv_jpeg.h"
#include  "jpeg_hdec_rwreg.h"

#ifdef CONFIG_JPEG_EXIF_SUPPORT
#include "jpeg_sdec_exif.h"
#endif

#include "jpeg_sdec_color.h"


#ifdef CONFIG_JPEG_SAVE_SCEN
#include "hi_jpeg_reg.h"
#endif

/*****************************************************************************/

#ifdef __cplusplus
#if __cplusplus
   extern "C" {
#endif
#endif /* __cplusplus */


    /***************************** Macro Definition ******************************/
     #define CONFIG_JPEG_SCALE_MULTIPLE_8                           (3)
     #define CONFIG_JPED_INPUT_DATA_BUFFER_NUM                      (2)

     #define CONFIG_JPED_INPUT_DATA_BUFFER_ALIGN                    (128)
     #define CONFIG_JPED_INPUT_DATA_ONE_BUFFER_RESERVE_SIZE         (128)
     #define CONFIG_JPED_INPUT_DATA_ONE_BUFFER_SIZE                 (256 * 1024)

     #define JPEG_API_MODULE_DEFINE_HANDLE()\
              JPEG_HDEC_HANDLE_S_PTR pJpegHandle = NULL;\
              pJpegHandle = (JPEG_HDEC_HANDLE_S_PTR)(cinfo->client_data);\
              if (NULL == pJpegHandle)\
              {\
                 ERREXIT(cinfo, JERR_NULL_POINT);\
              }
     /*************************** Enum Definition ****************************/


    /*************************** Structure Definition ****************************/
     typedef struct tatINPUT_STREAM_BUF_S
     {
         HI_BOOL UseSecondInputBuf;           /**<-- use second input buffer     >**//**<-- ??????????????????buffer >**/
         HI_BOOL SupportUserPhyInputDataBuf;  /**<-- whether user input data buffer is physical      >**//**<-- ??????????????????????buffer ????????>**/
         HI_BOOL SupportUserInputBufReturn;   /**<-- check whether stream save with two buffer  >**//**<-- ?????????????????????? >**/
         HI_BOOL UserInputDataEof;            /**<-- check the input data whether has been read empty, file or vir mem used  >**//**<-- ????????????????????????>**/
         HI_CHAR *pUserSecondInputDataVirBuf; /**<-- this is second input data virtual buffer  >**//**<-- ??????????????????????????????>**/
         HI_CHAR *pUserFirstInputDataVirBuf;  /**<-- this is first input data virtual buffer or input data start virtual buffer   >**//**<-- ??????????????????>**/
         HI_U32 UserInputDataPhyBuf;          /**<-- input one or pool physical buffer start address  >**//**<-- ?????????????????????????? >**/
         HI_ULONG UserTotalInputBufSize;      /**<-- input one or pool buffer size   >**//**<-- ?????????????????????? >**/
         HI_ULONG UserFirstInputBufSize;      /**<-- first input data buffer size       >**//**<-- ????????????????????????????>**/
         HI_ULONG UserSecondInputBufSize;     /**<-- second input data buffer size  >**//**<-- ???????????????????????????? >**/
         HI_ULONG UserInputCurPos;            /**<-- the input data current position, file or vir mem used  >**//**<-- ??????????????????????????????>**/
         HI_ULONG UserDataHasBeenReadSize;    /**<-- the input data has been read size, memory return used  >**//**<-- ??????????????????????????????????????????>**/
     }INPUT_STREAM_BUF_S;

     typedef struct tagINPUT_DATA_BUF_S
     {
         HI_BOOL DecDataEof;          /**<-- check whether decode buffer is empty                  >**//**<-- ?????????????????????????????? >**/
         HI_BOOL SaveStreamBufBusy;   /**<-- check whether current save stream buffer is busy  >**//**<-- ????????????buffer ????????????????????>**/
         HI_CHAR *pSaveStreamVirBuf;  /**<-- input data virtual buffer that be use to decode        >**//**<-- ????????buffer  ???????? >**/
         HI_U32 SaveStreamPhyBuf;     /**<-- input data physical buffer that be use to decode     >**//**<-- ????????buffer ???????????? >**/
     }INPUT_DEC_DATA_BUF_S;

     typedef struct tagJPEG_INPUT_DATA_BUF_INFO_S
     {
         HI_BOOL bUseInsideData;               /**<-- dispose stream with inside or callback  >**//**<-- ??????????????????????????????????>**/
         HI_BOOL EnReadToInputDataBuf;         /**<-- enable read input data to save stream buffer with callback used  >**//**<-- ????????????????????buffer ??>**/
         HI_BOOL BeginReadToInputDataBuf;      /**<-- begin read input data to save stream buffer  >**//**<-- ????????????????buffer  ?? >**/
         HI_U32 SaveStreamBufSize;             /**<-- input data buffer size that be use to decode  >**//**<-- ????????buffer  ???? >**/
         HI_U32 DecDataBufIndex;               /**<-- decode use which buffer    >**//**<-- ????????????????buffer  >**/
         HI_U32 SaveStreamBufIndex;            /**<-- save data to which buffer  >**//**<-- ????????????????????????buffer >**/
         INPUT_STREAM_BUF_S stInputStreamBuf;  /**<-- input data buffer infomation >**//**<-- ????????buffer ???? >**/
         INPUT_DEC_DATA_BUF_S stSaveStreamBuf[CONFIG_JPED_INPUT_DATA_BUFFER_NUM]; /**<-- hard decode data buffer >**//**<-- ??????????????????buffer ???? >**/
     }JPEG_INPUT_DATA_BUF_INFO_S;

    /** the jpeg sof information??the hard decode is only use dec para */
    /** CNcomment:jpeg?????????????????????????????????????????? */
    typedef struct tagJPEG_HDEC_SOFINFO_S
    {
         HI_BOOL bCalcSize;        /**< the jpeg size has  calculated >**//**<CNcomment:jpeg??????????????????????????????????  >**/
         HI_U32  u32YWidth;        /**< the lu width                 >**//**<CNcomment:??????????        >**/
         HI_U32  u32YHeight;       /**< the lu height                >**//**<CNcomment:????????              >**/
         HI_U32  u32YMcuHeight;    /**< the lu height,mcu align >**//**<CNcomment:??????????MCU????>**/
         HI_U32  u32YSize;         /**< the lu size                   >**//**<CNcomment:????????          >**/
         HI_U32  u32CWidth;        /**< the ch width                >**//**<CNcomment:????????          >**/
         HI_U32  u32CHeight;       /**< the ch height               >**//**<CNcomment:????????          */
         HI_U32  u32CMcuHeight;    /**< the ch height,mcu align >**//**<CNcomment:??????????MCU???? >**/
         HI_U32  u32CSize;         /**< the ch size                   >**//**<CNcomment:????????          >**/
         HI_U32  u32YStride;       /**< the lu stride                 >**//**<CNcomment:??????????     >**/
         HI_U32  u32CbCrStride;    /**< the ch stride                >**//**<CNcomment:??????????     >**/
         HI_U32  DecOutWidth;      /**< the dec width               >**//**<CNcomment:????????          >**/
         HI_U32  DecOutHeight;     /**< the dec height              >**//**<CNcomment:????????          >**/
         HI_U32  DecOutStride;     /**< the display stride          >**//**<CNcomment:??????????    >**/
         HI_U32  u32InWandH;       /**< set to register size       >**//**<CNcomment:????????????????  >**/
         #ifdef CONFIG_JPEG_HARDDEC2ARGB
         HI_U32  u32McuWidth;      /**< the mcu width        >**/
         HI_U32  u32MINSize;       /**< the min size           >**/
         HI_U32  u32MIN1Size;      /**< the min1 size         >**/
         HI_U32  u32RGBSizeReg;    /**< set to register size >**//**<CNcomment:??????????????????  >**/
         #endif
    }JPEG_HDEC_SOFINFO_S;

    typedef struct tagJPEG_MIDDLE_SURFACE_S
    {
         HI_CHAR* pOutVir; /**<  csc output virtual buffer  >**//**<CNcomment:????????????????????????   */
         HI_CHAR* DecOutVir[MAX_PIXEL_COMPONENT_NUM];  /**< jpeg hard dec output vitual  buffer   >**//**<CNcomment:jpeg ????????????????????  */
         HI_U32 DecOutPhy[MAX_PIXEL_COMPONENT_NUM];    /**< jpeg hard dec output physics buffer >**//**<CNcomment:jpeg ????????????????????  */
         HI_U32   OutPhy; /**<  csc output physics buffer    >**//**<CNcomment:????????????????????????   */
    }JPEG_MIDDLE_SURFACE_S;

    typedef struct tagJPEG_HDEC_HANDLE_S
    {
          volatile HI_CHAR *pJpegRegVirAddr;  /**<-- mmap the jpeg virtual address  >**//**<CNcomment:jpeg??????????????????         >**/
          HI_BOOL bHasHufTable;
          HI_BOOL bDiscardScanlines;          /**<-- skip scan lines  >**//**<CNcomment: ????????>**/
          HI_BOOL bSeekToSoftDec;             /**<-- seek to soft decode  >**//**<CNcomment: ??????????????>**/
          HI_BOOL bOutUsrBuf;                 /**<-- whether out to usr buffer  >**//**<CNcomment: ????????????????????buffer ??>**/
          HI_BOOL SupportHardDec;             /**<-- whether support hard decode  >**//**<CNcomment: ????????????????>**/
          HI_BOOL EnStopDecode;               /**<-- whether support stop decode in decoding  >**//**<CNcomment: ??????????????????????????>**/
          HI_BOOL bHdecEnd;                   /**<-- hard decode success  >**//**<CNcomment:????????????>**/
          HI_BOOL bCSCEnd;                    /**<--color space convert success  >**//**<CNcomment:???????????????? >**/
          HI_BOOL bOutYCbCrSP;                /**<--if output yuvsp  >**//**<CNcomment:????????????yuv semi_planer    >**/
          HI_BOOL bDecOutColorSpaecXRGB;      /**<--the jpeg support dec to argb  >**//**<CNcomment:jpeg????????????????ARGB        >**/
          HI_BOOL bCheckedSupportHardDec;     /**<-- has been check whether support hard decode  >**//**<CNcomment:??????????????????????????>**/
          HI_BOOL bCrop;                      /**<--  if crop  >**//**<CNcomment:???????? CNend*/
          HI_BOOL bSetCropRect;               /**< -- if has been set crop rect >**//**<CNcomment: ??????????????????>**/
          HI_U32  u32MinPhyBuf;               /**<-- dec to argb need row buffer  >**//**<CNcomment:????????ARGB????????buffer      >**/
          HI_U32  SkipLines;                  /**<-- skip output lines >**//**<CNcomment:??????????????>**/
          #ifdef CONFIG_JPEG_SAVE_SCEN
          HI_S32  s32RegData[JPGD_REG_LENGTH];/**<--save scen>**//**<CNcomment:????????????>**/
          FILE* pScenFile;
          #endif
          HI_S32  s32LuDcLen[6];              /**<-- huffman lu dc codelenght  >**//**<CNcomment:????DC??????CodeLength >**/
          HI_BOOL  bOutYUV420SP;              /**<--all dec output yuv420sp     >**//**<CNcomment:????????yuv420sp???? >**/
          #ifdef CONFIG_JPEG_OUTPUT_LUPIXSUM
          HI_U64   u64LuPixValue;             /**<--the lu pixle value  >**//**<CNcomment:????????>**/
          #endif
          HI_U32   HardDecTimes;              /**<--hard decode cost times  >**//**<CNcomment:??????????????????>**/
          HI_U32   DecCostTimes;              /**<--calc the decode time  >**//**<CNcomment:????????????>**/
          #ifdef CONFIG_JPEG_LOW_DELAY_SUPPORT
          HI_BOOL  bLowDelayEn;
          HI_U32   u32PhyLineBuf;
          HI_CHAR* pVirLineBuf;
          #endif
          HI_S32   s32QuantTab[DCTSIZE2];
          HI_U32   u32HuffDcTab[12];
          HI_U32   u32HufAcMinTab[DCTSIZE];
          HI_U32   u32HufAcBaseTab[DCTSIZE];
          HI_U32   u32HufAcSymbolTab[256];
          HI_S32   s32ClientData; /**<--the client pointer of private structure   >***//**<CNcomment:??????????????>***/
          HI_S32   JpegDev;       /**<--the jpeg device  >**//**<CNcomment:jpeg???? >**/
          HI_S32   CscDev;
          HI_S32   MemDev;
          HI_U32   ScalRation;    /**<--the dec scale   >**//**<CNcomment:????????  >**/
          HI_BOOL  bReleaseRes;   /**<--the resouce has release   >**//**<CNcomment:????????????????>**/
          #ifdef CONFIG_GFX_MEM_ION
          HI_VOID *pSaveStreamMemHandle;
          HI_VOID *pMiddleMemHandle;
          HI_VOID *pMinMemHandle;
          HI_VOID *pOutMemHandle;
          #endif
          HI_U32 ResByteConsum; /**<--consume byte after suspend  >**//**<CNcomment:????????????????   >**/
          HI_U8 u8Fac[MAX_PIXEL_COMPONENT_NUM][2];/**< save the sample factor   >**//**<CNcomment:???????????????? >**/
          HI_JPEG_RECT_S stCropRect; /**<-- output crop size >**//**<--???????????? >**/
          JPEG_HDEC_SOFINFO_S  stJpegSofInfo;     /**< the jpeg sof information               >**//**<CNcomment:jpeg????????????           >**/
          JPEG_INPUT_DATA_BUF_INFO_S  stInputDataBufInfo; /**< the hard decode data buffer message    >**/
          HI_JPEG_FMT_E enImageFmt; /**< jpeg picture type   >**//**<CNcomment:jpeg????????>**/
          HI_JPEG_SURFACE_S  stOutSurface; /**< the user output message description    >**//**<CNcomment:??????????????????????     */
          JPEG_MIDDLE_SURFACE_S  stDecSurface;
          JPEG_SDEC_COLOR_CONVERT_S stSdecColorConvert;
          #ifdef CONFIG_JPEG_EXIF_SUPPORT
	      HI_BOOL  bExifSupport; /**<-- exif para define begine,  support exif mark >**//**<-- ????????exif  ??????????????exif >**/
	      HI_BOOL  bIsHDR;
	      HI_U8    u8ImageCount;
	      HI_CHAR* pThumbnailAddr;
	      HI_U32   u32ThumbnailSize;
          JPEG_EXIF_INFO_S  stExifInfo;
          #endif
    }JPEG_HDEC_HANDLE_S,*JPEG_HDEC_HANDLE_S_PTR;

    /********************** Global Variable declaration *****************************/

    /******************************* API declaration *****************************/

    /************************************************************************/


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif /* __JPEG_HDEC_API_H__*/
