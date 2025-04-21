#include <stdio.h>
#include <windows.h>
#include "FULL.h"
void SearchDirectory(const wchar_t* directory, const char* target);
void Search_Disk_C(const char* filename){
    SearchDirectory(L"C:\\", filename);
}
void Search_Disk_D(const char* filename){
    SearchDirectory(L"D:\\", filename);
}
void Search_Disk_Another(const char* filename){
    wchar_t path[MAX_PATH];
    wprintf(L"Enter full path (e.g. E:\\)");
    getchar();
    fgetws(path, MAX_PATH, stdin);
    size_t len = wcslen(path);
    if(len > 0 && path[len - 1] == '\n'){
        path[len - 1] = '\0';
    }
    SearchDirectory(path, filename);
}

void Search_Full(const char* filename) {
    Search_Disk_C(filename);
    Search_Disk_D(filename);
}
void SearchDirectory(const wchar_t* directory, const char* target) {
    wchar_t search_path[MAX_PATH];
    WIN32_FIND_DATAW findFileData;
    HANDLE hFind;
    wsprintfW(search_path, L"%s\\*", directory);
    hFind = FindFirstFileW(search_path, &findFileData);
    if (hFind == INVALID_HANDLE_VALUE) return;
    do {
        if (wcscmp(findFileData.cFileName, L".") == 0 || wcscmp(findFileData.cFileName, L"..") == 0)
            continue;
        wchar_t full_path[MAX_PATH];
        wsprintfW(full_path, L"%s\\%s", directory, findFileData.cFileName);
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            SearchDirectory(full_path, target);
        } else {
            char fileNameA[MAX_PATH];
            wcstombs(fileNameA, findFileData.cFileName, MAX_PATH);
            if (strcmp(fileNameA, target) == 0) {
                wprintf(L"[FOUND] %s\n", full_path);
            }
        }
    } while (FindNextFileW(hFind, &findFileData));
    FindClose(hFind);
}