#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include "hi_unf_otp.h"
#include "hi_type.h"

static HI_S32 s_printBuffer(HI_CHAR *pString, HI_U8 *pu8Buf, HI_U32 u32Len)
{
    HI_U32 i;

    if ( (NULL == pu8Buf) || (NULL == pString) )
    {
        printf("null pointer input in function print_buf!\n");
        return HI_FAILURE;
    }

    printf("%s:\n", pString);
    for ( i = 0 ; i < u32Len ; i++ )
    {
        if ( ( i != 0) && ( (i% 16) == 0) )
        {
            printf("\n");
        }
        printf("%x ", pu8Buf[i]);
    }
    printf("\n");

    return HI_SUCCESS;
}

HI_S32 main(int argc, char *argv[])
{
    HI_S32 ret = HI_SUCCESS;
    HI_U8 au8HDCPRootKey[16] = {0x12,0x34,0x56,0x78,0,0,0,0,0,0,0,0,0,0,0,0};

    ret = HI_UNF_OTP_Init();
	if(HI_SUCCESS != ret)
	{
		printf("OTP init failed!\n");
		return HI_FAILURE;
	}

    ret = HI_UNF_OTP_WriteHdcpRootKey(au8HDCPRootKey, 16);
	if(HI_SUCCESS != ret)
	{
		printf("HI_UNF_OTP_WriteHdcpRootKey failed!\n");
		(HI_VOID)HI_UNF_OTP_DeInit();
		return HI_FAILURE;
	}

    s_printBuffer("set hdcp root key", au8HDCPRootKey, sizeof(au8HDCPRootKey));

    (HI_VOID)HI_UNF_OTP_DeInit();

    return HI_SUCCESS;
}

