/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

_WdfVersionBuild_

Module Name:

    WdfCommonBuffer.h

Abstract:

    WDF CommonBuffer support

Environment:

    Kernel mode only.

Notes:

Revision History:

--*/

//
// NOTE: This header is generated by stubwork.  Please make any
//       modifications to the corresponding template files
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _WDFCOMMONBUFFER_H_
#define _WDFCOMMONBUFFER_H_

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



#if (NTDDI_VERSION >= NTDDI_WIN2K)



typedef struct _WDF_COMMON_BUFFER_CONFIG {
    //
    // Size of this structure in bytes
    //
    ULONG   Size;

    //
    // Alignment requirement of the buffer address
    //
    ULONG   AlignmentRequirement;

} WDF_COMMON_BUFFER_CONFIG, *PWDF_COMMON_BUFFER_CONFIG;

FORCEINLINE
VOID
WDF_COMMON_BUFFER_CONFIG_INIT(
    _Out_ PWDF_COMMON_BUFFER_CONFIG Config,
    _In_  ULONG  AlignmentRequirement
    )
{
    RtlZeroMemory(Config, sizeof(WDF_COMMON_BUFFER_CONFIG));

    Config->Size = sizeof(WDF_COMMON_BUFFER_CONFIG);
    Config->AlignmentRequirement = AlignmentRequirement;
}

//
// WDF Function: WdfCommonBufferCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(STDCALL *PFN_WDFCOMMONBUFFERCREATE)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDMAENABLER DmaEnabler,
    _In_
    _When_(Length == 0, __drv_reportError(Length cannot be zero))
    size_t Length,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _Out_
    WDFCOMMONBUFFER* CommonBuffer
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
WdfCommonBufferCreate(
    _In_
    WDFDMAENABLER DmaEnabler,
    _In_
    _When_(Length == 0, __drv_reportError(Length cannot be zero))
    size_t Length,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _Out_
    WDFCOMMONBUFFER* CommonBuffer
    )
{
    return ((PFN_WDFCOMMONBUFFERCREATE) WdfFunctions[WdfCommonBufferCreateTableIndex])(WdfDriverGlobals, DmaEnabler, Length, Attributes, CommonBuffer);
}

//
// WDF Function: WdfCommonBufferCreateWithConfig
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(STDCALL *PFN_WDFCOMMONBUFFERCREATEWITHCONFIG)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDMAENABLER DmaEnabler,
    _In_
    _When_(Length == 0, __drv_reportError(Length cannot be zero))
    size_t Length,
    _In_
    PWDF_COMMON_BUFFER_CONFIG Config,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _Out_
    WDFCOMMONBUFFER* CommonBuffer
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
WdfCommonBufferCreateWithConfig(
    _In_
    WDFDMAENABLER DmaEnabler,
    _In_
    _When_(Length == 0, __drv_reportError(Length cannot be zero))
    size_t Length,
    _In_
    PWDF_COMMON_BUFFER_CONFIG Config,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _Out_
    WDFCOMMONBUFFER* CommonBuffer
    )
{
    return ((PFN_WDFCOMMONBUFFERCREATEWITHCONFIG) WdfFunctions[WdfCommonBufferCreateWithConfigTableIndex])(WdfDriverGlobals, DmaEnabler, Length, Config, Attributes, CommonBuffer);
}

//
// WDF Function: WdfCommonBufferGetAlignedVirtualAddress
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
PVOID
(STDCALL *PFN_WDFCOMMONBUFFERGETALIGNEDVIRTUALADDRESS)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCOMMONBUFFER CommonBuffer
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
PVOID
WdfCommonBufferGetAlignedVirtualAddress(
    _In_
    WDFCOMMONBUFFER CommonBuffer
    )
{
    return ((PFN_WDFCOMMONBUFFERGETALIGNEDVIRTUALADDRESS) WdfFunctions[WdfCommonBufferGetAlignedVirtualAddressTableIndex])(WdfDriverGlobals, CommonBuffer);
}

//
// WDF Function: WdfCommonBufferGetAlignedLogicalAddress
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
PHYSICAL_ADDRESS
(STDCALL *PFN_WDFCOMMONBUFFERGETALIGNEDLOGICALADDRESS)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCOMMONBUFFER CommonBuffer
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
PHYSICAL_ADDRESS
WdfCommonBufferGetAlignedLogicalAddress(
    _In_
    WDFCOMMONBUFFER CommonBuffer
    )
{
    return ((PFN_WDFCOMMONBUFFERGETALIGNEDLOGICALADDRESS) WdfFunctions[WdfCommonBufferGetAlignedLogicalAddressTableIndex])(WdfDriverGlobals, CommonBuffer);
}

//
// WDF Function: WdfCommonBufferGetLength
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
size_t
(STDCALL *PFN_WDFCOMMONBUFFERGETLENGTH)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCOMMONBUFFER CommonBuffer
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
size_t
WdfCommonBufferGetLength(
    _In_
    WDFCOMMONBUFFER CommonBuffer
    )
{
    return ((PFN_WDFCOMMONBUFFERGETLENGTH) WdfFunctions[WdfCommonBufferGetLengthTableIndex])(WdfDriverGlobals, CommonBuffer);
}



#endif // (NTDDI_VERSION >= NTDDI_WIN2K)


WDF_EXTERN_C_END

#endif // _WDFCOMMONBUFFER_H_

