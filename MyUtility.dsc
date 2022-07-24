[Defines]
	PLATFORM_NAME = MyUtility
	PLATFORM_GUID = c9ba9d19-f888-4406-a8d4-e54a1d7e1e39
	PLATFORM_VERSION = 1.0
	DSC_SPECIFICATION = 0x00010005
	SUPPORTED_ARCHITECTURES = X64
	BUILD_TARGETS = DEBUG|RELEASE

[LibraryClasses]
	UefiLib|MdePkg/Library/UefiLib/UefiLib.inf
	UefiMemoryLib|MdePkg/Library/UefiMemoryLib/UefiMemoryLib.inf
	UefiApplicationEntryPoint|MdePkg/Library/UefiApplicationEntryPoint/UefiApplicationEntryPoint.inf
	PrintLib|MdePkg/Library/BasePrintLib/BasePrintLib.inf
	PcdLib|MdePkg/Library/BasePcdLibNull/BasePcdLibNull.inf
	MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf
	DebugLib|MdePkg/Library/UefiDebugLibConOut/UefiDebugLibConOut.inf
	BaseMemoryLib|MdePkg/Library/BaseMemoryLib/BaseMemoryLib.inf
	BaseLib|MdePkg/Library/BaseLib/BaseLib.inf
	UefiBootServicesTableLib|MdePkg/Library/UefiBootServicesTableLib/UefiBootServicesTableLib.inf
	DevicePathLib|MdePkg/Library/UefiDevicePathLib/UefiDevicePathLib.inf
	UefiRuntimeServicesTableLib|MdePkg/Library/UefiRuntimeServicesTableLib/UefiRuntimeServicesTableLib.inf
	RegisterFilterLib|MdePkg/Library/RegisterFilterLibNull/RegisterFilterLibNull.inf
	DebugPrintErrorLevelLib|MdePkg/Library/BaseDebugPrintErrorLevelLib/BaseDebugPrintErrorLevelLib.inf
	IoLib|MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsic.inf
	cjsonlib|MyACPI_V3/cJSON/cjson.inf
	LibC|StdLib/LibC/LibC.inf
	LibStdio|StdLib/LibC/Stdio/Stdio.inf

	PciExpressLib|MdePkg/Library/BasePciExpressLib/BasePciExpressLib.inf

	# From Stdlib.inc Start
	ShellLib|ShellPkg/Library/UefiShellLib/UefiShellLib.inf
	#ShellLib|ShellPkg/Library/UefiShellLib/UefiShellLib.inf
  	FileHandleLib|MdePkg/Library/UefiFileHandleLib/UefiFileHandleLib.inf
  	SortLib|MdeModulePkg/Library/UefiSortLib/UefiSortLib.inf
  	ShellCEntryLib|ShellPkg/Library/UefiShellCEntryLib/UefiShellCEntryLib.inf

  	#
  	# C Standard Libraries
  	#
  	LibC|StdLib/LibC/LibC.inf
  	LibCType|StdLib/LibC/Ctype/Ctype.inf
  	LibLocale|StdLib/LibC/Locale/Locale.inf
  	LibMath|StdLib/LibC/Math/Math.inf
  	LibSignal|StdLib/LibC/Signal/Signal.inf
  	LibStdio|StdLib/LibC/Stdio/Stdio.inf
  	LibStdLib|StdLib/LibC/StdLib/StdLib.inf
  	LibString|StdLib/LibC/String/String.inf
  	LibTime|StdLib/LibC/Time/Time.inf
  	LibUefi|StdLib/LibC/Uefi/Uefi.inf
  	LibWchar|StdLib/LibC/Wchar/Wchar.inf

	# Common Utilities for Networking Libraries
  	LibNetUtil|StdLib/LibC/NetUtil/NetUtil.inf

	# Additional libraries for POSIX functionality.
  	LibPosix|StdLib/PosixLib/PosixLib.inf   # Combines LibErr, LibGen, LibGlob, LibStringlist, GetPass into one library

  	LibErr|StdLib/PosixLib/Err/LibErr.inf
  	LibGen|StdLib/PosixLib/Gen/LibGen.inf
  	LibGlob|StdLib/PosixLib/Glob/LibGlob.inf
  	LibStringlist|StdLib/PosixLib/Stringlist/LibStringlist.inf
  	LibIIO|StdLib/LibC/Uefi/InteractiveIO/IIO.inf

	# Additional, non-standard, libraries
  	LibContainer|StdLib/LibC/Containers/ContainerLib.inf

	# Libraries for device abstractions within the Standard C Library
	# Applications should not directly access any functions defined in these libraries.
  	LibGdtoa|StdLib/LibC/gdtoa/gdtoa.inf
  	DevConsole|StdLib/LibC/Uefi/Devices/daConsole.inf
  	DevShell|StdLib/LibC/Uefi/Devices/daShell.inf       # DEPRECATED!  Please use DevMedia for new code.
  	DevMedia|StdLib/LibC/Uefi/Devices/daShell.inf
  	DevUtility|StdLib/LibC/Uefi/Devices/daUtility.inf

  	LuaLib|AppPkg/Applications/Lua/LuaLib.inf           # Lua language library
  	# From Stdlib.inc end

	HiiLib|MdeModulePkg/Library/UefiHiiLib/UefiHiiLib.inf
	UefiHiiServicesLib|MdeModulePkg/Library/UefiHiiServicesLib/UefiHiiServicesLib.inf


[Components]
	MyUtility/MyUtility.inf