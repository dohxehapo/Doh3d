#include "Doh3d.h"
#include "GGrid.h"


namespace Doh3d
{

	GGrid::GGrid(float pPosX, float pPosY, float pSizeX, float pSizeY, int pNumberOfCells,
				 const std::string& pTextureName, const std::string& pFrameTextureName)
	{
		m_position.x = roundf(pPosX);
		m_position.y = roundf(pPosY);
		m_position.z = 0;
		m_size.x = pSizeX;
		m_size.y = pSizeY;

		m_textureName = pTextureName;
		m_frameTextureName = pFrameTextureName;
		m_ti = 0;
		m_tiFrame = 0;

		m_numberOfCells = pNumberOfCells;
		m_selectedCell = -1;
		m_items.resize(pNumberOfCells, nullptr);
	}
	
	GGrid::~GGrid() { }


	ErrCode3d GGrid::Load()
	{
		LOG("GGrid::Load()");
		ErrCode3d err;

		err = ResourceMan::GetTi(m_textureName, m_ti);
		if (err != err3d_noErr)
		{
			echo("ERROR: Can't get TI for GGrid (id: ", m_id, "): \"", m_textureName, "\".");
			return err;
		}

		err = ResourceMan::GetTi(m_frameTextureName, m_tiFrame);
		if (err != err3d_noErr)
		{
			echo("ERROR: Can't get TI for GGrid frame (id: ", m_id, "): \"", m_textureName, "\".");
			return err;
		}

		err = UpdateTransformMatrix();
		if (err != err3d_noErr)
		{
			echo("ERROR: Can't update TransformMatrix for GGrid (id: ", m_id, ").");
			return err;
		}

		return err3d_noErr;
	}

	ErrCode3d GGrid::Unload()
	{
		return err3d_noErr;
	}


	ErrCode3d GGrid::Draw(Sprite& pSprite) const
	{
		LOG("GGrid::Draw()");
		int hRes;

		pSprite.Get()->SetTransform(&m_transformMatrix);

		hRes = pSprite.Get()->Draw(ResourceMan::GetTexture(m_ti).Get(), 0, 0, &m_position, D3DCOLOR_ARGB(255, 255, 255, 255));
		if (hRes != S_OK)
		{
			echo("ERROR: Can't draw sprite.");
			return err3d_cantDrawSprite;
		}

		// Selection frame

		if (m_selectedCell != -1)
		{
			D3DXVECTOR3 framePos = m_position + m_frameOffset + m_gridShift * (FLOAT)m_selectedCell;
			hRes = pSprite.Get()->Draw(ResourceMan::GetTexture(m_tiFrame).Get(), 0, 0, &(framePos), D3DCOLOR_ARGB(255, 255, 255, 255));
			if (hRes != S_OK)
			{
				echo("ERROR: Can't draw sprite.");
				return err3d_cantDrawSprite;
			}
		}

		// Items

		int cellNumber = -1;
		for (auto* pItem : m_items)
		{
			++cellNumber;
			if (!pItem) continue;

			D3DXVECTOR3 framePos = m_position + m_gridOffset + m_gridShift * (FLOAT)cellNumber;
			hRes = pSprite.Get()->Draw(ResourceMan::GetTexture(pItem->GetTi()).Get(), 0, 0, &(framePos), D3DCOLOR_ARGB(255, 255, 255, 255));
			if (hRes != S_OK)
			{
				echo("ERROR: Can't draw sprite.");
				return err3d_cantDrawSprite;
			}
		}

		return err3d_noErr;
	}


	ErrCode3d GGrid::OnMouseMove(bool& pHandled)
	{
		LOG("GGrid::OnMouseMove()");
		ErrCode3d err;

		err = GBase::OnMouseMove(pHandled);
		if (err != err3d_noErr)
		{
			echo("ERROR: Error occurred while GBase::OnMouseMove().");
			return err;
		}

		return err3d_noErr;
	}

	ErrCode3d GGrid::OnMouseDown(bool& pHandled, int pButton)
	{
		LOG("GGrid::OnMouseDown()");
		ErrCode3d err;

		err = GBase::OnMouseDown(pHandled, pButton);
		if (err != err3d_noErr)
		{
			echo("ERROR: Error occurred while GBase::OnMouseDown().");
			return err;
		}

		return err3d_noErr;
	}

	ErrCode3d GGrid::OnMouseUp(bool& pHandled, int pButton)
	{
		LOG("GButton::OnMouseUp()");
		ErrCode3d err;

		err = GBase::OnMouseUp(pHandled, pButton);
		if (err != err3d_noErr)
		{
			echo("ERROR: Error occurred while GBase::OnMouseUp().");
			return err;
		}

		return err3d_noErr;
	}


	D3DXVECTOR2 GGrid::GetOriginalSize() const
	{
		return ResourceMan::GetTexture(m_ti).GetSize();
	}


	GridItem* GGrid::SelectCell(int pCellIndex)
	{
		if (pCellIndex < -1 || pCellIndex >= m_numberOfCells)
			return nullptr;

		m_selectedCell = pCellIndex;

		return m_selectedCell == -1 ? nullptr : m_items[m_selectedCell];
	}

	GridItem* GGrid::GetItem(int pItemIndex)
	{
		if (pItemIndex < 0 || pItemIndex >= (int)m_items.size())
			return nullptr;
		return m_items[pItemIndex];
	}

} // ns Doh3d