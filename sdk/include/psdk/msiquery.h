/*
 * Copyright (C) 2002,2003 Mike McCormack
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __WINE_MSIQUERY_H
#define __WINE_MSIQUERY_H

#include <msi.h>

typedef enum tagMSICONDITION
{
    MSICONDITION_FALSE = 0,
    MSICONDITION_TRUE  = 1,
    MSICONDITION_NONE  = 2,
    MSICONDITION_ERROR = 3,
} MSICONDITION;

#define MSI_NULL_INTEGER 0x80000000

typedef enum tagMSICOLINFO
{
    MSICOLINFO_NAMES = 0,
    MSICOLINFO_TYPES = 1
} MSICOLINFO;

typedef enum tagMSICOSTTREE
{
    MSICOSTTREE_SELFONLY = 0,
    MSICOSTTREE_CHILDREN = 1,
    MSICOSTTREE_PARENTS  = 2,
    MSICOSTTREE_PRODUCT  = 3,
} MSICOSTTREE;

typedef enum tagMSIMODIFY
{
    MSIMODIFY_SEEK = -1,
    MSIMODIFY_REFRESH = 0,
    MSIMODIFY_INSERT = 1,
    MSIMODIFY_UPDATE = 2,
    MSIMODIFY_ASSIGN = 3,
    MSIMODIFY_REPLACE = 4,
    MSIMODIFY_MERGE = 5,
    MSIMODIFY_DELETE = 6,
    MSIMODIFY_INSERT_TEMPORARY = 7,
    MSIMODIFY_VALIDATE = 8,
    MSIMODIFY_VALIDATE_NEW = 9,
    MSIMODIFY_VALIDATE_FIELD = 10,
    MSIMODIFY_VALIDATE_DELETE = 11
} MSIMODIFY;

#ifndef WINE_NO_UNICODE_MACROS
#define MSIDBOPEN_READONLY (LPCTSTR)0
#define MSIDBOPEN_TRANSACT (LPCTSTR)1
#define MSIDBOPEN_DIRECT   (LPCTSTR)2
#define MSIDBOPEN_CREATE   (LPCTSTR)3
#define MSIDBOPEN_CREATEDIRECT (LPCTSTR)4
#else
#define MSIDBOPEN_READONLY (LPCWSTR)0
#define MSIDBOPEN_TRANSACT (LPCWSTR)1
#define MSIDBOPEN_DIRECT   (LPCWSTR)2
#define MSIDBOPEN_CREATE   (LPCWSTR)3
#define MSIDBOPEN_CREATEDIRECT (LPCWSTR)4
#endif

#define MSIDBOPEN_PATCHFILE 32 / sizeof(*MSIDBOPEN_READONLY)

typedef enum tagMSIRUNMODE
{
    MSIRUNMODE_ADMIN = 0,
    MSIRUNMODE_ADVERTISE = 1,
    MSIRUNMODE_MAINTENANCE = 2,
    MSIRUNMODE_ROLLBACKENABLED = 3,
    MSIRUNMODE_LOGENABLED = 4,
    MSIRUNMODE_OPERATIONS = 5,
    MSIRUNMODE_REBOOTATEND = 6,
    MSIRUNMODE_REBOOTNOW = 7,
    MSIRUNMODE_CABINET = 8,
    MSIRUNMODE_SOURCESHORTNAMES = 9,
    MSIRUNMODE_TARGETSHORTNAMES = 10,
    MSIRUNMODE_RESERVED11 = 11,
    MSIRUNMODE_WINDOWS9X = 12,
    MSIRUNMODE_ZAWENABLED = 13,
    MSIRUNMODE_RESERVED14 = 14,
    MSIRUNMODE_RESERVED15 = 15,
    MSIRUNMODE_SCHEDULED = 16,
    MSIRUNMODE_ROLLBACK = 17,
    MSIRUNMODE_COMMIT = 18
} MSIRUNMODE;

typedef enum tagMSIDBERROR
{
    MSIDBERROR_INVALIDARG = -3,
    MSIDBERROR_MOREDATA = -2,
    MSIDBERROR_FUNCTIONERROR = -1,
    MSIDBERROR_NOERROR = 0,
    MSIDBERROR_DUPLICATEKEY = 1,
    MSIDBERROR_REQUIRED = 2,
    MSIDBERROR_BADLINK = 3,
    MSIDBERROR_OVERFLOW = 4,
    MSIDBERROR_UNDERFLOW = 5,
    MSIDBERROR_NOTINSET = 6,
    MSIDBERROR_BADVERSION = 7,
    MSIDBERROR_BADCASE = 8,
    MSIDBERROR_BADGUID = 9,
    MSIDBERROR_BADWILDCARD = 10,
    MSIDBERROR_BADIDENTIFIER = 11,
    MSIDBERROR_BADLANGUAGE = 12,
    MSIDBERROR_BADFILENAME = 13,
    MSIDBERROR_BADPATH = 14,
    MSIDBERROR_BADCONDITION = 15,
    MSIDBERROR_BADFORMATTED = 16,
    MSIDBERROR_BADTEMPLATE = 17,
    MSIDBERROR_BADDEFAULTDIR = 18,
    MSIDBERROR_BADREGPATH = 19,
    MSIDBERROR_BADCUSTOMSOURCE = 20,
    MSIDBERROR_BADPROPERTY = 21,
    MSIDBERROR_MISSINGDATA = 22,
    MSIDBERROR_BADCATEGORY = 23,
    MSIDBERROR_BADKEYTABLE = 24,
    MSIDBERROR_BADMAXMINVALUES = 25,
    MSIDBERROR_BADCABINET = 26,
    MSIDBERROR_BADSHORTCUT= 27,
    MSIDBERROR_STRINGOVERFLOW = 28,
    MSIDBERROR_BADLOCALIZEATTRIB = 29
} MSIDBERROR;

typedef enum tagMSIDBSTATE
{
    MSIDBSTATE_ERROR = -1,
    MSIDBSTATE_READ = 0,
    MSIDBSTATE_WRITE = 1
} MSIDBSTATE;

typedef enum tagMSITRANSFORM_ERROR
{
    MSITRANSFORM_ERROR_ADDEXISTINGROW   =  0x00000001,
    MSITRANSFORM_ERROR_DELMISSINGROW    =  0x00000002,
    MSITRANSFORM_ERROR_ADDEXISTINGTABLE =  0x00000004,
    MSITRANSFORM_ERROR_DELMISSINGTABLE  =  0x00000008,
    MSITRANSFORM_ERROR_UPDATEMISSINGROW =  0x00000010,
    MSITRANSFORM_ERROR_CHANGECODEPAGE   =  0x00000020,
    MSITRANSFORM_ERROR_VIEWTRANSFORM    =  0x00000100
} MSITRANSFORM_ERROR;

typedef enum tagMSITRANSFORM_VALIDATE
{
    MSITRANSFORM_VALIDATE_LANGUAGE                   = 0x00000001,
    MSITRANSFORM_VALIDATE_PRODUCT                    = 0x00000002,
    MSITRANSFORM_VALIDATE_PLATFORM                   = 0x00000004,
    MSITRANSFORM_VALIDATE_MAJORVERSION               = 0x00000008,
    MSITRANSFORM_VALIDATE_MINORVERSION               = 0x00000010,
    MSITRANSFORM_VALIDATE_UPDATEVERSION              = 0x00000020,
    MSITRANSFORM_VALIDATE_NEWLESSBASEVERSION         = 0x00000040,
    MSITRANSFORM_VALIDATE_NEWLESSEQUALBASEVERSION    = 0x00000080,
    MSITRANSFORM_VALIDATE_NEWEQUALBASEVERSION        = 0x00000100,
    MSITRANSFORM_VALIDATE_NEWGREATEREQUALBASEVERSION = 0x00000200,
    MSITRANSFORM_VALIDATE_NEWGREATERBASEVERSION      = 0x00000400,
    MSITRANSFORM_VALIDATE_UPGRADECODE                = 0x00000800
} MSITRANSFORM_VALIDATE;

#ifdef __cplusplus
extern "C" {
#endif

/* view manipulation */
UINT WINAPI MsiViewFetch(MSIHANDLE,MSIHANDLE*);
UINT WINAPI MsiViewExecute(MSIHANDLE,MSIHANDLE);
UINT WINAPI MsiViewClose(MSIHANDLE);
UINT WINAPI MsiDatabaseOpenViewA(MSIHANDLE,LPCSTR,MSIHANDLE*);
UINT WINAPI MsiDatabaseOpenViewW(MSIHANDLE,LPCWSTR,MSIHANDLE*);
#define     MsiDatabaseOpenView WINELIB_NAME_AW(MsiDatabaseOpenView)
MSIDBERROR WINAPI MsiViewGetErrorA(MSIHANDLE,LPSTR,LPDWORD);
MSIDBERROR WINAPI MsiViewGetErrorW(MSIHANDLE,LPWSTR,LPDWORD);
#define     MsiViewGetError WINELIB_NAME_AW(MsiViewGetError)

MSIDBSTATE WINAPI MsiGetDatabaseState(MSIHANDLE);

/* record manipulation */
MSIHANDLE WINAPI MsiCreateRecord(UINT);
UINT WINAPI MsiRecordClearData(MSIHANDLE);
UINT WINAPI MsiRecordSetInteger(MSIHANDLE,UINT,int);
UINT WINAPI MsiRecordSetStringA(MSIHANDLE,UINT,LPCSTR);
UINT WINAPI MsiRecordSetStringW(MSIHANDLE,UINT,LPCWSTR);
#define     MsiRecordSetString WINELIB_NAME_AW(MsiRecordSetString)
UINT WINAPI MsiRecordGetStringA(MSIHANDLE,UINT,LPSTR,LPDWORD);
UINT WINAPI MsiRecordGetStringW(MSIHANDLE,UINT,LPWSTR,LPDWORD);
#define     MsiRecordGetString WINELIB_NAME_AW(MsiRecordGetString)
UINT WINAPI MsiRecordGetFieldCount(MSIHANDLE);
int WINAPI MsiRecordGetInteger(MSIHANDLE,UINT);
UINT WINAPI MsiRecordDataSize(MSIHANDLE,UINT);
BOOL WINAPI MsiRecordIsNull(MSIHANDLE,UINT);
UINT WINAPI MsiFormatRecordA(MSIHANDLE,MSIHANDLE,LPSTR,LPDWORD);
UINT WINAPI MsiFormatRecordW(MSIHANDLE,MSIHANDLE,LPWSTR,LPDWORD);
#define     MsiFormatRecord WINELIB_NAME_AW(MsiFormatRecord)
UINT WINAPI MsiRecordSetStreamA(MSIHANDLE,UINT,LPCSTR);
UINT WINAPI MsiRecordSetStreamW(MSIHANDLE,UINT,LPCWSTR);
#define     MsiRecordSetStream WINELIB_NAME_AW(MsiRecordSetStream)
UINT WINAPI MsiRecordReadStream(MSIHANDLE,UINT,char*,LPDWORD);

UINT WINAPI MsiDatabaseGetPrimaryKeysA(MSIHANDLE,LPCSTR,MSIHANDLE*);
UINT WINAPI MsiDatabaseGetPrimaryKeysW(MSIHANDLE,LPCWSTR,MSIHANDLE*);
#define     MsiDatabaseGetPrimaryKeys WINELIB_NAME_AW(MsiDatabaseGetPrimaryKeys)

/* installing */
UINT WINAPI MsiDoActionA(MSIHANDLE,LPCSTR );
UINT WINAPI MsiDoActionW(MSIHANDLE,LPCWSTR );
#define     MsiDoAction WINELIB_NAME_AW(MsiDoAction)

/* database transforms */
UINT WINAPI MsiDatabaseApplyTransformA(MSIHANDLE,LPCSTR,int);
UINT WINAPI MsiDatabaseApplyTransformW(MSIHANDLE,LPCWSTR,int);
#define     MsiDatabaseApplyTransform WINELIB_NAME_AW(MsiDatabaseApplyTransform)
UINT WINAPI MsiDatabaseGenerateTransformA(MSIHANDLE,MSIHANDLE,LPCSTR,int,int);
UINT WINAPI MsiDatabaseGenerateTransformW(MSIHANDLE,MSIHANDLE,LPCWSTR,int,int);
#define     MsiDatabaseGenerateTransform WINELIB_NAME_AW(MsiDatabaseGenerateTransform)

UINT WINAPI MsiDatabaseCommit(MSIHANDLE);

/* install state */
UINT WINAPI MsiGetFeatureStateA(MSIHANDLE,LPCSTR,INSTALLSTATE*,INSTALLSTATE*);
UINT WINAPI MsiGetFeatureStateW(MSIHANDLE,LPCWSTR,INSTALLSTATE*,INSTALLSTATE*);
#define     MsiGetFeatureState WINELIB_NAME_AW(MsiGetFeatureState)
UINT WINAPI MsiGetFeatureValidStatesA(MSIHANDLE,LPCSTR,LPDWORD);
UINT WINAPI MsiGetFeatureValidStatesW(MSIHANDLE,LPCWSTR,LPDWORD);
#define     MsiGetFeatureValidStates WINELIB_NAME_AW(MsiGetFeatureValidStates)
UINT WINAPI MsiSetComponentStateA(MSIHANDLE,LPCSTR,INSTALLSTATE);
UINT WINAPI MsiSetComponentStateW(MSIHANDLE,LPCWSTR,INSTALLSTATE);
#define     MsiSetComponentState WINELIB_NAME_AW(MsiSetComponentState)
UINT WINAPI MsiGetComponentStateA(MSIHANDLE,LPCSTR,INSTALLSTATE*,INSTALLSTATE*);
UINT WINAPI MsiGetComponentStateW(MSIHANDLE,LPCWSTR,INSTALLSTATE*,INSTALLSTATE*);
#define     MsiGetComponentState WINELIB_NAME_AW(MsiGetComponentState)

MSICONDITION WINAPI MsiEvaluateConditionA(MSIHANDLE,LPCSTR);
MSICONDITION WINAPI MsiEvaluateConditionW(MSIHANDLE,LPCWSTR);
#define     MsiEvaluateCondition WINELIB_NAME_AW(MsiEvaluateCondition)

/* property functions */
UINT WINAPI MsiGetPropertyA(MSIHANDLE, LPCSTR, LPSTR, LPDWORD);
UINT WINAPI MsiGetPropertyW(MSIHANDLE, LPCWSTR, LPWSTR, LPDWORD);
#define     MsiGetProperty WINELIB_NAME_AW(MsiGetProperty)

UINT WINAPI MsiSetPropertyA(MSIHANDLE, LPCSTR, LPCSTR);
UINT WINAPI MsiSetPropertyW(MSIHANDLE, LPCWSTR, LPCWSTR);
#define     MsiSetProperty WINELIB_NAME_AW(MsiSetProperty)

UINT WINAPI MsiGetTargetPathA(MSIHANDLE,LPCSTR,LPSTR,LPDWORD);
UINT WINAPI MsiGetTargetPathW(MSIHANDLE,LPCWSTR,LPWSTR,LPDWORD);
#define     MsiGetTargetPath WINELIB_NAME_AW(MsiGetTargetPath)

UINT WINAPI MsiSetTargetPathA(MSIHANDLE, LPCSTR, LPCSTR);
UINT WINAPI MsiSetTargetPathW(MSIHANDLE, LPCWSTR, LPCWSTR);
#define     MsiSetTargetPath WINELIB_NAME_AW(MsiSetTargetPath)

UINT WINAPI MsiGetSourcePathA(MSIHANDLE,LPCSTR,LPSTR,LPDWORD);
UINT WINAPI MsiGetSourcePathW(MSIHANDLE,LPCWSTR,LPWSTR,LPDWORD);
#define     MsiGetSourcePath WINELIB_NAME_AW(MsiGetSourcePath)

MSIHANDLE WINAPI MsiGetActiveDatabase(MSIHANDLE);

UINT WINAPI MsiViewGetColumnInfo(MSIHANDLE, MSICOLINFO, MSIHANDLE*);
INT WINAPI MsiProcessMessage(MSIHANDLE, INSTALLMESSAGE, MSIHANDLE);

UINT WINAPI MsiSetFeatureAttributesA(MSIHANDLE, LPCSTR, DWORD);
UINT WINAPI MsiSetFeatureAttributesW(MSIHANDLE, LPCWSTR, DWORD);
#define     MsiSetFeatureAttributes WINELIB_NAME_AW(MsiSetFeatureAttributes)

UINT WINAPI MsiSetFeatureStateA(MSIHANDLE, LPCSTR, INSTALLSTATE);
UINT WINAPI MsiSetFeatureStateW(MSIHANDLE, LPCWSTR, INSTALLSTATE);
#define     MsiSetFeatureState WINELIB_NAME_AW(MsiSetFeatureState)

UINT WINAPI MsiPreviewDialogA(MSIHANDLE, LPCSTR);
UINT WINAPI MsiPreviewDialogW(MSIHANDLE, LPCWSTR);
#define     MsiPreviewDialog WINELIB_NAME_AW(MsiPreviewDialog)

UINT WINAPI MsiPreviewBillboardA(MSIHANDLE, LPCSTR, LPCSTR);
UINT WINAPI MsiPreviewBillboardW(MSIHANDLE, LPCWSTR, LPCWSTR);
#define     MsiPreviewBillboard WINELIB_NAME_AW(MsiPreviewBillboard)

UINT WINAPI MsiCreateTransformSummaryInfoA(MSIHANDLE, MSIHANDLE, LPCSTR, int, int);
UINT WINAPI MsiCreateTransformSummaryInfoW(MSIHANDLE, MSIHANDLE, LPCWSTR, int, int);
#define     MsiCreateTransformSummaryInfo WINELIB_NAME_AW(MsiCreateTransformSummaryInfo)

UINT WINAPI MsiGetSummaryInformationA(MSIHANDLE, LPCSTR, UINT, MSIHANDLE *);
UINT WINAPI MsiGetSummaryInformationW(MSIHANDLE, LPCWSTR, UINT, MSIHANDLE *);
#define     MsiGetSummaryInformation WINELIB_NAME_AW(MsiGetSummaryInformation)

UINT WINAPI MsiSummaryInfoGetPropertyA(MSIHANDLE,UINT,PUINT,LPINT,FILETIME*,LPSTR,LPDWORD);
UINT WINAPI MsiSummaryInfoGetPropertyW(MSIHANDLE,UINT,PUINT,LPINT,FILETIME*,LPWSTR,LPDWORD);
#define     MsiSummaryInfoGetProperty WINELIB_NAME_AW(MsiSummaryInfoGetProperty)

UINT WINAPI MsiSummaryInfoSetPropertyA(MSIHANDLE, UINT, UINT, INT, FILETIME*, LPCSTR);
UINT WINAPI MsiSummaryInfoSetPropertyW(MSIHANDLE, UINT, UINT, INT, FILETIME*, LPCWSTR);
#define     MsiSummaryInfoSetProperty WINELIB_NAME_AW(MsiSummaryInfoSetProperty)

UINT WINAPI MsiDatabaseExportA(MSIHANDLE, LPCSTR, LPCSTR, LPCSTR);
UINT WINAPI MsiDatabaseExportW(MSIHANDLE, LPCWSTR, LPCWSTR, LPCWSTR);
#define     MsiDatabaseExport WINELIB_NAME_AW(MsiDatabaseExport)

UINT WINAPI MsiDatabaseImportA(MSIHANDLE, LPCSTR, LPCSTR);
UINT WINAPI MsiDatabaseImportW(MSIHANDLE, LPCWSTR, LPCWSTR);
#define     MsiDatabaseImport WINELIB_NAME_AW(MsiDatabaseImport)

UINT WINAPI MsiOpenDatabaseW(LPCWSTR, LPCWSTR, MSIHANDLE*);
UINT WINAPI MsiOpenDatabaseA(LPCSTR, LPCSTR, MSIHANDLE*);
#define     MsiOpenDatabase WINELIB_NAME_AW(MsiOpenDatabase)

MSICONDITION WINAPI MsiDatabaseIsTablePersistentA(MSIHANDLE, LPCSTR);
MSICONDITION WINAPI MsiDatabaseIsTablePersistentW(MSIHANDLE, LPCWSTR);
#define     MsiDatabaseIsTablePersistent WINELIB_NAME_AW(MsiDatabaseIsTablePersistent)

UINT WINAPI MsiSequenceA(MSIHANDLE, LPCSTR, INT);
UINT WINAPI MsiSequenceW(MSIHANDLE, LPCWSTR, INT);
#define     MsiSequence WINELIB_NAME_AW(MsiSequence)

UINT WINAPI MsiSummaryInfoPersist(MSIHANDLE);
UINT WINAPI MsiSummaryInfoGetPropertyCount(MSIHANDLE,PUINT);

UINT WINAPI MsiEnableUIPreview(MSIHANDLE, MSIHANDLE*);
BOOL WINAPI MsiGetMode(MSIHANDLE, MSIRUNMODE);
UINT WINAPI MsiSetMode(MSIHANDLE, MSIRUNMODE, BOOL);

UINT WINAPI MsiViewModify(MSIHANDLE, MSIMODIFY, MSIHANDLE);

UINT WINAPI MsiGetFeatureCostA(MSIHANDLE, LPCSTR, MSICOSTTREE, INSTALLSTATE, LPINT);
UINT WINAPI MsiGetFeatureCostW(MSIHANDLE, LPCWSTR, MSICOSTTREE, INSTALLSTATE, LPINT);
#define     MsiGetFeatureCost WINELIB_NAME_AW(MsiGetFeatureCost)

LANGID WINAPI MsiGetLanguage(MSIHANDLE);

UINT WINAPI MsiSetInstallLevel(MSIHANDLE, int);

MSIHANDLE WINAPI MsiGetLastErrorRecord(void);

#ifdef __cplusplus
}
#endif

#endif /* __WINE_MSIQUERY_H */
