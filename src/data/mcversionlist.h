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
#include <wx/string.h>
#include <vector>
#include <stdint.h>

enum VersionType
{
	OldSnapshot,
	Stable,
	CurrentStable,
	Snapshot
};

struct MCVersion
{
	MCVersion(wxString _name, uint64_t _unixTimestamp, wxString _dlURL, bool _has_lwjgl, wxString _etag)
	: name(_name), unixTimestamp(_unixTimestamp), dlURL(_dlURL), has_lwjgl(_has_lwjgl), etag(_etag)
	{
	}
	MCVersion()
	{
		unixTimestamp = 0;
		has_lwjgl = false;
	}
	// the mojang version string
	wxString name;
	// checksum
	wxString etag;
	// last changed unix time in seconds. nice for sorting :3
	uint64_t unixTimestamp;
	// base URL for download
	wxString dlURL;
	// this version has a mojang lwjgl associated with it
	bool has_lwjgl;
	VersionType type;
};

class MCVersionList
{
public:
	static MCVersionList& Instance()
	{
		if (pInstance == 0)
			pInstance = new MCVersionList();
		return *pInstance;
	};
	

	bool Reload();
	bool LoadIfNeeded();
	bool NeedsLoad()
	{
		return versions.size() == 0;
	}

	std::vector <MCVersion> versions;
	int stableVersionIndex;
private:
	static MCVersionList * pInstance;
	MCVersionList();
};
