//this file is part of Function List Plugin for Notepad++
//Copyright (C)2006 Jens Lorenz <jens.plugin.npp@gmx.de>
//
//This program is free software; you can redistribute it and/or
//modify it under the terms of the GNU General Public License
//as published by the Free Software Foundation; either
//version 2 of the License, or (at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program; if not, write to the Free Software
//Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include "AboutDialog.h"
#include "PluginInterface.h"
#include "resource.h"
#include "Window.h"

void AboutDialog::doDialog()
{
	if (!isCreated()) create(IDD_ABOUT_DIALOG);
	goToCenter();
}

INT_PTR CALLBACK AboutDialog::run_dlgProc(UINT Message, WPARAM wParam, LPARAM /*lParam*/)
{
	switch (Message)
	{
		case WM_INITDIALOG :
		{
			_emailLinkJSL.init(_hInst, _hSelf);
			_emailLinkJSL.create(::GetDlgItem(_hSelf, IDC_EMAIL_LINK_JSL), TEXT("mailto:jean.sebastien.leroy@gmail.com"));
			_emailLinkPND.init(_hInst, _hSelf);
			_emailLinkPND.create(::GetDlgItem(_hSelf, IDC_EMAIL_LINK_PND), TEXT("mailto:pg.nedev@gmail.com"));
			_urlOriginalRepo.init(_hInst, _hSelf);
			_urlOriginalRepo.create(::GetDlgItem(_hSelf, IDC_ORIGINAL_REPO_URL), NULL);
			_urlPNDRepo.init(_hInst, _hSelf);
			_urlPNDRepo.create(::GetDlgItem(_hSelf, IDC_PND_REPO_URL), NULL);

			return TRUE;
		}
		case WM_COMMAND :
		{
			switch (wParam)
			{
				case IDC_ABOUT_CLOSE_BUTTON :
				case IDCANCEL :
					display(FALSE);
					return TRUE;

				default :
					break;
			}
			break;
		}
	}
	return FALSE;
}

