/*******************************************************************************
********************************************************************************
** COPYRIGHT NOTIFICATION (c) 2017 HMS Industrial Networks AB                 **
**                                                                            **
** This code is the property of HMS Industrial Networks AB.                   **
** The source code may not be reproduced, distributed, or used without        **
** permission. When used together with a product from HMS, permission is      **
** granted to modify, reproduce and distribute the code in binary form        **
** without any restrictions.                                                  **
**                                                                            **
** THE CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND. HMS DOES NOT    **
** WARRANT THAT THE FUNCTIONS OF THE CODE WILL MEET YOUR REQUIREMENTS, OR     **
** THAT THE OPERATION OF THE CODE WILL BE UNINTERRUPTED OR ERROR-FREE, OR     **
** THAT DEFECTS IN IT CAN BE CORRECTED.                                       **

********************************************************************************
********************************************************************************
** This file contains OPC UA specific definitions.
********************************************************************************
********************************************************************************
*/

#ifndef ABP_OPCUA_H_
#define ABP_OPCUA_H_

/*------------------------------------------------------------------------------
** OPC UA instance attributes
**------------------------------------------------------------------------------
*/
#define ABP_OPCUA_IA_MODEL                   1
#define ABP_OPCUA_IA_APPLICATION_URI         2
#define ABP_OPCUA_IA_VENDOR_NAMESPACE_URI    3
#define ABP_OPCUA_IA_DEVICE_TYPE_NAME        4
#define ABP_OPCUA_IA_DEVICE_INST_NAME        5
#define ABP_OPCUA_IA_PRODUCT_URI             6
#define ABP_OPCUA_IA_LIMITS                  7
#define ABP_OPCUA_IA_APPLICATION_MODELS      8
#define ABP_OPCUA_IA_STATUS                  9

/*------------------------------------------------------------------------------
** The data size of the OPC UA instance attributes
**------------------------------------------------------------------------------
*/
#define ABP_OPCUA_IA_MODEL_DS                    ( ABP_UINT8_SIZEOF )
#define ABP_OPCUA_IA_APPLICATION_URI_MAX_DS      ( 128 * ABP_CHAR_SIZEOF )
#define ABP_OPCUA_IA_VENDOR_NAMESPACE_URI_MAX_DS ( 128 * ABP_CHAR_SIZEOF )
#define ABP_OPCUA_IA_DEVICE_TYPE_NAME_MAX_DS     ( 64 * ABP_CHAR_SIZEOF )
#define ABP_OPCUA_IA_DEVICE_INST_NAME_MAX_DS     ( 64 * ABP_CHAR_SIZEOF )
#define ABP_OPCUA_IA_PRODUCT_URI_MAX_DS          ( 128 * ABP_CHAR_SIZEOF )
#define ABP_OPCUA_IA_LIMITS_DS                   ( ABP_UINT16_SIZEOF + ABP_UINT32_SIZEOF + ABP_UINT32_SIZEOF + ABP_UINT32_SIZEOF )
#define ABP_OPCUA_IA_APPLICATION_MODELS_MAX_DS   ( ABP_OPCUA_IA_APPLICATIONS_MODELS_MAX * ( ABP_UINT8_SIZEOF + ABP_UINT8_SIZEOF + ABP_UINT16_SIZEOF ) )
#define ABP_OPCUA_IA_STATUS_DS                   ( ABP_ENUM_SIZEOF + ABP_UINT8_SIZEOF )

/*------------------------------------------------------------------------------
** Values of Model attribute
**------------------------------------------------------------------------------
*/
typedef enum ABP_OpcuaModel
{
   ABP_OPCUA_MODEL_DISABLED            = 0,
   ABP_OPCUA_MODEL_CC40                = 1,
   ABP_OPCUA_MODEL_APPLICATION         = 2
}
ABP_OpcuaModelType;

/*------------------------------------------------------------------------------
** Valid ranges for the "Limits" attribute
**------------------------------------------------------------------------------
*/
#define ABP_OPCUA_IA_LIMITS_MAX_MON_ITEMS_MIN    ( 8 )
#define ABP_OPCUA_IA_LIMITS_MAX_MON_ITEMS_MAX    ( 100 )
#define ABP_OPCUA_IA_LIMITS_MIN_PUB_INT_MIN      ( 1000 )
#define ABP_OPCUA_IA_LIMITS_MIN_PUB_INT_MAX      ( 1000 * 3600 * 24 )
#define ABP_OPCUA_IA_LIMITS_MIN_SAMPLING_INT_MIN ( 10 )
#define ABP_OPCUA_IA_LIMITS_MIN_SAMPLING_INT_MAX ( 1000 * 3600 * 24 )
#define ABP_OPCUA_IA_LIMITS_MAX_QUEUE_SIZE_MIN   ( 1 )
#define ABP_OPCUA_IA_LIMITS_MAX_QUEUE_SIZE_MAX   ( 110 )

/*------------------------------------------------------------------------------
** Values of Status attribute
**------------------------------------------------------------------------------
*/
typedef enum ABP_OpcuaState
{
   ABP_OPCUA_STATUS_NOT_STARTED                    = 0,
   ABP_OPCUA_STATUS_INITIALIZING                   = 1,
   ABP_OPCUA_STATUS_RUNNING                        = 2,
   ABP_OPCUA_STATUS_CLIENT_CONNECTED               = 3,
   ABP_OPCUA_STATUS_STOPPED                        = 4,
   ABP_OPCUA_STATUS_GENERAL_FAILURE                = 128,
   ABP_OPCUA_STATUS_READING_NODESET_FILE_FAILED    = 129,
   ABP_OPCUA_STATUS_NO_SERVER_CERTIFICATE          = 130,
   ABP_OPCUA_STATUS_INVALID_SERVER_CERTIFICATE_URI = 131,
   ABP_OPCUA_STATUS_INVALID_MODEL_ATTRIBUTE        = 132

}
ABP_OpcuaStateType;

/*------------------------------------------------------------------------------
** Max number of application models that a user can specify
**------------------------------------------------------------------------------
*/
#define ABP_OPCUA_IA_APPLICATIONS_MODELS_MAX 35

/*------------------------------------------------------------------------------
** OPC UA Object specific commands
**------------------------------------------------------------------------------
*/

#define ABP_OPCUA_CMD_METHOD_CALL   0x10
#define ABP_OPCUA_CMD_GET_APPLICATION_MODELS_FILENAME  0x11
#define ABP_OPCUA_CMD_GET_APPLICATION_MODELS_NAMESPACE 0x12

/*------------------------------------------------------------------------------
** Application data value types
**------------------------------------------------------------------------------
*/
typedef enum ABP_OpcuaApplicationDataValue
{
   ABP_OPCUA_DATA_VALUE_SCALAR   = 0,
   ABP_OPCUA_DATA_VALUE_ARRAY    = 1
}
ABP_OpcuaApplicationDataValueType;


#endif  /* inclusion lock */
