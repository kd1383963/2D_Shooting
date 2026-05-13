#pragma once

class C_KeyManager
{

public:


	bool GetSpaceKey()
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (!SpaceKeyFlg)
			{
				SpaceKeyFlg = true;
				return true;
			}
		}
		else
		{
			SpaceKeyFlg = false;
		}
		return false;
	}
	bool GetYKey()
	{
		if (GetAsyncKeyState('Y') & 0x8000)
		{
			if (!YKeyFlg)
			{
				YKeyFlg = true;
				return true;
			}
		}
		else
		{
			YKeyFlg = false;
		}
		return false;
	}

	bool GetUKey()
	{
		if (GetAsyncKeyState('U') & 0x8000)
		{
			if (!UKeyFlg)
			{
				UKeyFlg = true;
				return true;
			}
		}
		else
		{
			UKeyFlg = false;
		}
		return false;
	}

	bool GetIKey()
	{
		if (GetAsyncKeyState('I') & 0x8000)
		{
			if (!IKeyFlg)
			{
				IKeyFlg = true;
				return true;
			}
		}
		else
		{
			IKeyFlg = false;
		}
		return false;
	}

	bool GetOKey()
	{
		if (GetAsyncKeyState('O') & 0x8000)
		{
			if (!OKeyFlg)
			{
				OKeyFlg = true;
				return true;
			}
		}
		else
		{
			OKeyFlg = false;
		}
		return false;
	}

	bool GetPKey()
	{
		if (GetAsyncKeyState('P') & 0x8000)
		{
			if (!PKeyFlg)
			{
				PKeyFlg = true;
				return true;
			}
		}
		else
		{
			PKeyFlg = false;
		}
		return false;
	}

	bool GetHKey()
	{
		if (GetAsyncKeyState('H') & 0x8000)
		{
			if (!HKeyFlg)
			{
				HKeyFlg = true;
				return true;
			}
		}
		else
		{
			HKeyFlg = false;
		}
		return false;
	}

	bool GetJKey()
	{
		if (GetAsyncKeyState('J') & 0x8000)
		{
			if (!JKeyFlg)
			{
				JKeyFlg = true;
				return true;
			}
		}
		else
		{
			JKeyFlg = false;
		}
		return false;
	}

	bool GetLKey()
	{
		if (GetAsyncKeyState('L') & 0x8000)
		{
			if (!LKeyFlg)
			{
				LKeyFlg = true;
				return true;
			}
		}
		else
		{
			LKeyFlg = false;
		}
		return false;
	}

	//bool GetUpKey()
	//{
	//	if (GetAsyncKeyState(VK_UP) & 0x8000)
	//	{
	//		if (!UpKeyFlg)
	//		{
	//			UpKeyFlg = true;
	//			return true;
	//		}
	//	}
	//	else
	//	{
	//		UpKeyFlg = false;
	//	}
	//	return false;
	//}

	//bool GetDownKey()
	//{
	//	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	//	{
	//		if (!DownKeyFlg)
	//		{
	//			DownKeyFlg = true;
	//			return true;
	//		}
	//	}
	//	else
	//	{
	//		DownKeyFlg = false;
	//	}
	//	return false;
	//}

	//bool GetLeftKey()
	//{
	//	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	//	{
	//		if (!LeftKeyFlg)
	//		{
	//			LeftKeyFlg = true;
	//			return true;
	//		}
	//	}
	//	else
	//	{
	//		LeftKeyFlg = false;
	//	}
	//	return false;
	//}

	//bool GetRightKey()
	//{
	//	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	//	{
	//		if (!RightKeyFlg)
	//		{
	//			RightKeyFlg = true;
	//			return true;
	//		}
	//	}
	//	else
	//	{
	//		RightKeyFlg = false;
	//	}
	//	return false;
	//}

	bool GetLClick()
	{
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			if (!LClickFlg)
			{
				LClickFlg = true;
				return true;
			}
		}
		else
		{
			LClickFlg = false;
		}
		return false;
	}

	//長押し用
	bool GetLDown()
	{
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			return true;
		}
		else
		{
			return	false;
		}
	}

	bool GetRClick()
	{
		if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
		{
			if (!RClickFlg)
			{
				RClickFlg = true;
				return true;
			}
		}
		else
		{
			RClickFlg = false;
		}
		return false;
	}

private:

	C_KeyManager() 
	{
		SpaceKeyFlg = false;
		LClickFlg = false;
		RClickFlg = false;
	}

	//キーごとに必要

	bool SpaceKeyFlg;
	bool UpKeyFlg;
	bool DownKeyFlg;
	bool LeftKeyFlg;
	bool RightKeyFlg;
	bool LClickFlg;
	bool RClickFlg;

	bool YKeyFlg;
	bool UKeyFlg;
	bool IKeyFlg;
	bool OKeyFlg;
	bool PKeyFlg;

	bool HKeyFlg;
	bool JKeyFlg;
	bool LKeyFlg;

public:

	static C_KeyManager& GetInstance()
	{
		static C_KeyManager instance;
		return instance;
	}

};

