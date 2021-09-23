//Find
		void	SetItem(TItemPos Cell, LPITEM item);

///Change
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
		void	SetItem(TItemPos Cell, LPITEM item, bool bHighlight = true);
#else
		void	SetItem(TItemPos Cell, LPITEM item);
#endif