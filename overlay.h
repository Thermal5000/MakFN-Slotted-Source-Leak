#pragma once
#include <d2d1.h>
#include <d3d9.h>
#include <dwmapi.h>
#include <dwrite.h>
#include <string>
#include <vector>
#include <windows.h>

class Overlay
{
private:
    HWND window;

    const wchar_t* font;
    float          size;

public:
    Overlay(const wchar_t* Font, float Font_Size)
    {
        this->font = Font;
        this->size = Font_Size;
    }

    ~Overlay()
    {

    }

    bool init();
};