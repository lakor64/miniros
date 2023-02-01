@ fastcall WdEnterMonitoredSection(ptr)
@ fastcall WdExitMonitoredSection(ptr)
@ fastcall WdResetDeferredWatch(ptr)
@ fastcall WdResumeDeferredWatch(ptr ptr)
@ fastcall WdSuspendDeferredWatch(ptr)
@ stdcall WdAllocateDeferredWatchdog(ptr ptr long)
@ stdcall WdAllocateWatchdog(ptr ptr long)
@ stdcall WdAttachContext(ptr ptr)
@ stdcall WdCompleteEvent(ptr ptr)
@ stdcall WdDereferenceObject(ptr)
@ stdcall WdDetachContext(ptr)
@ stdcall WdFreeDeferredWatchdog(ptr)
@ stdcall WdFreeWatchdog(ptr)
@ stdcall WdGetDeviceObject(ptr)
@ stdcall WdGetLastEvent(ptr)
@ stdcall WdGetLowestDeviceObject(ptr)
@ stdcall WdMadeAnyProgress(ptr)
@ stdcall WdReferenceObject(ptr)
@ stdcall WdResetWatch(ptr)
@ stdcall WdResumeWatch(ptr ptr)
@ stdcall WdStartDeferredWatch(ptr ptr long)
@ stdcall WdStartWatch(ptr double ptr)
@ stdcall WdStopDeferredWatch(ptr)
@ stdcall WdStopWatch(ptr long)
@ stdcall WdSuspendWatch(ptr)
@ stub WdDbgCreateSnapshot
@ stub WdDbgDestroySnapshot
@ stub WdDbgReportCancel
@ stub WdDbgReportComplete
@ stub WdDbgReportCreate
@ stub WdDbgReportQueryInfo
@ stub WdDbgReportRecreate
@ stub WdDbgReportSecondaryData
@ stub WdDiagGetEtwHandle
@ stub WdDiagInit
@ stub WdDiagIsTracingEnabled
@ stub WdDiagNotifyUser
@ stub WdDiagShutdown
@ stub WdInitLogging
@ stub WdLogEvent5
@ stub WdLogGetRecentEvents
@ stub WdpInterfaceReferenceNop
@ stub WdQueryDebugFlag
@ stub DMgrIsSetupRunning
@ stub DMgrReleaseDisplayOwnership
@ stub DMgrAcquireDisplayOwnership
@ stub DMgrGetDisplayOwnership
@ stub DMgrGetSmbiosInfo
@ stub DMgrAcquireGdiViewId
@ stub DMgrReleaseGdiViewId
@ stub DMgrWriteDeviceCountToRegistry
@ stub SMgrRegisterSessionStartCallout
@ stub SMgrUnregisterSessionStartCallout
@ stub SMgrGdiCallout
@ stub GTF_FloatToInteger
@ stub GTF_FloatToRation
@ stub GTF_UsingVerticalRefreshFrequency
