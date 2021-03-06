#pragma once

#include "StartupPars.h"


namespace Doh3d
{

	class WinClass
	{
	public:

		static const StartupPars& startupPars() { return d_startupPars; }

    static bool registerClass(const StartupPars& pStartupPars, const std::string& pApplicationName);
    static void unregisterClass();

	private:

    static StartupPars d_startupPars;
    static std::string d_applicationName;

    static LRESULT __stdcall wndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	};

} // ns Doh3d
