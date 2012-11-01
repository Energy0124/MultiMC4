// 
//  Copyright 2012 MultiMC Contributors
// 
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
// 
//        http://www.apache.org/licenses/LICENSE-2.0
// 
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
//

#pragma once
#include <wx/dialog.h>

#include "instance.h"
#include "task.h"

class ForgeListCtrl : public wxListCtrl
{
public:
ForgeListCtrl(wxWindow* parent):wxListCtrl(parent,-1,wxDefaultPosition,wxDefaultSize,wxLC_SINGLE_SEL| wxLC_REPORT){};
ForgeListCtrl():wxListCtrl(){};
virtual ~ForgeListCtrl(){};

void SetupColumns();
void OnSize( wxSizeEvent& event );

private:
DECLARE_DYNAMIC_CLASS(ForgeListCtrl)
DECLARE_EVENT_TABLE()
};



class InstallForgeDialog : public wxDialog
{
public:
	InstallForgeDialog(wxWindow *parent);

	wxString GetSelectedBuild();

protected:
	void LoadBuildList();

	void OnRefreshListClicked(wxCommandEvent& event);
	void OnListBoxSelChange(wxCommandEvent& event);

	void UpdateOKBtn();

	ForgeListCtrl *buildList;

	DECLARE_EVENT_TABLE()
};
