//Find
	pSlotWin->ActivateSlot(iSlotIndex);

///Change
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
	pSlotWin->ActivateNewSlot(iSlotIndex);
#else
	pSlotWin->ActivateSlot(iSlotIndex);
#endif

//Find
	pSlotWin->DeactivateSlot(iSlotIndex);

///Change
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
	pSlotWin->DeactivateNewSlot(iSlotIndex);
#else
	pSlotWin->DeactivateSlot(iSlotIndex);
#endif

//Find
void initwndMgr()

///Add Above
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
PyObject* wndMgrSetSlotDiffuseColor(PyObject* poSelf, PyObject* poArgs)
{
	UI::CWindow* pWin;
	if (!PyTuple_GetWindow(poArgs, 0, &pWin))
		return Py_BuildException();

	DWORD dwSlotIndex;
	if (!PyTuple_GetUnsignedLong(poArgs, 1, &dwSlotIndex))
		return Py_BuildException();

	BYTE blType;
	if (!PyTuple_GetByte(poArgs, 2, &blType))
		return Py_BuildException();

	if (!pWin->IsType(UI::CSlotWindow::Type()))
		return Py_BuildException();

	dynamic_cast<UI::CSlotWindow*>(pWin)->SetNewSlotDiffuseColor(dwSlotIndex, blType);

	return Py_BuildNone();
}

PyObject* wndMgrSetSlotFlashEffect(PyObject* poSelf, PyObject* poArgs)
{
	UI::CWindow* pWin;
	if (!PyTuple_GetWindow(poArgs, 0, &pWin))
		return Py_BuildException();

	DWORD dwSlotIndex;
	if (!PyTuple_GetUnsignedLong(poArgs, 1, &dwSlotIndex))
		return Py_BuildException();

	bool bActive;
	if (!PyTuple_GetBoolean(poArgs, 2, &bActive))
		return Py_BuildException();

	if (!pWin->IsType(UI::CSlotWindow::Type()))
		return Py_BuildException();

	dynamic_cast<UI::CSlotWindow*>(pWin)->SetNewSlotFlashEffect(dwSlotIndex, bActive);

	return Py_BuildNone();
}
#endif

//Find
		{ "SetSlotCount",				wndMgrSetSlotCount,					METH_VARARGS },

///Add
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
		{ "SetSlotDiffuseColor",		wndMgrSetSlotDiffuseColor,			METH_VARARGS },
		{ "SetSlotFlashEffect",			wndMgrSetSlotFlashEffect,			METH_VARARGS },
#endif

//Find
	PyModule_AddIntConstant(poModule, "RENDERING_MODE_MODULATE",		CGraphicExpandedImageInstance::RENDERING_MODE_MODULATE);

///Add
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_ORANGE", UI::ESlotColor::COLOR_TYPE_ORANGE);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_WHITE", UI::ESlotColor::COLOR_TYPE_WHITE);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_RED", UI::ESlotColor::COLOR_TYPE_RED);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_GREEN", UI::ESlotColor::COLOR_TYPE_GREEN);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_YELLOW", UI::ESlotColor::COLOR_TYPE_YELLOW);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_SKY", UI::ESlotColor::COLOR_TYPE_SKY);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_PINK", UI::ESlotColor::COLOR_TYPE_PINK);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_BLUE", UI::ESlotColor::COLOR_TYPE_BLUE);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_DARK_BLUE", UI::ESlotColor::COLOR_TYPE_DARK_BLUE);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_PURPLE", UI::ESlotColor::COLOR_TYPE_PURPLE);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_GRAY", UI::ESlotColor::COLOR_TYPE_GRAY);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_SILVER", UI::ESlotColor::COLOR_TYPE_SILVER);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_MAX", UI::ESlotColor::COLOR_TYPE_MAX);

	PyModule_AddIntConstant(poModule, "HILIGHTSLOT_ACCE", UI::ESlotHilight::HILIGHTSLOT_ACCE);
	PyModule_AddIntConstant(poModule, "HILIGHTSLOT_CHANGE_LOOK", UI::ESlotHilight::HILIGHTSLOT_CHANGE_LOOK);
	PyModule_AddIntConstant(poModule, "HILIGHTSLOT_AURA", UI::ESlotHilight::HILIGHTSLOT_AURA);
	PyModule_AddIntConstant(poModule, "HILIGHTSLOT_CUBE", UI::ESlotHilight::HILIGHTSLOT_CUBE);
	PyModule_AddIntConstant(poModule, "HILIGHTSLOT_MAX", UI::ESlotHilight::HILIGHTSLOT_MAX);
#endif