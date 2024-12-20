#include "pch.h"
#include "Utils.h"

void Utils::DrawText(HDC hdc, Pos pos, const wstring& str)
{
	::TextOut(hdc, static_cast<int32>(pos.GetX()), static_cast<int32>(pos.GetY()), str.c_str(), static_cast<int32>(str.size()));
}

void Utils::DrawRect(HDC hdc, Pos pos, int32 w, int32 h)
{
	::Rectangle(hdc, static_cast<int32>(pos.GetX()- w / 2), static_cast<int32>(pos.GetY() - h / 2), static_cast<int32>(pos.GetX() + w / 2), static_cast<int32>(pos.GetY() + h / 2));
}

void Utils::DrawCircle(HDC hdc, Pos pos, int32 radius)
{
	::Ellipse(hdc, static_cast<int32>(pos.GetX() - radius), static_cast<int32>(pos.GetY() - radius), static_cast<int32>(pos.GetX() + radius), static_cast<int32>(pos.GetY() + radius));
}

void Utils::DrawLine(HDC hdc, Pos from, Pos to)
{
	::MoveToEx(hdc, static_cast<int32>(from.GetX()), static_cast<int32>(from.GetY()), nullptr);
	::LineTo(hdc, static_cast<int32>(to.GetX()), static_cast<int32>(to.GetY()));
}

void Utils::DrawLineColored(HDC hdc, Pos from, Pos to, COLORREF color)
{
	HPEN pen = ::CreatePen(PS_SOLID, 1, color);
	HPEN oldPen = (HPEN)::SelectObject(hdc, (HGDIOBJ)pen);

	::MoveToEx(hdc, static_cast<int32>(from.GetX()), static_cast<int32>(from.GetY()), nullptr);
	::LineTo(hdc, static_cast<int32>(to.GetX()), static_cast<int32>(to.GetY()));

	::SelectObject(hdc, oldPen);
	::DeleteObject(pen);
}

void Utils::ReadBmp(const wstring& path)
{
	FILE* fp = nullptr;

	if (::_wfopen_s(&fp, path.c_str(), L"rb") != 0)
		return;

	BITMAPFILEHEADER fileHeader = {};
	::fread_s(&fileHeader, sizeof(fileHeader), sizeof(fileHeader), 1, fp);

	BITMAPINFOHEADER infoHeader = {};
	::fread_s(&infoHeader, sizeof(infoHeader), sizeof(infoHeader), 1, fp);

	int32 imgSize = infoHeader.biWidth * infoHeader.biHeight * 4;
	char* buffer = (char*)::malloc(imgSize);
	fread_s(buffer, imgSize, imgSize, 1, fp);

	//::free(buffer);
}
