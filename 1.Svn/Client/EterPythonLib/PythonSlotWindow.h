///Add
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
#include <array>
#endif

//Find
	enum ESlotStyle
	{
		...
	};

///Add
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
	enum ESlotColor
	{
		COLOR_TYPE_ORANGE,
		COLOR_TYPE_WHITE,
		COLOR_TYPE_RED,
		COLOR_TYPE_GREEN,
		COLOR_TYPE_YELLOW,
		COLOR_TYPE_SKY,
		COLOR_TYPE_PINK,
		COLOR_TYPE_BLUE,
		COLOR_TYPE_DARK_BLUE,
		COLOR_TYPE_PURPLE,
		COLOR_TYPE_GRAY,
		COLOR_TYPE_SILVER,

		COLOR_TYPE_MAX
	};

	enum ESlotHilight
	{
		HILIGHTSLOT_ACCE,
		HILIGHTSLOT_CHANGE_LOOK,
		HILIGHTSLOT_AURA,
		HILIGHTSLOT_CUBE,

		HILIGHTSLOT_MAX
	};
#endif

//Find
				CAniImageBox * pFinishCoolTimeEffect;

///Add
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
				std::array<std::shared_ptr< CAniImageBox >, 3> pNewSlotEffect;
				bool bFlashEffect;
#endif

//Find
			void RefreshSlot();

///Add
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
			D3DXCOLOR GetNewSlotColor(const BYTE blType) const;
			void SetNewSlotDiffuseColor(const DWORD dwIndex, const BYTE blType);
			void ActivateNewSlot(const DWORD dwSlotIndex);
			void DeactivateNewSlot(const DWORD dwSlotIndex);
			void SetNewSlotFlashEffect(const DWORD dwSlotIndex, const bool bActive);
#endif