//Find
	Slot.pFinishCoolTimeEffect = NULL;

///Add
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
	Slot.pNewSlotEffect.fill(nullptr);
	Slot.bFlashEffect = false;
#endif

//Find
void CSlotWindow::SetSlotCoolTime(DWORD dwIndex, float fCoolTime, float fElapsedTime)
{
	...
}

///Add
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
D3DXCOLOR CSlotWindow::GetNewSlotColor(const BYTE blType) const
{
	switch (blType)
	{
	case ESlotColor::COLOR_TYPE_ORANGE:
		return D3DXCOLOR(0xFFA500);
	case ESlotColor::COLOR_TYPE_WHITE:
		return D3DXCOLOR(0xFFFFFF);
	case ESlotColor::COLOR_TYPE_RED:
		return D3DXCOLOR(0xFF0000);
	case ESlotColor::COLOR_TYPE_GREEN:
		return D3DXCOLOR(0x008000);
	case ESlotColor::COLOR_TYPE_YELLOW:
		return D3DXCOLOR(0xFFFF00);
	case ESlotColor::COLOR_TYPE_SKY:
		return D3DXCOLOR(0x87CEFA);
	case ESlotColor::COLOR_TYPE_PINK:
		return D3DXCOLOR(0xFFC0CB);
	case ESlotColor::COLOR_TYPE_BLUE:
		return D3DXCOLOR(0x0000FF);
	case ESlotColor::COLOR_TYPE_DARK_BLUE:
		return D3DXCOLOR(0x00008B);
	case ESlotColor::COLOR_TYPE_PURPLE:
		return D3DXCOLOR(0x800080);
	case ESlotColor::COLOR_TYPE_GRAY:
		return D3DXCOLOR(0x800080);
	case ESlotColor::COLOR_TYPE_SILVER:
		return D3DXCOLOR(0xC0C0C0);
	}

	return D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
}

void CSlotWindow::SetNewSlotDiffuseColor(const DWORD dwIndex, const BYTE blType)
{
	TSlot* pSlot;
	if (!GetSlotPointer(dwIndex, &pSlot))
		return;

	const D3DXCOLOR color{ GetNewSlotColor(blType) };
	for (auto& NewSlotEffect : pSlot->pNewSlotEffect)
	{
		if (NewSlotEffect == nullptr)
			continue;

		const auto& vecImage = NewSlotEffect->GetImageVector();
		if (vecImage.empty())
			continue;

		for (CGraphicExpandedImageInstance* SlotImage : vecImage)
		{
			if (SlotImage == nullptr || SlotImage->IsEmpty())
				continue;

			SlotImage->SetDiffuseColor(color.r, color.g, color.b, color.a);
		}
	}
}

void CSlotWindow::ActivateNewSlot(const DWORD dwSlotIndex)
{
	TSlot* pSlot;
	if (!GetSlotPointer(dwSlotIndex, &pSlot))
		return;

	for (size_t i = 0; i < pSlot->pNewSlotEffect.size(); i++)
	{
		auto& NewSlotEffect = pSlot->pNewSlotEffect.at(i);
		if (NewSlotEffect == nullptr)
		{
			char buf[128];
			NewSlotEffect = std::make_shared< CAniImageBox >(nullptr);

			for (BYTE j = 0; j < 13; j++)
			{
				if (i == 0)
					snprintf(buf, sizeof(buf), "d:/ymir work/ui/public/slotactiveeffect/%02d.sub", j);
				else
					snprintf(buf, sizeof(buf), "d:/ymir work/ui/public/slotactiveeffect/slot%d/%02d.sub", (i + 1), j);

				NewSlotEffect->AppendImage(buf);
				NewSlotEffect->SetRenderingMode(CGraphicExpandedImageInstance::RENDERING_MODE_SCREEN);
			}
		}

		if (i == (pSlot->byyPlacedItemSize - 1))
			NewSlotEffect->Show();
		else
			NewSlotEffect->Hide();
	}
}

void CSlotWindow::DeactivateNewSlot(const DWORD dwSlotIndex)
{
	TSlot* pSlot;
	if (!GetSlotPointer(dwSlotIndex, &pSlot))
		return;

	for (const auto& NewSlotEffect : pSlot->pNewSlotEffect)
		if (NewSlotEffect)
			NewSlotEffect->Hide();

	/*Clear*/
	SetNewSlotDiffuseColor(dwSlotIndex, ESlotColor::COLOR_TYPE_MAX);
	SetNewSlotFlashEffect(dwSlotIndex, false);
}

void CSlotWindow::SetNewSlotFlashEffect(const DWORD dwSlotIndex, const bool bActive)
{
	TSlot* pSlot;
	if (!GetSlotPointer(dwSlotIndex, &pSlot))
		return;

	pSlot->bFlashEffect = bActive;
}
#endif

//Find
	if (pSlot->pSignImage)
	{
 		pSlot->pSignImage->Hide();
	}

///Add
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
	for (const auto& NewSlotEffect : pSlot->pNewSlotEffect)
	{
		if (NewSlotEffect)
			NewSlotEffect->Hide();
	}

	pSlot->bFlashEffect = false;
#endif

//Find
		if (rSlot.pInstance)
		{
			rSlot.pInstance->SetPosition(m_rect.left + rSlot.ixPosition, m_rect.top + rSlot.iyPosition);
			rSlot.pInstance->Render();
		}

///Change
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
		static bool __bGrowing = false;
		static float __fAlpha = 1.0f;
		__fAlpha += 0.0003f * (__bGrowing ? 1.0f : -1.0f);
		
		if (__fAlpha >= 1.0f || __fAlpha <= 0.0f)
			__bGrowing = !__bGrowing;
#endif
		if (rSlot.pInstance)
		{
			rSlot.pInstance->SetPosition(m_rect.left + rSlot.ixPosition, m_rect.top + rSlot.iyPosition);
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
			rSlot.pInstance->GetDiffuseColor().a = rSlot.bFlashEffect ? __fAlpha : 1.0f;
#endif
			rSlot.pInstance->Render();
		}
		
//Find
		if (rSlot.bActive)
		{
			int ix = m_rect.left + rSlot.ixPosition;
			int iy = m_rect.top + rSlot.iyPosition;
			if (m_pSlotActiveEffect)
			{
				m_pSlotActiveEffect->SetPosition(ix, iy);
				m_pSlotActiveEffect->Render();
			}
		}

///Add
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
		for (const auto& NewSlotEffect : rSlot.pNewSlotEffect)
		{
			if (NewSlotEffect == nullptr || NewSlotEffect->IsShow() == false)
				continue;

			NewSlotEffect->SetPosition(m_rect.left + rSlot.ixPosition, m_rect.top + rSlot.iyPosition);
			NewSlotEffect->Update();
			NewSlotEffect->Render();
		}
#endif

//Find
			rSlot.pNumberLine->SetPosition(ix, iy);

///Add Above
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
			for (const auto& NumberImage : rSlot.pNumberLine->GetImageVector())
			{
				if (NumberImage)
					NumberImage->GetDiffuseColor().a = rSlot.bFlashEffect ? __fAlpha : 1.0f;
			}
#endif