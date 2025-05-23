#pragma once

#ifndef MY_MACROS_H
#define MY_MACROS_H

#include <cassert>

#define FALSE_IF_FAILED(Call) Result = Call; if (!Result) return false;
#define HFALSE_IF_FAILED(Call) hResult = Call; if (FAILED(hResult)) return false;
#define ASSERT_NOT_FAILED(Call) hResult = Call; assert(FAILED(hResult) == false);

#define NAME_D3D_RESOURCE(D3DResource, Name) D3DResource->SetPrivateData(WKPDID_D3DDebugObjectName, (UINT)strlen(Name), Name);

#endif
