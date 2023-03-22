#include "SaveScreen.h"

void SaveFailed(NavigationHost& NavHost)
{
    View::DrawMenuCenter(Language::GetString(L"SAVE_FAILED_TITLE"), {}, 0);
    InputHandle::Get();
    return NavHost.Back();
}

void SaveSuccess(NavigationHost& NavHost)
{
    View::DrawMenuCenter(Language::GetString(L"SAVE_SUCCESS_TITLE"), {}, 0);
    InputHandle::Get();
    return NavHost.Back();
}
