/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

_WdfVersionBuild_

Module Name:

    wdfroletypes.h

Abstract:

    Various typedefs for convenience.

Environment:

    kernel mode only

Revision History:

--*/

//
// NOTE: This header is generated by stubwork.  Please make any
//       modifications to the corresponding template files
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _WDFROLETYPES_H_
#define _WDFROLETYPES_H_

#ifndef WDF_EXTERN_C
  #ifdef __cplusplus
    #define WDF_EXTERN_C       extern "C"
    #define WDF_EXTERN_C_START extern "C" {
    #define WDF_EXTERN_C_END   }
  #else
    #define WDF_EXTERN_C
    #define WDF_EXTERN_C_START
    #define WDF_EXTERN_C_END
  #endif
#endif

WDF_EXTERN_C_START



typedef EVT_WDF_OBJECT_CONTEXT_CLEANUP EVT_WDF_DEVICE_CONTEXT_CLEANUP;
typedef EVT_WDF_OBJECT_CONTEXT_DESTROY EVT_WDF_DEVICE_CONTEXT_DESTROY;
typedef EVT_WDF_OBJECT_CONTEXT_CLEANUP EVT_WDF_IO_QUEUE_CONTEXT_CLEANUP_CALLBACK;
typedef EVT_WDF_OBJECT_CONTEXT_DESTROY EVT_WDF_IO_QUEUE_CONTEXT_DESTROY_CALLBACK;
typedef EVT_WDF_OBJECT_CONTEXT_CLEANUP EVT_WDF_FILE_CONTEXT_CLEANUP_CALLBACK;
typedef EVT_WDF_OBJECT_CONTEXT_DESTROY EVT_WDF_FILE_CONTEXT_DESTROY_CALLBACK;





WDF_EXTERN_C_END

#endif // _WDFROLETYPES_H_

