#Find
		if player.DRAGON_SOUL_INVENTORY == inven_type:
			if app.ENABLE_DRAGON_SOUL_SYSTEM:
				self.wndDragonSoul.HighlightSlot(inven_pos)

#Add
		elif player.INVENTORY == inven_type:
			if app.BL_ENABLE_PICKUP_ITEM_EFFECT:
				self.wndInventory.HighlightSlot(inven_pos)
