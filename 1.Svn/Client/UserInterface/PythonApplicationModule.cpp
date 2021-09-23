///Add
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
	PyModule_AddIntConstant(poModule, "BL_ENABLE_PICKUP_ITEM_EFFECT", true);
#else
	PyModule_AddIntConstant(poModule, "BL_ENABLE_PICKUP_ITEM_EFFECT", false);
#endif