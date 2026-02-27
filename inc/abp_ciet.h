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
#define ABP_CIET_IA_CLOCK_OFFSET         11
#define ABP_CIET_IA_PROC_DATA_ALLOC      12

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
#define ABP_CIET_IA_CLOCK_OFFSET_DS         ( ABP_UINT64_SIZEOF + ABP_UINT32_SIZEOF + 2 * ABP_UINT16_SIZEOF )
#define ABP_CIET_IA_PROC_DATA_ALLOC_DS      ( ( ABP_UINT32_SIZEOF + ABP_UINT16_SIZEOF ) * 3 * 2 + ABP_ENUM_SIZEOF )

/*******************************************************************************
** Typedefs
********************************************************************************
*/
/*------------------------------------------------------------------------------
** Structure describing attribute#11: Clock offset
**------------------------------------------------------------------------------
*/
ABCC_SYS_PACK_ON
typedef struct ABP_CIET_ClockOffset
{
   INT64 llOffsetSec;
   INT32 lOffsetNanoSec;
   INT16 iUtcOffsetMin;
   INT16 iSummerTimeOffsetMin;
}
PACKED_STRUCT ABP_CIET_ClockOffsetType;
ABCC_SYS_PACK_OFF

/*------------------------------------------------------------------------------
** Enum for attribute#12 process data allocation notification
**------------------------------------------------------------------------------
*/
typedef enum ABP_CIET_ProcDataAllocNotification
{
   /* Result of the automatic process data mapping calculated from the ADIs.
      It mirrors the actual ABCC memory map layout.
   */
   ABP_CIET_NOTIFY_AUTO_MAPPING           = 0x00,
   /* Result of the process data allocation command after explicitly setting the
      process data addresses and sizes.
      It mirrors the actual ABCC memory map layout.
   */
   ABP_CIET_NOTIFY_ALLOCATION_ACK         = 0x01,
   /* Process data allocation command rejected due to address conflicts in given
      process data addresses and sizes.
      ABCC memory map layout was not changed by allocation command.
   */
   ABP_CIET_NOTIFY_ALLOCATION_NACK_RANGE  = 0x02,
   /* Process data allocation command rejected due to size conflicts in given
      process data addresses and sizes.
      ABCC memory map layout was not changed by allocation command.
   */
   ABP_CIET_NOTIFY_ALLOCATION_NACK_SIZE   = 0x03,
   /* Contents of SlmpCyclicConfigTrnSubPayload-PDU request sent by the master
      station. It does not represent the actual ABCC memory map layout, the
      memory map layout is unaffected.
   */
   ABP_CIET_NOTIFY_CYCLIC_CONFIG_TRN      = 0x10,
   /* Contents of SlmpCyclicConfigRcvSubPayload-PDU request sent by the master
      station. It does not represent the actual ABCC memory map layout, the
      memory map layout is unaffected.
   */
   ABP_CIET_NOTIFY_CYCLIC_CONFIG_RCV      = 0x11,

   ABP_CIET_NOTIFY_LAST_VALUE
}
ABP_CIET_ProcDataAllocNotificationType;

/*------------------------------------------------------------------------------
** Structure describing attribute#12: Process data allocation in ABCC memory map
**------------------------------------------------------------------------------
*/
ABCC_SYS_PACK_ON
typedef struct ABP_CIET_ProcDataAlloc
{
   UINT32   lSndBitAddress;      /* 0000h <= lSndBitAddress < 0FFFh                          */
   UINT16   iSndBitSize;         /* Size of the send bit data (RX) in number of bytes        */
   UINT32   lSndWordAddress;     /* SndBitAddress + SndBitSize <= SndWordAddress < 0FFFh     */
   UINT16   iSndWordSize;        /* Size of the send word data (RWr) in number of bytes      */
   UINT32   lSndSafetyAddress;   /* SndWordAddress + SndWordSize <= SndSafetyAddress < 0FFFh */
   UINT16   iSndSafetySize;      /* Size of the send Safety PDU in number of bytes           */
   UINT32   lRcvBitAddress;      /* 1000h <= RcvBitAddress < 0FFFh                           */
   UINT16   iRcvBitSize;         /* Size of the receive bit data (RY) in number of bytes     */
   UINT32   lRcvWordAddress;     /* RcvBitAddress + RcvBitSize <= RcvWordAddress < 0FFFh     */
   UINT16   iRcvWordSize;        /* Size of the receive word data (RWw) in number of bytes   */
   UINT32   lRcvSafetyAddress;   /* RcvWordAddress + RcvWordSize <= RcvSafetyAddress < 0FFFh */
   UINT16   iRcvSafetySize;      /* Size of the receive Safety PDU in number of bytes        */
   UINT8    bNotify;             /* ABP_CIET_ProcDataAllocNotificationType, Set access only  */
}
PACKED_STRUCT ABP_CIET_ProcDataAllocType;
ABCC_SYS_PACK_OFF

#endif  /* inclusion lock */
