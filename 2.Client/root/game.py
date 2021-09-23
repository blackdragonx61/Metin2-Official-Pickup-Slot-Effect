#Add new funcs to end of file
	if app.BL_ENABLE_PICKUP_ITEM_EFFECT:
		def DeactivateSlot(self, slotindex, type):
			self.interface.DeactivateSlot(slotindex, type)
		
		def ActivateSlot(self, slotindex, type):
			self.interface.ActivateSlot(slotindex, type)