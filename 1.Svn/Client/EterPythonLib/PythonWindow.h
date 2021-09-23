//Find
			void SetNumber(const char * c_szNumber);

///Add
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
			const std::vector<CGraphicImageInstance*>& GetImageVector() const { return m_ImageInstanceVector; };
#endif

//Find
			void ResetFrame();

///Add
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
			const std::vector<CGraphicExpandedImageInstance*>& GetImageVector() const { return m_ImageVector; };
#endif