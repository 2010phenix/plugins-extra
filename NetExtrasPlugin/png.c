/*
 * Process Hacker Extra Plugins -
 *   Network Extras Plugin
 *
 * Copyright (C) 2016 dmex
 *
 * This file is part of Process Hacker.
 *
 * Process Hacker is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Process Hacker is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Process Hacker.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "main.h"

struct 
{
    PWSTR CountryCode;
    INT ResourceID;
} 
CountryResourceTable[] =
{
    { L"AD", AD_PNG },
    { L"AE", AE_PNG },
    { L"AF", AF_PNG },
    { L"AG", AG_PNG },
    { L"AI", AI_PNG },
    { L"AL", AL_PNG },
    { L"AM", AM_PNG },
    { L"AN", AN_PNG },
    { L"AO", AO_PNG },
    { L"AR", AR_PNG },
    { L"AS", AS_PNG },
    { L"AT", AT_PNG },
    { L"AU", AU_PNG },
    { L"AW", AW_PNG },
    { L"AX", AX_PNG },
    { L"AZ", AZ_PNG },

    { L"BA", BA_PNG },
    { L"BB", BB_PNG },
    { L"BD", BD_PNG },
    { L"BE", BE_PNG },
    { L"BF", BF_PNG },
    { L"BG", BG_PNG },
    { L"BH", BH_PNG },
    { L"BI", BI__PNG },
    { L"BJ", BJ_PNG },
    { L"BM", BM_PNG },
    { L"BN", BN_PNG },
    { L"BO", BO_PNG },
    { L"BR", BR_PNG },
    { L"BS", BS_PNG },
    { L"BT", BT_PNG },
    { L"BV", BV_PNG },
    { L"BW", BW_PNG },
    { L"BY", BY_PNG },
    { L"BZ", BZ_PNG },

    { L"CA", CA_PNG },
    { L"CC", CC_PNG },
    { L"CD", CD_PNG },
    { L"CF", CF_PNG },
    { L"CG", CG_PNG },
    { L"CH", CH_PNG },
    { L"CI", CI_PNG },
    { L"CK", CK_PNG },
    { L"CL", CL_PNG },
    { L"CM", CM_PNG },
    { L"CN", CN_PNG },
    { L"CO", CO_PNG },
    { L"CR", CR_PNG },
    { L"CS", CS_PNG },
    { L"CU", CU_PNG },
    { L"CV", CV_PNG },
    { L"CX", CX_PNG },
    { L"CY", CY_PNG },
    { L"CZ", CZ_PNG },

    { L"DE", DE_PNG },
    { L"DJ", DJ_PNG },
    { L"DK", DK_PNG },
    { L"DM", DM_PNG },
    { L"DO", DO_PNG },
    { L"DZ", DZ_PNG },

    { L"EC", EC_PNG },
    { L"EE", EE_PNG },
    { L"EG", EG_PNG },
    { L"EH", EH_PNG },
    { L"ER", ER_PNG },
    { L"ES", ES_PNG },
    { L"ET", ET_PNG },

    { L"FI", FI_PNG },
    { L"FJ", FJ_PNG },
    { L"FK", FK_PNG },
    { L"FO", FO_PNG },
    { L"FR", FR_PNG },

    { L"GA", GA_PNG },
    { L"GB", GB_PNG },
    { L"GD", GD_PNG },
    { L"GE", GE_PNG },
    { L"GF", GF_PNG },
    { L"GH", GH_PNG },
    { L"GI", GI_PNG },
    { L"GL", GL_PNG },
    { L"GM", GM_PNG },
    { L"GN", GN_PNG },
    { L"GP", GP_PNG },
    { L"GQ", GQ_PNG },
    { L"GR", GR_PNG },
    { L"GS", GS_PNG },
    { L"GT", GT_PNG },
    { L"GU", GU_PNG },
    { L"GW", GW_PNG },
    { L"GY", GY_PNG },

    { L"HK", HK_PNG },
    { L"HM", HM_PNG },
    { L"HN", HN_PNG },
    { L"HR", HR_PNG },
    { L"HT", HT_PNG },
    { L"HU", HU_PNG },

    { L"ID", ID_PNG },
    { L"IE", IE_PNG },
    { L"IL", IL_PNG },
    { L"IN", IN_PNG },
    { L"IO", IO_PNG },
    { L"IQ", IQ_PNG },
    { L"IR", IR_PNG },
    { L"IS", IS_PNG },
    { L"IT", IT_PNG },

    { L"JM", JM_PNG },
    { L"JO", JO_PNG },
    { L"JP", JP_PNG },

    { L"KE", KE_PNG },
    { L"KG", KG_PNG },
    { L"KH", KH_PNG },
    { L"KI", KI_PNG },
    { L"KM", KM_PNG },
    { L"KN", KN_PNG },
    { L"KP", KP_PNG },
    { L"KR", KR_PNG },
    { L"KW", KW_PNG },
    { L"KY", KY_PNG },
    { L"KZ", KZ_PNG },

    { L"LA", LA_PNG },
    { L"LB", LB_PNG },
    { L"LC", LC_PNG },
    { L"LI", LI_PNG },
    { L"LK", LK_PNG },
    { L"LR", LR_PNG },
    { L"LS", LS_PNG },
    { L"LT", LT_PNG },
    { L"LU", LU_PNG },
    { L"LV", LV_PNG },
    { L"LY", LY_PNG },

    { L"MA", MA_PNG },
    { L"MC", MC_PNG },
    { L"MD", MD_PNG },
    { L"ME", ME_PNG },
    { L"MG", MG_PNG },
    { L"MH", MH_PNG },
    { L"MK", MK_PNG },
    { L"ML", ML_PNG },
    { L"MM", MM_PNG },
    { L"MN", MN_PNG },
    { L"MO", MO_PNG },
    { L"MP", MP_PNG },
    { L"MQ", MQ_PNG },
    { L"MR", MR_PNG },
    { L"MS", MS_PNG },
    { L"MT", MT_PNG },
    { L"MU", MU_PNG },
    { L"MV", MV_PNG },
    { L"MW", MW_PNG },
    { L"MX", MX_PNG },
    { L"MY", MY_PNG },
    { L"MZ", MZ_PNG },

    { L"NA", NA_PNG },
    { L"NC", NC_PNG },
    { L"NE", NE_PNG },
    { L"NF", NF_PNG },
    { L"NG", NG_PNG },
    { L"NI", NI_PNG },
    { L"NL", NL_PNG },
    { L"NO", NO_PNG },
    { L"NP", NP_PNG },
    { L"NR", NR_PNG },
    { L"NU", NU_PNG },
    { L"NZ", NZ_PNG },

    { L"OM", OM_PNG },

    { L"PA", PA_PNG },
    { L"PE", PE_PNG },
    { L"PF", PF_PNG },
    { L"PG", PG_PNG },
    { L"PH", PH_PNG },
    { L"PK", PK_PNG },
    { L"PL", PL_PNG },
    { L"PM", PM_PNG },
    { L"PN", PN_PNG },
    { L"PR", PR_PNG },
    { L"PS", PS_PNG },
    { L"PT", PT_PNG },
    { L"PW", PW_PNG },
    { L"PY", PY_PNG },

    { L"QA", QA_PNG },

    { L"RE", RE_PNG },
    { L"RO", RO_PNG },
    { L"RS", RS_PNG },
    { L"RU", RU_PNG },
    { L"RW", RW_PNG },

    { L"SA", SA_PNG },
    { L"SB", SB_PNG },
    { L"SC", SC_PNG },
    { L"SD", SD_PNG },
    { L"SE", SE_PNG },
    { L"SG", SG_PNG },
    { L"SH", SH_PNG },
    { L"SI", SI_PNG },
    { L"SJ", SJ_PNG },
    { L"SK", SK_PNG },
    { L"SL", SL_PNG },
    { L"SM", SM_PNG },
    { L"SN", SN_PNG },
    { L"SO", SO_PNG },
    { L"SR", SR_PNG },
    { L"ST", ST_PNG },
    { L"SV", SV_PNG },
    { L"SY", SY_PNG },
    { L"SZ", SZ_PNG },

    { L"TC", TC_PNG },
    { L"TD", TD_PNG },
    { L"TF", TF_PNG },
    { L"TG", TG_PNG },
    { L"TH", TH_PNG },
    { L"TJ", TJ_PNG },
    { L"TK", TK_PNG },
    { L"TL", TL_PNG },
    { L"TM", TM_PNG },
    { L"TN", TN_PNG },
    { L"TO", TO_PNG },
    { L"TR", TR_PNG },
    { L"TT", TT_PNG },
    { L"TV", TV_PNG },
    { L"TW", TW_PNG },
    { L"TZ", TZ_PNG },

    { L"UA", UA_PNG },
    { L"UG", UG_PNG },
    { L"UM", UM_PNG },
    { L"US", US_PNG },
    { L"UY", UY_PNG },
    { L"UZ", UZ_PNG },

    { L"VA", VA_PNG },
    { L"VC", VC_PNG },
    { L"VE", VE_PNG },
    { L"VG", VG_PNG },
    { L"VI", VI_PNG },
    { L"VN", VN_PNG },
    { L"VU", VU_PNG },

    { L"WF", WF_PNG },
    { L"WS", WS_PNG },

    { L"YE", YE_PNG },
    { L"YT", YT_PNG },

    { L"ZA", ZA_PNG },
    { L"ZM", ZM_PNG },
    { L"ZW", ZW_PNG }
};

static INT LookupResourceCode(_In_ PPH_STRING Name)
{
    for (INT i = 0; i < ARRAYSIZE(CountryResourceTable); i++)
    {
        if (PhEqualString2(Name, CountryResourceTable[i].CountryCode, TRUE))
        {
            return CountryResourceTable[i].ResourceID;
        }
    }

    return 0;
}

HBITMAP LoadImageFromResources(
    _In_ UINT Width,
    _In_ UINT Height,
    _In_ PPH_STRING Name
    )
{
    UINT frameCount = 0;
    BOOLEAN isSuccess = FALSE;
    ULONG resourceLength = 0;
    HGLOBAL resourceHandle = NULL;
    HRSRC resourceHandleSource = NULL;
    WICInProcPointer resourceBuffer = NULL;
    HDC screenHdc = NULL;
    HDC bufferDc = NULL;
    BITMAPINFO bitmapInfo = { 0 };
    HBITMAP bitmapHandle = NULL;
    PBYTE bitmapBuffer = NULL;
    IWICStream* wicStream = NULL;
    IWICBitmapSource* wicBitmapSource = NULL;
    IWICBitmapDecoder* wicDecoder = NULL;
    IWICBitmapFrameDecode* wicFrame = NULL;
    IWICImagingFactory* wicFactory = NULL;
    IWICBitmapScaler* wicScaler = NULL;
    WICPixelFormatGUID pixelFormat;
    WICRect rect = { 0, 0, Width, Height };

    INT resourceCode = LookupResourceCode(Name);

    if (resourceCode == 0)
        return NULL;

    __try
    {
        // Create the ImagingFactory
        if (FAILED(CoCreateInstance(&CLSID_WICImagingFactory1, NULL, CLSCTX_INPROC_SERVER, &IID_IWICImagingFactory, &wicFactory)))
            __leave;

        // Find the resource
        if ((resourceHandleSource = FindResource(PluginInstance->DllBase, MAKEINTRESOURCE(resourceCode), L"PNG")) == NULL)
            __leave;

        // Get the resource length
        resourceLength = SizeofResource(PluginInstance->DllBase, resourceHandleSource);

        // Load the resource
        if ((resourceHandle = LoadResource(PluginInstance->DllBase, resourceHandleSource)) == NULL)
            __leave;

        if ((resourceBuffer = (WICInProcPointer)LockResource(resourceHandle)) == NULL)
            __leave;

        // Create the Stream
        if (FAILED(IWICImagingFactory_CreateStream(wicFactory, &wicStream)))
            __leave;

        // Initialize the Stream from Memory
        if (FAILED(IWICStream_InitializeFromMemory(wicStream, resourceBuffer, resourceLength)))
            __leave;

        if (FAILED(IWICImagingFactory_CreateDecoder(wicFactory, &GUID_ContainerFormatPng, NULL, &wicDecoder)))
            __leave;

        if (FAILED(IWICBitmapDecoder_Initialize(wicDecoder, (IStream*)wicStream, WICDecodeMetadataCacheOnLoad)))
            __leave;

        // Get the Frame count
        if (FAILED(IWICBitmapDecoder_GetFrameCount(wicDecoder, &frameCount)) || frameCount < 1)
            __leave;

        // Get the Frame
        if (FAILED(IWICBitmapDecoder_GetFrame(wicDecoder, 0, &wicFrame)))
            __leave;

        // Get the WicFrame image format
        if (FAILED(IWICBitmapFrameDecode_GetPixelFormat(wicFrame, &pixelFormat)))
            __leave;

        // Check if the image format is supported:
        if (IsEqualGUID(&pixelFormat, &GUID_WICPixelFormat32bppPRGBA))
        {
            wicBitmapSource = (IWICBitmapSource*)wicFrame;
        }
        else
        {
            IWICFormatConverter* wicFormatConverter = NULL;

            if (FAILED(IWICImagingFactory_CreateFormatConverter(wicFactory, &wicFormatConverter)))
                __leave;

            if (FAILED(IWICFormatConverter_Initialize(
                wicFormatConverter,
                (IWICBitmapSource*)wicFrame,
                &GUID_WICPixelFormat32bppPRGBA,
                WICBitmapDitherTypeNone,
                NULL,
                0.0,
                WICBitmapPaletteTypeCustom
                )))
            {
                IWICFormatConverter_Release(wicFormatConverter);
                __leave;
            }

            // Convert the image to the correct format:
            IWICFormatConverter_QueryInterface(wicFormatConverter, &IID_IWICBitmapSource, &wicBitmapSource);

            // Cleanup the converter.
            IWICFormatConverter_Release(wicFormatConverter);

            // Dispose the old frame now that the converted frame is in wicBitmapSource.
            IWICBitmapFrameDecode_Release(wicFrame);
        }

        bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        bitmapInfo.bmiHeader.biWidth = rect.Width;
        bitmapInfo.bmiHeader.biHeight = -((LONG)rect.Height);
        bitmapInfo.bmiHeader.biPlanes = 1;
        bitmapInfo.bmiHeader.biBitCount = 32;
        bitmapInfo.bmiHeader.biCompression = BI_RGB;

        screenHdc = GetDC(NULL);
        bufferDc = CreateCompatibleDC(screenHdc);
        bitmapHandle = CreateDIBSection(screenHdc, &bitmapInfo, DIB_RGB_COLORS, (PVOID*)&bitmapBuffer, NULL, 0);

        // Check if it's the same rect as the requested size.
        //if (width != rect.Width || height != rect.Height)
        if (FAILED(IWICImagingFactory_CreateBitmapScaler(wicFactory, &wicScaler)))
            __leave;
        if (FAILED(IWICBitmapScaler_Initialize(wicScaler, wicBitmapSource, rect.Width, rect.Height, WICBitmapInterpolationModeFant)))
            __leave;
        if (FAILED(IWICBitmapScaler_CopyPixels(wicScaler, &rect, rect.Width * 4, rect.Width * rect.Height * 4, bitmapBuffer)))
            __leave;

        isSuccess = TRUE;
    }
    __finally
    {
        if (wicScaler)
        {
            IWICBitmapScaler_Release(wicScaler);
        }

        if (bufferDc)
        {
            DeleteDC(bufferDc);
        }

        if (screenHdc)
        {
            ReleaseDC(NULL, screenHdc);
        }

        if (wicBitmapSource)
        {
            IWICBitmapSource_Release(wicBitmapSource);
        }

        if (wicStream)
        {
            IWICStream_Release(wicStream);
        }

        if (wicDecoder)
        {
            IWICBitmapDecoder_Release(wicDecoder);
        }

        if (wicFactory)
        {
            IWICImagingFactory_Release(wicFactory);
        }

        if (resourceHandle)
        {
            FreeResource(resourceHandle);
        }
    }

    if (isSuccess)
        return bitmapHandle;

    DeleteObject(bitmapHandle);
    return NULL;
}
