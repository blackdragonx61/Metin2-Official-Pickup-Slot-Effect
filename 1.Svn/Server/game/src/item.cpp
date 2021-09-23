//Find
bool CItem::AddToCharacter(LPCHARACTER ch, TItemPos Cell)

///Change
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
bool CItem::AddToCharacter(LPCHARACTER ch, TItemPos Cell, bool bHighlight)
#else
bool CItem::AddToCharacter(LPCHARACTER ch, TItemPos Cell)
#endif

//Find
	ch->SetItem(TItemPos(window_type, pos), this);

///Change
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
	ch->SetItem(TItemPos(window_type, pos), this, bHighlight);
#else
	ch->SetItem(TItemPos(window_type, pos), this);
#endif