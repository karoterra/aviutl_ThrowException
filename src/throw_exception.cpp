#include <Windows.h>
#include <stdexcept>
#include <aviutl_exedit_sdk/aviutl.hpp>

using AviUtl::FilterPlugin;
using AviUtl::detail::FilterPluginFlag;

const char* kFilterName = "ThrowException";
const char* kFilterInformation = "ThrowException v0.1.0 by karoterra";

BOOL func_WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam, AviUtl::EditHandle* editp, FilterPlugin* fp) {
    switch (message) {
    case WM_COMMAND:
        switch (LOWORD(wparam)) {
        case FilterPlugin::MidFilterButton + 0:
            throw std::runtime_error("runtime error by ThrowException.auf");
            break;
        }
        break;
    }
    return FALSE;
}

const char* kCheckName[] = { "例外発生!" };
int kCheckDef[] = { -1 };

AviUtl::FilterPluginDLL filter_src{
    .flag = FilterPluginFlag::AlwaysActive | FilterPluginFlag::ExInformation | FilterPluginFlag::DispFilter,
    .name = kFilterName,
    .check_n = sizeof(kCheckDef) / sizeof(int),
    .check_name = kCheckName,
    .check_default = kCheckDef,
    .func_WndProc = func_WndProc,
    .information = kFilterInformation,
};

extern "C" __declspec(dllexport) AviUtl::FilterPluginDLL * GetFilterTable(void) {
    return &filter_src;
}
