//Find
void CHARACTER::SetItem(TItemPos Cell, LPITEM pItem)

///Change
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
void CHARACTER::SetItem(TItemPos Cell, LPITEM pItem, bool bHighlight)
#else
void CHARACTER::SetItem(TItemPos Cell, LPITEM pItem)
#endif

//Find
			pack.highlight = (Cell.window_type == DRAGON_SOUL_INVENTORY);

///Change
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
			pack.highlight = bHighlight;
#else
			pack.highlight = (Cell.window_type == DRAGON_SOUL_INVENTORY);
#endif

//Find in void CHARACTER::SetWear(BYTE bCell, LPITEM item)
	SetItem(TItemPos (INVENTORY, INVENTORY_MAX_NUM + bCell), item);

///Change
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
	SetItem(TItemPos(INVENTORY, INVENTORY_MAX_NUM + bCell), item, false);
#else
	SetItem(TItemPos (INVENTORY, INVENTORY_MAX_NUM + bCell), item);
#endif

//Find in bool CHARACTER::MoveItem(TItemPos Cell, TItemPos DestCell, BYTE count)
			SetItem(DestCell, item);

///Change
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
			SetItem(DestCell, item, false);
#else
			SetItem(DestCell, item);
#endif

//Find in bool CHARACTER::MoveItem(TItemPos Cell, TItemPos DestCell, BYTE count)
			item2->AddToCharacter(this, DestCell);

///Change
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
			item2->AddToCharacter(this, DestCell, false);
#else
			item2->AddToCharacter(this, DestCell);
#endif

//Find in bool CHARACTER::SwapItem(BYTE bCell, BYTE bDestCell)
		if (item1->EquipTo(this, bEquipCell))
			item2->AddToCharacter(this, TItemPos(INVENTORY, bInvenCell));

///Change
		if (item1->EquipTo(this, bEquipCell))
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
			item2->AddToCharacter(this, TItemPos(INVENTORY, bInvenCell), false);
#else
			item2->AddToCharacter(this, TItemPos(INVENTORY, bInvenCell));
#endif

//Find in bool CHARACTER::SwapItem(BYTE bCell, BYTE bDestCell)
		item1->AddToCharacter(this, TItemPos(INVENTORY, bCell2));
		item2->AddToCharacter(this, TItemPos(INVENTORY, bCell1));

///Change
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
		item1->AddToCharacter(this, TItemPos(INVENTORY, bCell2), false);
		item2->AddToCharacter(this, TItemPos(INVENTORY, bCell1), false);
#else
		item1->AddToCharacter(this, TItemPos(INVENTORY, bCell2));
		item2->AddToCharacter(this, TItemPos(INVENTORY, bCell1));
#endif

//Find in bool CHARACTER::UnequipItem(LPITEM item)
		item->AddToCharacter(this, TItemPos(INVENTORY, pos));

///Change
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
		item->AddToCharacter(this, TItemPos(INVENTORY, pos), false);
#else
		item->AddToCharacter(this, TItemPos(INVENTORY, pos));
#endif