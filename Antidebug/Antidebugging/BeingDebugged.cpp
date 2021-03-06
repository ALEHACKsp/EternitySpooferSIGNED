#include "pch.h"
#include "BeingDebugged.h"


BOOL
IsDebuggerPresentPEB(
	VOID
)
/*++

Routine Description:

	Checks if the BeingDebugged flag is set in the Process Environment Block (PEB).
	This is effectively the same code that IsDebuggerPresent() executes internally.
	The PEB pointer is fetched from DWORD FS:[0x30] on x86_32 and QWORD GS:[0x60] on x86_64.

Arguments:

	None

Return Value:

	TRUE - if debugger was detected
	FALSE - otherwise
--*/
{

	PPEB pPeb = (PPEB)__readgsqword(0x60);




	return pPeb->BeingDebugged == 1;
}
