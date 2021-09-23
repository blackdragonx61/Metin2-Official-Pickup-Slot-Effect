//Find
		bool	AddToCharacter(LPCHARACTER ch, TItemPos Cell);

///Change
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
		bool	AddToCharacter(LPCHARACTER ch, TItemPos Cell, bool bHighlight = true);
#else
		bool	AddToCharacter(LPCHARACTER ch, TItemPos Cell);
#endif