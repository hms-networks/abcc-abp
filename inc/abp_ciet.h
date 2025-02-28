/*******************************************************************************
********************************************************************************
** COPYRIGHT NOTIFICATION (c) 2022 HMS Industrial Networks AB                 **
**                                                                            **
** This program is the property of HMS Industrial Networks AB.                **
** It may not be reproduced, distributed, or used without permission          **
** of an authorized company official.                                         **
********************************************************************************
********************************************************************************
** Anybus-CC Protocol - CC-Link IE TSN Definitions.
**
** This software component contains protocol definitions used by the CC-Link IE
** TSN Anybus-CC module as well as applications designed to use such
** modules.
**
** The generic portion used by all Anybus-CC modules is available in the file
** ABP.H.
********************************************************************************
********************************************************************************
** Services:
********************************************************************************
********************************************************************************
*/

#ifndef ABP_CIET_H
#define ABP_CIET_H

/*******************************************************************************
** Constants
********************************************************************************
*/
/*------------------------------------------------------------------------------
** CC-Link IE TSN object instance attributes
**------------------------------------------------------------------------------
*/
#define ABP_CIET_IA_VENDOR_CODE          1
#define ABP_CIET_IA_VENDOR_NAME          2
#define ABP_CIET_IA_MODEL_CODE           3
#define ABP_CIET_IA_EXPANSION_MODEL_CODE 4
#define ABP_CIET_IA_MODEL_NAME           5
#define ABP_CIET_IA_DEVICE_TYPE          6
#define ABP_CIET_IA_DEVICE_VERSION       7
#define ABP_CIET_IA_FW_VERSION           8
#define ABP_CIET_IA_HW_VERSION           9
#define ABP_CIET_IA_SERIAL_NUMBER        10

/*------------------------------------------------------------------------------
** The data size of the CC-Link IE TSN object instance attributes
** (in bytes).
**------------------------------------------------------------------------------
*/
#define ABP_CIET_VENDOR_NAME_STR_LEN   32
#define ABP_CIET_MODEL_NAME_STR_LEN    20
#define ABP_CIET_SERIAL_NUMBER_STR_LEN 32

#define ABP_CIET_IA_VENDOR_CODE_DS          ABP_UINT16_SIZEOF
#define ABP_CIET_IA_VENDOR_NAME_DS          ( ABP_CHAR_SIZEOF * ABP_CIET_VENDOR_NAME_STR_LEN )
#define ABP_CIET_IA_MODEL_CODE_DS           ABP_UINT32_SIZEOF
#define ABP_CIET_IA_EXPANSION_MODEL_CODE_DS ABP_UINT16_SIZEOF
#define ABP_CIET_IA_MODEL_NAME_DS           ( ABP_CHAR_SIZEOF * ABP_CIET_MODEL_NAME_STR_LEN )
#define ABP_CIET_IA_DEVICE_TYPE_DS          ABP_UINT16_SIZEOF
#define ABP_CIET_IA_DEVICE_VERSION_DS       ABP_UINT16_SIZEOF
#define ABP_CIET_IA_FW_VERSION_DS           ABP_UINT16_SIZEOF
#define ABP_CIET_IA_HW_VERSION_DS           ABP_UINT8_SIZEOF
#define ABP_CIET_IA_SERIAL_NUMBER_DS        ( ABP_CHAR_SIZEOF * ABP_CIET_SERIAL_NUMBER_STR_LEN )

#endif  /* inclusion lock */
