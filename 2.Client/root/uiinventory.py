#Add after imports
if app.BL_ENABLE_PICKUP_ITEM_EFFECT:
	def ReprGetItemIndex(window):
		return lambda pos : player.GetItemIndex(window, pos)

#Find
			self.equipmentTab.append(self.GetChild("Equipment_Tab_02"))

#Add
			if app.BL_ENABLE_PICKUP_ITEM_EFFECT:
				self.listHighlightedSlot = []

#Find in def RefreshBagSlotWindow(self):
		self.wndItem.RefreshSlot()

#Add Above
			if app.BL_ENABLE_PICKUP_ITEM_EFFECT:
				self.__HighlightSlot_Refresh()

#Find in def OverInItem(self, overSlotPos):
		overSlotPos = self.__InventoryLocalSlotPosToGlobalSlotPos(overSlotPos)
		self.wndItem.SetUsableItem(False)

#Add
		if app.BL_ENABLE_PICKUP_ITEM_EFFECT:
			self.DelHighlightSlot(overSlotPos)

#Find
	def OnMoveWindow(self, x, y):
		#		print("Inventory Global Pos : ", self.GetGlobalPosition())
		if self.wndBelt:
			#			print("Belt Global Pos : ", self.wndBelt.GetGlobalPosition())
			self.wndBelt.AdjustPositionAndSize()

#Add
	if app.BL_ENABLE_PICKUP_ITEM_EFFECT:
		def ActivateSlot(self, slotindex, type):
			if type == wndMgr.HILIGHTSLOT_MAX:
				return
					
		def DeactivateSlot(self, slotindex, type):
			if type == wndMgr.HILIGHTSLOT_MAX:
				return

		def __HighlightSlot_Refresh(self):
			for i in xrange(self.wndItem.GetSlotCount()):
				slotNumber = self.__InventoryLocalSlotPosToGlobalSlotPos(i)
				if slotNumber in self.listHighlightedSlot:
					self.wndItem.ActivateSlot(i)
					# self.wndItem.SetSlotDiffuseColor(i, wndMgr.COLOR_TYPE_YELLOW)
					# self.wndItem.SetSlotFlashEffect(i, True)

		def __HighlightSlot_Clear(self):
			for i in xrange(self.wndItem.GetSlotCount()):
				slotNumber = self.__InventoryLocalSlotPosToGlobalSlotPos(i)
				if slotNumber in self.listHighlightedSlot:
					self.wndItem.DeactivateSlot(i)
					self.listHighlightedSlot.remove(slotNumber)
		
		def HighlightSlot(self, slot):
			if slot>player.INVENTORY_PAGE_SIZE*player.INVENTORY_PAGE_COUNT:
				return
			
			if not slot in self.listHighlightedSlot:
				self.listHighlightedSlot.append (slot)

		def DelHighlightSlot(self, inventorylocalslot):
			if inventorylocalslot in self.listHighlightedSlot:
				if inventorylocalslot >= player.INVENTORY_PAGE_SIZE:
					self.wndItem.DeactivateSlot(inventorylocalslot - (self.inventoryPageIndex * player.INVENTORY_PAGE_SIZE) )
				else:
					self.wndItem.DeactivateSlot(inventorylocalslot)

				self.listHighlightedSlot.remove(inventorylocalslot)