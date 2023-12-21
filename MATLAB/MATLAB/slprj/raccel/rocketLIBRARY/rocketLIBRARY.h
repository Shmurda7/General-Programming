

        /*
    * rocketLIBRARY.h
    *
            * Academic License - for use in teaching, academic research, and meeting
* course requirements at degree granting institutions only.  Not for
* government, commercial, or other organizational use.
        *
    * Code generation for model "rocketLIBRARY".
    *
    * Model version              : 1.19
    * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
        * C source code generated on : Mon Dec  4 23:30:39 2023
 * 
 * Target selection: raccel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
    */


    #ifndef RTW_HEADER_rocketLIBRARY_h_
    #define RTW_HEADER_rocketLIBRARY_h_



                    #ifndef rocketLIBRARY_COMMON_INCLUDES_
            #define rocketLIBRARY_COMMON_INCLUDES_
                #include <stdlib.h>
        #include "rtwtypes.h"
        #include "sigstream_rtw.h"
        #include "simtarget/slSimTgtSigstreamRTW.h"
        #include "simtarget/slSimTgtSlioCoreRTW.h"
        #include "simtarget/slSimTgtSlioClientsRTW.h"
        #include "simtarget/slSimTgtSlioSdiRTW.h"
        #include "simstruc.h"
        #include "fixedpoint.h"
        #include "raccel.h"
        #include "slsv_diagnostic_codegen_c_api.h"
        #include "rt_logging_simtarget.h"
        #include "dt_info.h"
        #include "ext_work.h"

            #endif /* rocketLIBRARY_COMMON_INCLUDES_ */



#include "rocketLIBRARY_types.h"

#include <string.h>

#include <stddef.h>

#include "rtw_modelmap_simtarget.h"

#include "rt_defines.h"

#include "rtGetInf.h"

#include "rt_nonfinite.h"


    

    

    

    
            #define MODEL_NAME rocketLIBRARY
    #define NSAMPLE_TIMES (4) /* Number of sample times */
    #define NINPUTS (0)       /* Number of model inputs */
    #define NOUTPUTS (0)     /* Number of model outputs */
    #define NBLOCKIO (77) /* Number of data output port signals */
    #define NUM_ZC_EVENTS (0) /* Number of zero-crossing events */


            #ifndef NCSTATES
    #define NCSTATES (12)   /* Number of continuous states */
    #elif NCSTATES != 12
    # error Invalid specification of NCSTATES defined in compiler command
    #endif



                    #ifndef rtmGetDataMapInfo
            #define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
            #endif

            #ifndef rtmSetDataMapInfo
            #define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
            #endif




    

    

    

            
            /* user code (top of header file) */
            #ifndef IN_RACCEL_MAIN

#endif

                    /* Block signals (default storage) */
                    
        typedef struct  {
        




                    
                    


                        



                            
                            
                                   real_T p0shvkceq5[3]; /* '<S5>/xe,ye,ze' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T gmtjwxhcc4[3]; /* '<S50>/phi theta psi' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ntqzzqi1dc[3]; /* '<Root>/Switch' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T gsdo2pjwzd; /* '<Root>/Sum1' */

                        
                        
                        


                    






                    
                    


                        



                            
                                   real_T bvik5bxnsw[3]; 

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nxlaprucin[9]; /* '<S60>/Vector Concatenate' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T eenfrxbcez[3]; /* '<S71>/Unit Conversion' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T kzzs5lii4k[3]; /* '<S6>/3ft-->inf' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T hndudxkdvr[3]; /* '<S6>/h//z0' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T fvn3vgbif3[3]; /* '<S6>/Product' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T jes3bzaku0[3]; /* '<S6>/Product1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nz4yxh1qfq[3]; /* '<S6>/Transform from Inertial to Body axes' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T pzpb0aaq1i[3]; /* '<S4>/Limit  altitude  to troposhere' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T az30op0bz1[3]; /* '<S4>/Lapse Rate' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T djlhbobpcq[3]; /* '<S4>/Sum1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T efsisy4fdx[3]; /* '<S4>/1//T0' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T pocvhehxoq[3]; /* '<S4>/Product' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T frtaiwzqi5[3]; /* '<S4>/rho0' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T gx2bnlk0lw[3]; /* '<S4>/Sum' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T bbyymkm3vn[3]; /* '<S4>/Limit  altitude  to Stratosphere' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T gus0dwpmta[3]; /* '<S4>/g//R' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ons4nt2sr3[3]; /* '<S4>/Product1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T cs1icxkpbk[3]; /* '<S4>/Product3' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T eweodspclo[3]; /* '<Root>/Product1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T beqzc5bw0r[3]; /* '<S2>/reference area' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ppbw2ujmty[3]; /* '<S2>/Product' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T a5kvjjzqcc[3]; /* '<Root>/Sum' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ltespdje45[2]; /* '<S3>/Sum' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T f3grp50dae; /* '<S35>/Abs' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T a4vnpcfi1i; /* '<S35>/Switch' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T cnuqgk0ctt; /* '<S32>/Abs1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T apnu1iub5y; /* '<S28>/Switch1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T bzbu3yseb2; /* '<S28>/Sum' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dekfyvtcle; /* '<S33>/Abs' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T p1cjwgdban[3]; /* '<S5>/p,q,r ' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T jrvb2m0kwj[3]; /* '<S50>/phidot thetadot psidot' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T mplveaosnc[3]; /* '<S62>/Product' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T fq0udmcr0d; /* '<S64>/i x j' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T i25dx5gfjj; /* '<S64>/j x k' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T azigzyu2ua; /* '<S64>/k x i' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T osmqo5ipx2; /* '<S65>/i x k' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T mxurwdq3rp; /* '<S65>/j x i' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T n5my3rkxnx; /* '<S65>/k x j' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T h4mpthrjzj[3]; /* '<S61>/Sum' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T gaqfxcn5mu[3]; /* '<S63>/Product' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T fpj41u20a1[3]; /* '<S51>/Sum2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T hdpsy3sguu[3]; /* '<S51>/Product2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ivl5z2vmyi[3]; /* '<S66>/Sum of Elements' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T pjxjfknbqz[3]; /* '<S52>/Sum' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T k0esd4omu2[3]; /* '<S5>/Product' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T grafq4xnvz[3]; /* '<S5>/ub,vb,wb' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T czqbao5rcr; /* '<S68>/j x k' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ds0u1ctsfa; /* '<S68>/k x i' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T mbnstg1xrg; /* '<S68>/i x j' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T jwmr4335zo; /* '<S69>/k x j' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T mgaxq1x2cb; /* '<S69>/i x k' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T cjk455jyf1; /* '<S69>/j x i' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T lbvpk2cioa[3]; /* '<S53>/Sum' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T o3epcvura2[3]; /* '<S5>/Sum' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T oe1t3pfjur[9]; /* '<S5>/Transpose' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nycpslghoj[3]; /* '<S57>/Product' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T czkarcoix3[3]; /* '<S2>/coefAdjust' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T idzov0xqov; /* '<S38>/Switch' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T kf3nkdp1sm; /* '<S39>/Switch' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T o0lznmwy04; /* '<S44>/Trigonometric Function1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T frkjltmijt; /* '<S44>/Trigonometric Function2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T legy4gcyuq; /* '<S30>/SinCos' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T pq2n04xswi; /* '<S30>/SinCos' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T hcxyo5x1fp; /* '<Root>/Product' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T mqmfqguhsp[9]; /* '<S51>/Selector' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T i4ejkbvukm[9]; /* '<S51>/Selector1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T a2i2fdw0sz[9]; /* '<S51>/Selector2' */

                        
                        
                        


                    






                    
                    


                        



                            
                                   real_T k52s5q41hk[3]; 

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T o2yo20byci[3]; /* '<S6>/Wind speed at reference height' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T glou0tzny0; /* '<S6>/ln(ref_height//z0)' */

                        
                        
                        


                    






                    
                    


                        



                            
                                   real_T jellcacuop[6]; 

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   boolean_T kjw21vg1pk; /* '<S36>/Compare' */

                        
                        
                        


                    




        } B;

                            /* Block states (default storage) for system '<Root>' */

                    
        typedef struct  {
        




                    
                    


                        



                            
                            
                                   real_T dyg4fa5n4f[9]; /* '<S51>/Product2' */

                        
                        
                        


                    






                    
                    


                        
                                    
                            
        struct {
                    void *LoggedData;
        } awyzpux4va; /* '<Root>/Scope' */
    

            



                    






                    
                    


                        



                            
                            
                                   int_T k3zlzo4rka[3]; /* '<S6>/3ft-->inf' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   int_T eyovwuix3c[3]; /* '<S4>/Limit  altitude  to troposhere' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   int_T ljats3taij[3]; /* '<S4>/Limit  altitude  to Stratosphere' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   int_T kmks0kqlp2; /* '<S35>/Abs' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   int_T nentsm3ztg; /* '<S32>/Abs1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   int_T lzyi1v2xh5; /* '<S32>/Sign1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   int_T gbjv2wu0pg; /* '<S33>/Abs' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   int8_T pyhu0x3txh; /* '<S6>/ln(h//z0)' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   int8_T n0rsg5tawa; /* '<S49>/sqrt' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   int8_T lyamxhsgtb; /* '<S44>/sqrt' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   int8_T iez3ymddrk; /* '<S6>/ln(ref_height//z0)' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   boolean_T k4tj0ddmtk; /* '<S36>/Compare' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   boolean_T i3cpbuohc4; /* '<S34>/Compare' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   boolean_T j0vp3pypgy; /* '<S37>/Compare' */

                        
                        
                        


                    




        } DW;

            
        
                /* Continuous states (default storage) */
                    typedef struct  {
                            
                        real_T e23jdsrfeo[3]; /* '<S5>/xe,ye,ze' */
                    
                    
                        real_T n5z0itpfcl[3]; /* '<S50>/phi theta psi' */
                    
                    
                        real_T ffm313ejt1[3]; /* '<S5>/p,q,r ' */
                    
                    
                        real_T igfhqv0lvj[3]; /* '<S5>/ub,vb,wb' */
                    
    
        } X;
            
                        /* Periodic continuous state vector (global) */
                            typedef int_T  PeriodicIndX[3];
        typedef real_T PeriodicRngX[6];

                                            /* State derivatives (default storage) */
                            typedef struct  {
                                
                        real_T e23jdsrfeo[3]; /* '<S5>/xe,ye,ze' */
                    
                    
                        real_T n5z0itpfcl[3]; /* '<S50>/phi theta psi' */
                    
                    
                        real_T ffm313ejt1[3]; /* '<S5>/p,q,r ' */
                    
                    
                        real_T igfhqv0lvj[3]; /* '<S5>/ub,vb,wb' */
                    
                } XDot;                        
                /* State disabled  */
                    typedef struct  {                            
                        boolean_T e23jdsrfeo[3]; /* '<S5>/xe,ye,ze' */
                    
                    
                        boolean_T n5z0itpfcl[3]; /* '<S50>/phi theta psi' */
                    
                    
                        boolean_T ffm313ejt1[3]; /* '<S5>/p,q,r ' */
                    
                    
                        boolean_T igfhqv0lvj[3]; /* '<S5>/ub,vb,wb' */
                    
            } XDis;            
        
                /* Continuous State Absolute Tolerance  */
                    typedef struct  {
                                
                            real_T e23jdsrfeo[3]; /* '<S5>/xe,ye,ze' */
                        
                        
                            real_T n5z0itpfcl[3]; /* '<S50>/phi theta psi' */
                        
                        
                            real_T ffm313ejt1[3]; /* '<S5>/p,q,r ' */
                        
                        
                            real_T igfhqv0lvj[3]; /* '<S5>/ub,vb,wb' */
                        
        
        } CStateAbsTol;
            
        
                /* Continuous State Perturb Min  */
                    typedef struct  {
                                
                            real_T e23jdsrfeo[3]; /* '<S5>/xe,ye,ze' */
                        
                        
                            real_T n5z0itpfcl[3]; /* '<S50>/phi theta psi' */
                        
                        
                            real_T ffm313ejt1[3]; /* '<S5>/p,q,r ' */
                        
                        
                            real_T igfhqv0lvj[3]; /* '<S5>/ub,vb,wb' */
                        
        
        } CXPtMin;
            
        
                /* Continuous State Perturb Max  */
                    typedef struct  {
                                
                            real_T e23jdsrfeo[3]; /* '<S5>/xe,ye,ze' */
                        
                        
                            real_T n5z0itpfcl[3]; /* '<S50>/phi theta psi' */
                        
                        
                            real_T ffm313ejt1[3]; /* '<S5>/p,q,r ' */
                        
                        
                            real_T igfhqv0lvj[3]; /* '<S5>/ub,vb,wb' */
                        
        
        } CXPtMax;
            
                        /* Zero-crossing (trigger) state */
                    typedef struct  {
                            
                            real_T lu3c55ecxf[3]; /* '<S6>/3ft-->inf' */
                            real_T axz4m0humc[3]; /* '<S6>/3ft-->inf' */
                    
                    
                            real_T mwyudkm1dy[3]; /* '<S4>/Limit  altitude  to troposhere' */
                            real_T bt0q5oi2ra[3]; /* '<S4>/Limit  altitude  to troposhere' */
                    
                    
                            real_T aw0opacu4m[3]; /* '<S4>/Limit  altitude  to Stratosphere' */
                            real_T ntoczab3l3[3]; /* '<S4>/Limit  altitude  to Stratosphere' */
                    
                    
                            real_T em3amdgmbu; /* '<S35>/Abs' */
                    
                    
                            real_T jvpprkpwgk; /* '<S36>/Compare' */
                    
                    
                            real_T m0qienrh44; /* '<S32>/Abs1' */
                    
                    
                            real_T nopzsnecq5; /* '<S34>/Compare' */
                    
                    
                            real_T hhidsenk2j; /* '<S32>/Sign1' */
                    
                    
                            real_T cle00v3zor; /* '<S33>/Abs' */
                    
                    
                            real_T h4g4pudpyw; /* '<S37>/Compare' */
                    
        
        } ZCV;
            
        /* RTWCAPI data structure for RSIM */
        typedef struct  {
        rtwCAPI_ModelMappingInfo mmi;
        } DataMapInfo;

                        /* Parameters (default storage) */
                struct P_ {
                    




                    
                    


                        



                            
                            
                                   real_T FlatEarthtoLLA_LL0[2]; /* Mask Parameter: FlatEarthtoLLA_LL0
  * Referenced by: '<S3>/ref_position'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T AerodynamicForcesandMoments_S; /* Mask Parameter: AerodynamicForcesandMoments_S
  * Referenced by: '<S2>/reference area'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T RocketBodyMotions_Vm_0[3]; /* Mask Parameter: RocketBodyMotions_Vm_0
  * Referenced by: '<S5>/ub,vb,wb'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T WindShearModel_W_20; /* Mask Parameter: WindShearModel_W_20
  * Referenced by: '<S6>/Wind speed at reference height'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T WindShearModel_Wdeg; /* Mask Parameter: WindShearModel_Wdeg
  * Referenced by: '<S6>/Wind Direction'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T CompareToConstant_const; /* Mask Parameter: CompareToConstant_const
  * Referenced by: '<S34>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T CompareToConstant_const_pwri3oqztp; /* Mask Parameter: CompareToConstant_const_pwri3oqztp
  * Referenced by: '<S36>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T CompareToConstant_const_eds1jbkaw1; /* Mask Parameter: CompareToConstant_const_eds1jbkaw1
  * Referenced by: '<S37>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T CompareToConstant_const_abt4xuk4oi; /* Mask Parameter: CompareToConstant_const_abt4xuk4oi
  * Referenced by: '<S42>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T CompareToConstant_const_nv04wgg20q; /* Mask Parameter: CompareToConstant_const_nv04wgg20q
  * Referenced by: '<S40>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T CompareToConstant_const_cbnqt4m3vq; /* Mask Parameter: CompareToConstant_const_cbnqt4m3vq
  * Referenced by: '<S43>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T RocketBodyMotions_eul_0[3]; /* Mask Parameter: RocketBodyMotions_eul_0
  * Referenced by: '<S50>/phi theta psi'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T RocketBodyMotions_pm_0[3]; /* Mask Parameter: RocketBodyMotions_pm_0
  * Referenced by: '<S5>/p,q,r '
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T FlatEarthtoLLA_psi; /* Mask Parameter: FlatEarthtoLLA_psi
  * Referenced by: '<S3>/ref_rotation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T RocketBodyMotions_xme_0[3]; /* Mask Parameter: RocketBodyMotions_xme_0
  * Referenced by: '<S5>/xe,ye,ze'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Bias_Bias; /* Expression: 180
  * Referenced by: '<S35>/Bias'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Bias1_Bias; /* Expression: -180
  * Referenced by: '<S35>/Bias1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T phithetapsi_WrappedStateUpperValue; /* Expression: pi
  * Referenced by: '<S50>/phi theta psi'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T phithetapsi_WrappedStateLowerValue; /* Expression: -pi
  * Referenced by: '<S50>/phi theta psi'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Switch_Threshold; /* Expression: 2.4
  * Referenced by: '<Root>/Switch'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T uftinf_UpperSat; /* Expression: inf
  * Referenced by: '<S6>/3ft-->inf'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T uftinf_LowerSat; /* Expression: 3
  * Referenced by: '<S6>/3ft-->inf'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T hz0_Gain; /* Expression: 1/z0
  * Referenced by: '<S6>/h//z0'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Limitaltitudetotroposhere_UpperSat; /* Expression: h_trop
  * Referenced by: '<S4>/Limit  altitude  to troposhere'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Limitaltitudetotroposhere_LowerSat; /* Expression: h0
  * Referenced by: '<S4>/Limit  altitude  to troposhere'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T LapseRate_Gain; /* Expression: L
  * Referenced by: '<S4>/Lapse Rate'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T uT0_Gain; /* Expression: 1/T0
  * Referenced by: '<S4>/1//T0'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T rho0_Gain; /* Expression: rho0
  * Referenced by: '<S4>/rho0'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T LimitaltitudetoStratosphere_UpperSat; /* Expression: 0
  * Referenced by: '<S4>/Limit  altitude  to Stratosphere'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T LimitaltitudetoStratosphere_LowerSat; /* Expression: h_trop-h_strat
  * Referenced by: '<S4>/Limit  altitude  to Stratosphere'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T gR_Gain; /* Expression: g/R
  * Referenced by: '<S4>/g//R'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant_Value; /* Expression: 0
  * Referenced by: '<S22>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant6_Value[6]; /* Expression: [0.1 0.5 1 0.2 0 0]
  * Referenced by: '<Root>/Constant6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T coefAdjust_Gain[3]; /* Expression: [1  1  1]
  * Referenced by: '<S2>/coefAdjust'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant_Value_i4rpol133v; /* Expression: 1.51
  * Referenced by: '<Root>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant3_Value; /* Expression: 1/2
  * Referenced by: '<Root>/Constant3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant4_Value[9]; /* Expression: [(1/12)*(3*(0.103)^2 + 1.41^2) 0 0; 0 (1/12)*(3*(0.103)^2 + 1.41^2) 0; 0 0 (1/2)*(0.103)^2]
  * Referenced by: '<Root>/Constant4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant5_Value; /* Expression: 9.81
  * Referenced by: '<Root>/Constant5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant_Value_ky3avngojs; /* Expression: 180
  * Referenced by: '<S28>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant1_Value; /* Expression: 0
  * Referenced by: '<S28>/Constant1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant2_Value; /* Expression: 360
  * Referenced by: '<S35>/Constant2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant_Value_gxkbwrysrc; /* Expression: 180
  * Referenced by: '<S29>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant1_Value_dgld0ymnit; /* Expression: 0
  * Referenced by: '<S29>/Constant1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Bias_Bias_dw3it2mgbt; /* Expression: 180
  * Referenced by: '<S41>/Bias'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant2_Value_njsj4azasy; /* Expression: 360
  * Referenced by: '<S41>/Constant2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Bias1_Bias_jixhqnsnsh; /* Expression: -180
  * Referenced by: '<S41>/Bias1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Bias_Bias_dzgopcrirx; /* Expression: -90
  * Referenced by: '<S38>/Bias'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain_Gain; /* Expression: -1
  * Referenced by: '<S38>/Gain'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Bias1_Bias_fmis1slqel; /* Expression: +90
  * Referenced by: '<S38>/Bias1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Bias_Bias_afrbxfkpq4; /* Expression: 180
  * Referenced by: '<S39>/Bias'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant2_Value_mbyiuuie40; /* Expression: 360
  * Referenced by: '<S39>/Constant2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Bias1_Bias_jpxdd4e1oi; /* Expression: -180
  * Referenced by: '<S39>/Bias1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant_Value_cg2fb4qko2; /* Expression: 1
  * Referenced by: '<S44>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant1_Value_f3g5vycunl; /* Expression: R
  * Referenced by: '<S44>/Constant1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant2_Value_fmjdnwbdte; /* Expression: 1
  * Referenced by: '<S44>/Constant2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant3_Value_jtpisyudw2; /* Expression: 1
  * Referenced by: '<S44>/Constant3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant_Value_k4mkjjrubk; /* Expression: 1
  * Referenced by: '<S47>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant_Value_kdka53fglp; /* Expression: 1
  * Referenced by: '<S49>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant_Value_pjdesp3rvm; /* Expression: F
  * Referenced by: '<S48>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T f_Value; /* Expression: 1
  * Referenced by: '<S48>/f'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T AltitudeofTroposphere_Value; /* Expression: h_trop
  * Referenced by: '<S4>/Altitude of Troposphere'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant_Value_f1hpxzhsax; /* Expression: g/(L*R)
  * Referenced by: '<S4>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T SeaLevelTemperature_Value; /* Expression: T0
  * Referenced by: '<S4>/Sea Level  Temperature'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Thrust_Value[3]; /* Expression: [0 0 140]
  * Referenced by: '<Root>/Thrust'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Thrust1_Value[3]; /* Expression: [0 0 0]
  * Referenced by: '<Root>/Thrust1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Wdeg1_Value; /* Expression: 0
  * Referenced by: '<S6>/Wdeg1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ref_heightz0_Value; /* Expression: 20/z0
  * Referenced by: '<S6>/ref_height//z0'
   */

                        
                        
                        


                    




                };


    

    

    
        /* External data declarations for dependent source files */
        
            extern const char_T *RT_MEMORY_ALLOCATION_ERROR;
                extern B rtB; /* block i/o */
                extern X rtX; /* states (continuous) */
                extern DW rtDW; /* states (dwork) */

            
    

                        extern                 P rtP; /* parameters */





    

                extern mxArray * mr_rocketLIBRARY_GetDWork();
            extern void mr_rocketLIBRARY_SetDWork(const mxArray* ssDW);
        extern mxArray * mr_rocketLIBRARY_GetSimStateDisallowedBlocks();


        /* Function to get C API Model Mapping Static Info */
    extern const rtwCAPI_ModelMappingStaticInfo*
    rocketLIBRARY_GetCAPIStaticMap(void);


            /* Simulation Structure */
            extern SimStruct *const rtS;



    

    

    

    

            
            /* user code (bottom of header file) */
                        extern const int_T gblNumToFiles;
            extern const int_T gblNumFrFiles;
            extern const int_T gblNumFrWksBlocks;
            extern rtInportTUtable *gblInportTUtables; 
            extern const char *gblInportFileName;
            extern const int_T gblNumRootInportBlks;
            extern const int_T gblNumModelInputs;
            extern const int_T gblInportDataTypeIdx[];
            extern const int_T gblInportDims[];         
            extern const int_T gblInportComplex[];       
            extern const int_T gblInportInterpoFlag[];   
            extern const int_T gblInportContinuous[];
            extern const int_T gblParameterTuningTid;

                extern DataMapInfo* rt_dataMapInfoPtr; 
                extern rtwCAPI_ModelMappingInfo* rt_modelMapInfoPtr;

            void MdlOutputs(int_T tid);
            void MdlOutputsParameterSampleTime(int_T tid);
            void MdlUpdate(int_T tid);
            void MdlTerminate(void);
            void MdlInitializeSizes(void);
            void MdlInitializeSampleTimes(void);
            SimStruct * raccel_register_model(ssExecutionInfo* executionInfo);




    #endif /* RTW_HEADER_rocketLIBRARY_h_ */
