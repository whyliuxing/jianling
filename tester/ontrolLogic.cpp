// ontrolLogic.cpp: implementation of the ControlLogic class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ontrolLogic.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void ControLogic::Update(pfn_FUNC pfn)
{
    printf("��·��...");
    pfn();
}