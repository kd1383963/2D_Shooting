#include"Mouse.h"
#include "main.h"

void C_Mouse::Init()
{
	m_Mouse = GetMousePos();
}

void C_Mouse::Update()
{
	m_Mouse = GetMousePos();
}

void C_Mouse::Draw()
{
}

POINT C_Mouse::GetMousePos()
{
	POINT m;
	GetCursorPos(&m);
	ScreenToClient(APP.m_window.GetWndHandle(), &m);
	m.x -= ScrWidth / 2;
	m.y -= ScrHeight / 2;
	m.y *= -1;
	return m;

}


