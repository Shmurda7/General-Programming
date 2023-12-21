
    #ifndef RTW_HEADER_rocketLIBRARY_cap_host_h__
    #define RTW_HEADER_rocketLIBRARY_cap_host_h__

    #ifdef HOST_CAPI_BUILD

    #include "rtw_capi.h"
        #include "rtw_modelmap_simtarget.h"


    typedef struct  {
    rtwCAPI_ModelMappingInfo mmi;
    } rocketLIBRARY_host_DataMapInfo_T;

    #ifdef __cplusplus
    extern "C" {
        #endif

        void rocketLIBRARY_host_InitializeDataMapInfo(rocketLIBRARY_host_DataMapInfo_T *dataMap, const char *path);

        #ifdef __cplusplus
    }
    #endif

    #endif /* HOST_CAPI_BUILD */

    #endif /* RTW_HEADER_rocketLIBRARY_cap_host_h__ */

    /* EOF: rocketLIBRARY_capi_host.h */
