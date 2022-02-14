/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��˼�뵼�����޹�˾

 ******************************************************************************
  �� �� ��   : oal_cfg80211.h
  �� �� ��   : ����
  ��    ��   : 
  ��������   : 2016��2��29��
  ����޸�   :
  ��������   : oal_cfg80211.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2016��2��29��
    ��    ��   : 
    �޸�����   : �����ļ�

******************************************************************************/

#ifndef __OAL_LITEOS_CFG80211_H__
#define __OAL_LITEOS_CFG80211_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "los_typedef.h"

/*****************************************************************************
  2 �궨��
*****************************************************************************/
/* hostapd��supplicant�¼��ϱ���Ҫ�õ��� */
#define OAL_NLMSG_GOODSIZE   1920
#define OAL_ETH_ALEN_SIZE         6
#define OAL_NLMSG_DEFAULT_SIZE (OAL_NLMSG_GOODSIZE - OAL_NLMSG_HDRLEN)
#define OAL_IEEE80211_MIN_ACTION_SIZE 1000

#define OAL_NLA_PUT_U32(skb, attrtype, value)      NLA_PUT_U32(skb, attrtype, value)
#define OAL_NLA_PUT(skb, attrtype, attrlen, data)  NLA_PUT(skb, attrtype, attrlen, data)
#define OAL_NLA_PUT_U16(skb, attrtype, value)      NLA_PUT_U16(skb, attrtype, value)
#define OAL_NLA_PUT_U8(skb, attrtype, value)       NLA_PUT_U8(skb, attrtype, value)
#define OAL_NLA_PUT_FLAG(skb, attrtype)            NLA_PUT_FLAG(skb, attrtype)

typedef enum  rate_info_flags  oal_rate_info_flags;

/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/

/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/

/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/

/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of oal_cfg80211.h */