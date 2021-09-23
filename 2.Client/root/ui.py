#Find
	def DeactivateSlot(self, slotNumber):
		wndMgr.DeactivateSlot(self.hWnd, slotNumber)

#Add
	if app.BL_ENABLE_PICKUP_ITEM_EFFECT:
		def SetSlotDiffuseColor(self, slotindex, colortype):
			wndMgr.SetSlotDiffuseColor(self.hWnd, slotindex, colortype)

		def SetSlotFlashEffect(self, slotindex, active):
			wndMgr.SetSlotFlashEffect(self.hWnd, slotindex, active)