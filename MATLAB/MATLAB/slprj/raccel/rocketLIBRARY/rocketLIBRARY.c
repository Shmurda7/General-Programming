

    

        /*
        * rocketLIBRARY.c
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




    
#include "rocketLIBRARY.h"

#include "rtwtypes.h"

#include "mwmathutil.h"

#include "rocketLIBRARY_private.h"

#include <string.h>

#include "rt_logging_mmi.h"

#include "rocketLIBRARY_capi.h"

    #include "rocketLIBRARY_dt.h"
        
            /* user code (top of parameter file) */
            









        extern void* CreateDiagnosticAsVoidPtr_wrapper(const char* id, int nargs, ...);
        RTWExtModeInfo* gblRTWExtModeInfo = NULL;

        void raccelForceExtModeShutdown(boolean_T extModeStartPktReceived)
        {
            if (!extModeStartPktReceived) 
            { 
                boolean_T stopRequested = false;
                rtExtModeWaitForStartPkt(gblRTWExtModeInfo, 3, &stopRequested); 
            } 
            
            rtExtModeShutdown(3); 
        }

            #include "slsv_diagnostic_codegen_c_api.h"
            #include "slsa_sim_engine.h"
            const int_T gblNumToFiles = 0;
            const int_T gblNumFrFiles = 0;
            const int_T gblNumFrWksBlocks = 0;

            #ifdef RSIM_WITH_SOLVER_MULTITASKING
            boolean_T gbl_raccel_isMultitasking = 1;
            #else
            boolean_T gbl_raccel_isMultitasking = 0;
            #endif

            boolean_T gbl_raccel_tid01eq = 0;
            int_T gbl_raccel_NumST = 4;
            const char_T *gbl_raccel_Version = "9.9 (R2023a) 19-Nov-2022";
            
            void raccel_setup_MMIStateLog(SimStruct* S){
                #ifdef UseMMIDataLogging
                rt_FillStateSigInfoFromMMI(ssGetRTWLogInfo(S),&ssGetErrorStatus(S));
                #else
                UNUSED_PARAMETER(S);
                #endif
            }

                static DataMapInfo  rt_dataMapInfo;
                DataMapInfo* rt_dataMapInfoPtr = &rt_dataMapInfo;
                rtwCAPI_ModelMappingInfo* rt_modelMapInfoPtr = &(rt_dataMapInfo.mmi);
            

                /* Root inports information  */
                const int_T gblNumRootInportBlks = 0;
                const int_T gblNumModelInputs    = 0;
                extern const char *gblInportFileName;
                extern rtInportTUtable *gblInportTUtables; 

                
                
                
                const int_T gblInportDataTypeIdx[]   = {-1};
                const int_T gblInportDims[]          = {-1} ;                   
                const int_T gblInportComplex[]       = {-1};
                const int_T gblInportInterpoFlag[]   = {-1};    
                const int_T gblInportContinuous[]    = {-1};

                int_T enableFcnCallFlag[]   = {1, 1, 1, 1};
                
                    const char* raccelLoadInputsAndAperiodicHitTimes(SimStruct* S,
                    const char* inportFileName,
                    int* matFileFormat) {
                        return rt_RAccelReadInportsMatFile(S, inportFileName, matFileFormat);
                    }

            

            #include "simstruc.h"
            #include "fixedpoint.h"
                #include "slsa_sim_engine.h"
                #include "simtarget/slSimTgtSLExecSimBridge.h"


    

    

    

    

    

    

    

    

    

    

    
        /* Block signals (default storage) */
                                            B rtB;

            
        /* Continuous states */
                            X rtX;

    
            /* Block states (default storage) */
                                            DW rtDW;

            
    




            
        
        
        
        
        
        

        

        

        /* Periodic continuous states */
                                PeriodicIndX rtPeriodicIndX;

                PeriodicRngX rtPeriodicRngX;

                


            /* Parent Simstruct */
            static SimStruct model_S;
            SimStruct *const rtS = &model_S;


    

    

    

    

            





    

                                                                        

                        

                

        

            
                void rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(const real_T u0[3], const real_T u1[9], real_T y[3])
        {
            real_T A[9];
real_T a21;
real_T maxval;
int32_T r1;
int32_T r2;
int32_T r3;
int32_T rtemp;
memcpy(&A[0], &u1[0], 9U * sizeof(real_T));
r1 = 0;
r2 = 1;
r3 = 2;
maxval = muDoubleScalarAbs(u1[0]);
a21 = muDoubleScalarAbs(u1[1]);
if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
}
if (muDoubleScalarAbs(u1[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
}
A[r2] = u1[r2] / u1[r1];
A[r3] /= A[r1];
A[r2 + 3] -= A[r1 + 3] * A[r2];
A[r3 + 3] -= A[r1 + 3] * A[r3];
A[r2 + 6] -= A[r1 + 6] * A[r2];
A[r3 + 6] -= A[r1 + 6] * A[r3];
if (muDoubleScalarAbs(A[r3 + 3]) > muDoubleScalarAbs(A[r2 + 3])) {
    rtemp = r2 + 1;
    r2 = r3;
    r3 = rtemp - 1;
}
A[r3 + 3] /= A[r2 + 3];
A[r3 + 6] -= A[r3 + 3] * A[r2 + 6];
y[r1] = u0[0] / A[r1];
y[r2] = u0[1] - A[r1 + 3] * y[r1];
y[r3] = u0[2] - A[r1 + 6] * y[r1];
y[r2] /= A[r2 + 3];
y[r3] -= A[r2 + 6] * y[r2];
y[r3] /= A[r3 + 6];
y[r2] -= A[r3 + 3] * y[r3];
y[r1] -= y[r3] * A[r3];
y[r1] -= y[r2] * A[r2];


        }
            

            

            
        
                            
                

        


          void MdlInitialize(void)
    {
    
                
    
    




                                    




                                                
                                    



rtX.e23jdsrfeo[0] = rtP.RocketBodyMotions_xme_0[0];
rtX.n5z0itpfcl[0] = rtP.RocketBodyMotions_eul_0[0];
rtX.ffm313ejt1[0] = rtP.RocketBodyMotions_pm_0[0];
rtX.igfhqv0lvj[0] = rtP.RocketBodyMotions_Vm_0[0];
rtX.e23jdsrfeo[1] = rtP.RocketBodyMotions_xme_0[1];
rtX.n5z0itpfcl[1] = rtP.RocketBodyMotions_eul_0[1];
rtX.ffm313ejt1[1] = rtP.RocketBodyMotions_pm_0[1];
rtX.igfhqv0lvj[1] = rtP.RocketBodyMotions_Vm_0[1];
rtX.e23jdsrfeo[2] = rtP.RocketBodyMotions_xme_0[2];
rtX.n5z0itpfcl[2] = rtP.RocketBodyMotions_eul_0[2];
rtX.ffm313ejt1[2] = rtP.RocketBodyMotions_pm_0[2];
rtX.igfhqv0lvj[2] = rtP.RocketBodyMotions_Vm_0[2];

            /* InitializeConditions for root-level periodic continuous states */
            {
                int_T rootPeriodicContStateIndices[3] = {                        3                        , 4                        , 5                };
                real_T rootPeriodicContStateRanges[6] = {                        -3.1415926535897931                        , 3.1415926535897931                        , -3.1415926535897931                        , 3.1415926535897931                        , -3.1415926535897931                        , 3.1415926535897931                };

                (void) memcpy((void*)rtPeriodicIndX, rootPeriodicContStateIndices,
3*sizeof(int_T));

                (void) memcpy((void*)rtPeriodicRngX, rootPeriodicContStateRanges,
6*sizeof(real_T));
            }






    




                            }
        


                            
                

        


          void MdlStart(void)
    {
    
                
    
    




                                                    
    
    
    
    
    
    {
        bool externalInputIsInDatasetFormat = false; 
        void *pISigstreamManager = rt_GetISigstreamManager(rtS);
        rtwISigstreamManagerGetInputIsInDatasetFormat( pISigstreamManager, &externalInputIsInDatasetFormat );
        if (externalInputIsInDatasetFormat) {
        }

    }

        
        
        
    




                                                
                                    rtDW.n0rsg5tawa = 0;
rtDW.lyamxhsgtb = 0;
rtDW.iez3ymddrk = 0;
rtDW.pyhu0x3txh = 0;




    




                                MdlInitialize();
        
            }
        


            
        


                    
            
                    

        


          void MdlOutputs(int_T tid)
    {
    
                                                /* local scratch DWork variables */
                                

                                int32_T dzyocmumow;

                
                


        
real_T c2g3f2ksqa_idx_0;
real_T c2g3f2ksqa_idx_1;
real_T c2g3f2ksqa_idx_2;
real_T eubyht22ph_idx_0;
real_T eubyht22ph_idx_1;
real_T eubyht22ph_idx_2;
real_T fmmgro5a3o_idx_1;
real_T fmmgro5a3o_idx_2;
real_T irz13ngnad;
int32_T i;

    




                                

        
        
    




                
                                    
                
                                    









irz13ngnad = ssGetT(rtS);
rtB.p0shvkceq5[0] = rtX.e23jdsrfeo[0];
rtB.gmtjwxhcc4[0] = rtX.n5z0itpfcl[0];
if (irz13ngnad > rtP.Switch_Threshold) {
    rtB.ntqzzqi1dc[0] = rtP.Thrust1_Value[0];
    rtB.ntqzzqi1dc[1] = rtP.Thrust1_Value[1];
} else {
    rtB.ntqzzqi1dc[0] = rtP.Thrust_Value[0];
    rtB.ntqzzqi1dc[1] = rtP.Thrust_Value[1];
}
rtB.p0shvkceq5[1] = rtX.e23jdsrfeo[1];
rtB.gmtjwxhcc4[1] = rtX.n5z0itpfcl[1];
rtB.p0shvkceq5[2] = rtX.e23jdsrfeo[2];
rtB.gmtjwxhcc4[2] = rtX.n5z0itpfcl[2];
if (irz13ngnad > rtP.Switch_Threshold) {
    rtB.ntqzzqi1dc[2] = rtP.Thrust1_Value[2];
} else {
    rtB.ntqzzqi1dc[2] = rtP.Thrust_Value[2];
}
rtB.gsdo2pjwzd = rtB.ntqzzqi1dc[2] - rtB.hcxyo5x1fp;
rtB.bvik5bxnsw[0] = rtB.gmtjwxhcc4[2];
rtB.bvik5bxnsw[1] = rtB.gmtjwxhcc4[1];
rtB.bvik5bxnsw[2] = rtB.gmtjwxhcc4[0];
/* Unit Conversion - from: m to: ft
 Expression: output = (3.28084*input) + (0) */
muDoubleScalarSinCos(rtB.bvik5bxnsw[0], &eubyht22ph_idx_0, &irz13ngnad);
rtB.eenfrxbcez[0] = rtB.p0shvkceq5[0] * rtB.p0shvkceq5[0] * 3.280839895013123;
muDoubleScalarSinCos(rtB.bvik5bxnsw[1], &eubyht22ph_idx_1, &fmmgro5a3o_idx_1);
rtB.eenfrxbcez[1] = rtB.p0shvkceq5[1] * rtB.p0shvkceq5[1] * 3.280839895013123;
muDoubleScalarSinCos(rtB.bvik5bxnsw[2], &eubyht22ph_idx_2, &fmmgro5a3o_idx_2);
rtB.eenfrxbcez[2] = rtB.p0shvkceq5[2] * rtB.p0shvkceq5[2] * 3.280839895013123;
rtB.nxlaprucin[0] = irz13ngnad * fmmgro5a3o_idx_1;
rtB.nxlaprucin[1] = eubyht22ph_idx_1 * eubyht22ph_idx_2 * irz13ngnad - eubyht22ph_idx_0 * fmmgro5a3o_idx_2;
rtB.nxlaprucin[2] = eubyht22ph_idx_1 * fmmgro5a3o_idx_2 * irz13ngnad + eubyht22ph_idx_0 * eubyht22ph_idx_2;
rtB.nxlaprucin[3] = eubyht22ph_idx_0 * fmmgro5a3o_idx_1;
rtB.nxlaprucin[4] = eubyht22ph_idx_1 * eubyht22ph_idx_2 * eubyht22ph_idx_0 + irz13ngnad * fmmgro5a3o_idx_2;
rtB.nxlaprucin[5] = eubyht22ph_idx_1 * fmmgro5a3o_idx_2 * eubyht22ph_idx_0 - irz13ngnad * eubyht22ph_idx_2;
rtB.nxlaprucin[6] = -eubyht22ph_idx_1;
rtB.nxlaprucin[7] = fmmgro5a3o_idx_1 * eubyht22ph_idx_2;
rtB.nxlaprucin[8] = fmmgro5a3o_idx_1 * fmmgro5a3o_idx_2;
if (ssIsModeUpdateTimeStep(rtS)) {
    rtDW.k3zlzo4rka[0] = rtB.eenfrxbcez[0] >= rtP.uftinf_UpperSat ? 1 : rtB.eenfrxbcez[0] > rtP.uftinf_LowerSat ? 0 : -1;
    rtDW.k3zlzo4rka[1] = rtB.eenfrxbcez[1] >= rtP.uftinf_UpperSat ? 1 : rtB.eenfrxbcez[1] > rtP.uftinf_LowerSat ? 0 : -1;
    rtDW.k3zlzo4rka[2] = rtB.eenfrxbcez[2] >= rtP.uftinf_UpperSat ? 1 : rtB.eenfrxbcez[2] > rtP.uftinf_LowerSat ? 0 : -1;
}
eubyht22ph_idx_2 = rtDW.k3zlzo4rka[0] == 1 ? rtP.uftinf_UpperSat : rtDW.k3zlzo4rka[0] == -1 ? rtP.uftinf_LowerSat : rtB.eenfrxbcez[0];
rtB.kzzs5lii4k[0] = eubyht22ph_idx_2;
fmmgro5a3o_idx_2 = rtP.hz0_Gain * eubyht22ph_idx_2;
rtB.hndudxkdvr[0] = fmmgro5a3o_idx_2;
irz13ngnad = fmmgro5a3o_idx_2;
eubyht22ph_idx_2 = rtDW.k3zlzo4rka[1] == 1 ? rtP.uftinf_UpperSat : rtDW.k3zlzo4rka[1] == -1 ? rtP.uftinf_LowerSat : rtB.eenfrxbcez[1];
rtB.kzzs5lii4k[1] = eubyht22ph_idx_2;
fmmgro5a3o_idx_2 = rtP.hz0_Gain * eubyht22ph_idx_2;
rtB.hndudxkdvr[1] = fmmgro5a3o_idx_2;
fmmgro5a3o_idx_1 = fmmgro5a3o_idx_2;
eubyht22ph_idx_2 = rtDW.k3zlzo4rka[2] == 1 ? rtP.uftinf_UpperSat : rtDW.k3zlzo4rka[2] == -1 ? rtP.uftinf_LowerSat : rtB.eenfrxbcez[2];
rtB.kzzs5lii4k[2] = eubyht22ph_idx_2;
fmmgro5a3o_idx_2 = rtP.hz0_Gain * eubyht22ph_idx_2;
rtB.hndudxkdvr[2] = fmmgro5a3o_idx_2;
if (ssIsMajorTimeStep(rtS)) {
    if (rtDW.pyhu0x3txh != 0) {
        ssSetBlockStateForSolverChangedAtMajorStep(rtS);
        ssSetContTimeOutputInconsistentWithStateAtMajorStep(rtS);
        rtDW.pyhu0x3txh = 0;
    }
} else {
    if (irz13ngnad < 0.0) {
        irz13ngnad = 0.0;
        rtDW.pyhu0x3txh = 1;
    }
    if (fmmgro5a3o_idx_1 < 0.0) {
        fmmgro5a3o_idx_1 = 0.0;
        rtDW.pyhu0x3txh = 1;
    }
    if (fmmgro5a3o_idx_2 < 0.0) {
        fmmgro5a3o_idx_2 = 0.0;
        rtDW.pyhu0x3txh = 1;
    }
}
irz13ngnad = muDoubleScalarLog(irz13ngnad) / rtB.glou0tzny0;
rtB.fvn3vgbif3[0] = irz13ngnad;
rtB.jes3bzaku0[0] = irz13ngnad * rtB.o2yo20byci[0];
irz13ngnad = muDoubleScalarLog(fmmgro5a3o_idx_1) / rtB.glou0tzny0;
rtB.fvn3vgbif3[1] = irz13ngnad;
rtB.jes3bzaku0[1] = irz13ngnad * rtB.o2yo20byci[1];
irz13ngnad = muDoubleScalarLog(fmmgro5a3o_idx_2) / rtB.glou0tzny0;
rtB.fvn3vgbif3[2] = irz13ngnad;
rtB.jes3bzaku0[2] = irz13ngnad * rtB.o2yo20byci[2];
irz13ngnad = rtB.jes3bzaku0[1];
eubyht22ph_idx_2 = rtB.jes3bzaku0[0];
fmmgro5a3o_idx_1 = rtB.jes3bzaku0[2];
for (i = 0; i < 3; i++) {
    rtB.nz4yxh1qfq[i] = (rtB.nxlaprucin[i + 3] * irz13ngnad + rtB.nxlaprucin[i] * eubyht22ph_idx_2) + rtB.nxlaprucin[i + 6] * fmmgro5a3o_idx_1;
}
if (ssIsModeUpdateTimeStep(rtS)) {
    rtDW.eyovwuix3c[0] = rtB.p0shvkceq5[0] >= rtP.Limitaltitudetotroposhere_UpperSat ? 1 : rtB.p0shvkceq5[0] > rtP.Limitaltitudetotroposhere_LowerSat ? 0 : -1;
    rtDW.eyovwuix3c[1] = rtB.p0shvkceq5[1] >= rtP.Limitaltitudetotroposhere_UpperSat ? 1 : rtB.p0shvkceq5[1] > rtP.Limitaltitudetotroposhere_LowerSat ? 0 : -1;
    rtDW.eyovwuix3c[2] = rtB.p0shvkceq5[2] >= rtP.Limitaltitudetotroposhere_UpperSat ? 1 : rtB.p0shvkceq5[2] > rtP.Limitaltitudetotroposhere_LowerSat ? 0 : -1;
}
irz13ngnad = rtDW.eyovwuix3c[0] == 1 ? rtP.Limitaltitudetotroposhere_UpperSat : rtDW.eyovwuix3c[0] == -1 ? rtP.Limitaltitudetotroposhere_LowerSat : rtB.p0shvkceq5[0];
rtB.pzpb0aaq1i[0] = irz13ngnad;
irz13ngnad *= rtP.LapseRate_Gain;
rtB.az30op0bz1[0] = irz13ngnad;
irz13ngnad = rtP.SeaLevelTemperature_Value - irz13ngnad;
rtB.djlhbobpcq[0] = irz13ngnad;
rtB.efsisy4fdx[0] = rtP.uT0_Gain * irz13ngnad;
if ((rtB.efsisy4fdx[0] < 0.0) && (rtP.Constant_Value_f1hpxzhsax > muDoubleScalarFloor(rtP.Constant_Value_f1hpxzhsax))) {
    fmmgro5a3o_idx_1 = -muDoubleScalarPower(-rtB.efsisy4fdx[0], rtP.Constant_Value_f1hpxzhsax);
} else {
    fmmgro5a3o_idx_1 = muDoubleScalarPower(rtB.efsisy4fdx[0], rtP.Constant_Value_f1hpxzhsax);
}
irz13ngnad = fmmgro5a3o_idx_1 / rtB.efsisy4fdx[0];
rtB.pocvhehxoq[0] = irz13ngnad;
rtB.frtaiwzqi5[0] = rtP.rho0_Gain * irz13ngnad;
rtB.gx2bnlk0lw[0] = rtP.AltitudeofTroposphere_Value - rtB.p0shvkceq5[0];
irz13ngnad = rtDW.eyovwuix3c[1] == 1 ? rtP.Limitaltitudetotroposhere_UpperSat : rtDW.eyovwuix3c[1] == -1 ? rtP.Limitaltitudetotroposhere_LowerSat : rtB.p0shvkceq5[1];
rtB.pzpb0aaq1i[1] = irz13ngnad;
irz13ngnad *= rtP.LapseRate_Gain;
rtB.az30op0bz1[1] = irz13ngnad;
irz13ngnad = rtP.SeaLevelTemperature_Value - irz13ngnad;
rtB.djlhbobpcq[1] = irz13ngnad;
rtB.efsisy4fdx[1] = rtP.uT0_Gain * irz13ngnad;
if ((rtB.efsisy4fdx[1] < 0.0) && (rtP.Constant_Value_f1hpxzhsax > muDoubleScalarFloor(rtP.Constant_Value_f1hpxzhsax))) {
    fmmgro5a3o_idx_1 = -muDoubleScalarPower(-rtB.efsisy4fdx[1], rtP.Constant_Value_f1hpxzhsax);
} else {
    fmmgro5a3o_idx_1 = muDoubleScalarPower(rtB.efsisy4fdx[1], rtP.Constant_Value_f1hpxzhsax);
}
irz13ngnad = fmmgro5a3o_idx_1 / rtB.efsisy4fdx[1];
rtB.pocvhehxoq[1] = irz13ngnad;
rtB.frtaiwzqi5[1] = rtP.rho0_Gain * irz13ngnad;
rtB.gx2bnlk0lw[1] = rtP.AltitudeofTroposphere_Value - rtB.p0shvkceq5[1];
irz13ngnad = rtDW.eyovwuix3c[2] == 1 ? rtP.Limitaltitudetotroposhere_UpperSat : rtDW.eyovwuix3c[2] == -1 ? rtP.Limitaltitudetotroposhere_LowerSat : rtB.p0shvkceq5[2];
rtB.pzpb0aaq1i[2] = irz13ngnad;
irz13ngnad *= rtP.LapseRate_Gain;
rtB.az30op0bz1[2] = irz13ngnad;
irz13ngnad = rtP.SeaLevelTemperature_Value - irz13ngnad;
rtB.djlhbobpcq[2] = irz13ngnad;
rtB.efsisy4fdx[2] = rtP.uT0_Gain * irz13ngnad;
if ((rtB.efsisy4fdx[2] < 0.0) && (rtP.Constant_Value_f1hpxzhsax > muDoubleScalarFloor(rtP.Constant_Value_f1hpxzhsax))) {
    fmmgro5a3o_idx_1 = -muDoubleScalarPower(-rtB.efsisy4fdx[2], rtP.Constant_Value_f1hpxzhsax);
} else {
    fmmgro5a3o_idx_1 = muDoubleScalarPower(rtB.efsisy4fdx[2], rtP.Constant_Value_f1hpxzhsax);
}
irz13ngnad = fmmgro5a3o_idx_1 / rtB.efsisy4fdx[2];
rtB.pocvhehxoq[2] = irz13ngnad;
rtB.frtaiwzqi5[2] = rtP.rho0_Gain * irz13ngnad;
rtB.gx2bnlk0lw[2] = rtP.AltitudeofTroposphere_Value - rtB.p0shvkceq5[2];
if (ssIsModeUpdateTimeStep(rtS)) {
    rtDW.ljats3taij[0] = rtB.gx2bnlk0lw[0] >= rtP.LimitaltitudetoStratosphere_UpperSat ? 1 : rtB.gx2bnlk0lw[0] > rtP.LimitaltitudetoStratosphere_LowerSat ? 0 : -1;
    rtDW.ljats3taij[1] = rtB.gx2bnlk0lw[1] >= rtP.LimitaltitudetoStratosphere_UpperSat ? 1 : rtB.gx2bnlk0lw[1] > rtP.LimitaltitudetoStratosphere_LowerSat ? 0 : -1;
    rtDW.ljats3taij[2] = rtB.gx2bnlk0lw[2] >= rtP.LimitaltitudetoStratosphere_UpperSat ? 1 : rtB.gx2bnlk0lw[2] > rtP.LimitaltitudetoStratosphere_LowerSat ? 0 : -1;
}
irz13ngnad = rtDW.ljats3taij[0] == 1 ? rtP.LimitaltitudetoStratosphere_UpperSat : rtDW.ljats3taij[0] == -1 ? rtP.LimitaltitudetoStratosphere_LowerSat : rtB.gx2bnlk0lw[0];
rtB.bbyymkm3vn[0] = irz13ngnad;
irz13ngnad *= rtP.gR_Gain;
rtB.gus0dwpmta[0] = irz13ngnad;
rtB.ons4nt2sr3[0] = 1.0 / rtB.djlhbobpcq[0] * irz13ngnad;
irz13ngnad = rtB.frtaiwzqi5[0] * muDoubleScalarExp(rtB.ons4nt2sr3[0]);
rtB.cs1icxkpbk[0] = irz13ngnad;
irz13ngnad *= rtB.nz4yxh1qfq[0] * rtP.Constant3_Value;
rtB.eweodspclo[0] = irz13ngnad;
irz13ngnad *= rtP.AerodynamicForcesandMoments_S;
rtB.beqzc5bw0r[0] = irz13ngnad;
rtB.ppbw2ujmty[0] = irz13ngnad * rtB.czkarcoix3[0];
irz13ngnad = rtDW.ljats3taij[1] == 1 ? rtP.LimitaltitudetoStratosphere_UpperSat : rtDW.ljats3taij[1] == -1 ? rtP.LimitaltitudetoStratosphere_LowerSat : rtB.gx2bnlk0lw[1];
rtB.bbyymkm3vn[1] = irz13ngnad;
irz13ngnad *= rtP.gR_Gain;
rtB.gus0dwpmta[1] = irz13ngnad;
rtB.ons4nt2sr3[1] = 1.0 / rtB.djlhbobpcq[1] * irz13ngnad;
irz13ngnad = rtB.frtaiwzqi5[1] * muDoubleScalarExp(rtB.ons4nt2sr3[1]);
rtB.cs1icxkpbk[1] = irz13ngnad;
irz13ngnad *= rtB.nz4yxh1qfq[1] * rtP.Constant3_Value;
rtB.eweodspclo[1] = irz13ngnad;
irz13ngnad *= rtP.AerodynamicForcesandMoments_S;
rtB.beqzc5bw0r[1] = irz13ngnad;
rtB.ppbw2ujmty[1] = irz13ngnad * rtB.czkarcoix3[1];
irz13ngnad = rtDW.ljats3taij[2] == 1 ? rtP.LimitaltitudetoStratosphere_UpperSat : rtDW.ljats3taij[2] == -1 ? rtP.LimitaltitudetoStratosphere_LowerSat : rtB.gx2bnlk0lw[2];
rtB.bbyymkm3vn[2] = irz13ngnad;
irz13ngnad *= rtP.gR_Gain;
rtB.gus0dwpmta[2] = irz13ngnad;
rtB.ons4nt2sr3[2] = 1.0 / rtB.djlhbobpcq[2] * irz13ngnad;
irz13ngnad = rtB.frtaiwzqi5[2] * muDoubleScalarExp(rtB.ons4nt2sr3[2]);
rtB.cs1icxkpbk[2] = irz13ngnad;
irz13ngnad *= rtB.nz4yxh1qfq[2] * rtP.Constant3_Value;
rtB.eweodspclo[2] = irz13ngnad;
irz13ngnad *= rtP.AerodynamicForcesandMoments_S;
rtB.beqzc5bw0r[2] = irz13ngnad;
rtB.ppbw2ujmty[2] = irz13ngnad * rtB.czkarcoix3[2];
rtB.a5kvjjzqcc[0] = rtB.ntqzzqi1dc[0] - rtB.ppbw2ujmty[0];
rtB.a5kvjjzqcc[1] = rtB.ntqzzqi1dc[1] - rtB.ppbw2ujmty[1];
rtB.a5kvjjzqcc[2] = rtB.gsdo2pjwzd - rtB.ppbw2ujmty[2];

/* Unit Conversion - from: rad to: deg
 Expression: output = (57.2958*input) + (0) */
rtB.ltespdje45[0] = (rtB.p0shvkceq5[0] * rtB.pq2n04xswi - rtB.p0shvkceq5[1] * rtB.legy4gcyuq) * rtB.o0lznmwy04 * 57.295779513082323 + rtB.idzov0xqov;
rtB.ltespdje45[1] = (rtB.p0shvkceq5[0] * rtB.legy4gcyuq + rtB.p0shvkceq5[1] * rtB.pq2n04xswi) * rtB.frkjltmijt * 57.295779513082323 + rtB.kf3nkdp1sm;
if (ssIsModeUpdateTimeStep(rtS)) {
    rtDW.kmks0kqlp2 = (rtB.ltespdje45[0] >= 0.0);
}
rtB.f3grp50dae = rtDW.kmks0kqlp2 > 0 ? rtB.ltespdje45[0] : -rtB.ltespdje45[0];
if (ssIsSampleHit(rtS, 1, 0)) {
    if (ssIsModeUpdateTimeStep(rtS)) {
        rtDW.k4tj0ddmtk = (rtB.f3grp50dae > rtP.CompareToConstant_const_pwri3oqztp);
    }
    rtB.kjw21vg1pk = rtDW.k4tj0ddmtk;
}
if (rtB.kjw21vg1pk) {
    rtB.a4vnpcfi1i = muDoubleScalarMod(rtB.ltespdje45[0] + rtP.Bias_Bias, rtP.Constant2_Value) + rtP.Bias1_Bias;
} else {
    rtB.a4vnpcfi1i = rtB.ltespdje45[0];
}
if (ssIsModeUpdateTimeStep(rtS)) {
    rtDW.nentsm3ztg = (rtB.a4vnpcfi1i >= 0.0);
}
rtB.cnuqgk0ctt = rtDW.nentsm3ztg > 0 ? rtB.a4vnpcfi1i : -rtB.a4vnpcfi1i;
if (ssIsSampleHit(rtS, 1, 0)) {
    if (ssIsModeUpdateTimeStep(rtS)) {
        rtDW.i3cpbuohc4 = (rtB.cnuqgk0ctt > rtP.CompareToConstant_const);
    }
    if (rtB.a4vnpcfi1i > 0.0) {
        rtDW.lzyi1v2xh5 = 1;
    } else if (rtB.a4vnpcfi1i < 0.0) {
        rtDW.lzyi1v2xh5 = -1;
    } else {
        rtDW.lzyi1v2xh5 = 0;
    }
    if (rtDW.i3cpbuohc4) {
        rtB.apnu1iub5y = rtP.Constant_Value_ky3avngojs;
    } else {
        rtB.apnu1iub5y = rtP.Constant1_Value;
    }
}
rtB.bzbu3yseb2 = rtB.apnu1iub5y + rtB.ltespdje45[1];
if (ssIsModeUpdateTimeStep(rtS)) {
    rtDW.gbjv2wu0pg = (rtB.bzbu3yseb2 >= 0.0);
}
rtB.dekfyvtcle = rtDW.gbjv2wu0pg > 0 ? rtB.bzbu3yseb2 : -rtB.bzbu3yseb2;
if (ssIsSampleHit(rtS, 1, 0) && ssIsModeUpdateTimeStep(rtS)) {
    rtDW.j0vp3pypgy = (rtB.dekfyvtcle > rtP.CompareToConstant_const_eds1jbkaw1);
}
rtB.p1cjwgdban[0] = rtX.ffm313ejt1[0];
muDoubleScalarSinCos(rtB.gmtjwxhcc4[0], &irz13ngnad, &eubyht22ph_idx_0);
rtB.p1cjwgdban[1] = rtX.ffm313ejt1[1];
muDoubleScalarSinCos(rtB.gmtjwxhcc4[1], &fmmgro5a3o_idx_1, &eubyht22ph_idx_1);
rtB.p1cjwgdban[2] = rtX.ffm313ejt1[2];
rtB.jrvb2m0kwj[0] = (irz13ngnad * rtB.p1cjwgdban[1] + eubyht22ph_idx_0 * rtB.p1cjwgdban[2]) * (fmmgro5a3o_idx_1 / eubyht22ph_idx_1) + rtB.p1cjwgdban[0];
rtB.jrvb2m0kwj[1] = eubyht22ph_idx_0 * rtB.p1cjwgdban[1] - irz13ngnad * rtB.p1cjwgdban[2];
rtB.jrvb2m0kwj[2] = (irz13ngnad * rtB.p1cjwgdban[1] + eubyht22ph_idx_0 * rtB.p1cjwgdban[2]) / eubyht22ph_idx_1;
irz13ngnad = rtB.p1cjwgdban[1];
eubyht22ph_idx_0 = rtB.p1cjwgdban[0];
eubyht22ph_idx_1 = rtB.p1cjwgdban[2];
for (i = 0; i < 3; i++) {
    rtB.gaqfxcn5mu[i] = (rtB.i4ejkbvukm[i + 3] * irz13ngnad + rtB.i4ejkbvukm[i] * eubyht22ph_idx_0) + rtB.i4ejkbvukm[i + 6] * eubyht22ph_idx_1;
    rtB.mplveaosnc[i] = (rtB.mqmfqguhsp[i + 3] * irz13ngnad + rtB.mqmfqguhsp[i] * eubyht22ph_idx_0) + rtB.mqmfqguhsp[i + 6] * eubyht22ph_idx_1;
}
rtB.fq0udmcr0d = rtB.p1cjwgdban[0] * rtB.mplveaosnc[1];
rtB.i25dx5gfjj = rtB.p1cjwgdban[1] * rtB.mplveaosnc[2];
rtB.azigzyu2ua = rtB.mplveaosnc[0] * rtB.p1cjwgdban[2];
rtB.osmqo5ipx2 = rtB.p1cjwgdban[0] * rtB.mplveaosnc[2];
rtB.mxurwdq3rp = rtB.mplveaosnc[0] * rtB.p1cjwgdban[1];
rtB.n5my3rkxnx = rtB.mplveaosnc[1] * rtB.p1cjwgdban[2];
rtB.h4mpthrjzj[0] = rtB.i25dx5gfjj - rtB.n5my3rkxnx;
rtB.h4mpthrjzj[1] = rtB.azigzyu2ua - rtB.osmqo5ipx2;
rtB.h4mpthrjzj[2] = rtB.fq0udmcr0d - rtB.mxurwdq3rp;
rtB.fpj41u20a1[0] = (0.0 - rtB.gaqfxcn5mu[0]) - rtB.h4mpthrjzj[0];
rtB.fpj41u20a1[1] = (0.0 - rtB.gaqfxcn5mu[1]) - rtB.h4mpthrjzj[1];
rtB.fpj41u20a1[2] = (0.0 - rtB.gaqfxcn5mu[2]) - rtB.h4mpthrjzj[2];
rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(rtB.fpj41u20a1, rtB.a2i2fdw0sz, rtB.hdpsy3sguu);
for (dzyocmumow = 0; dzyocmumow < 1; dzyocmumow++) {
    if (ssIsSampleHit(rtS, 1, 0)) {
        i = dzyocmumow * 3;
        c2g3f2ksqa_idx_0 = 0.0 * rtB.k52s5q41hk[i];
        c2g3f2ksqa_idx_1 = rtB.k52s5q41hk[i + 1] * 0.0;
        c2g3f2ksqa_idx_2 = rtB.k52s5q41hk[i + 2] * 0.0;
    }
}
if (ssIsSampleHit(rtS, 1, 0)) {
    rtB.ivl5z2vmyi[0] = c2g3f2ksqa_idx_0;
    rtB.ivl5z2vmyi[1] = c2g3f2ksqa_idx_1;
    rtB.ivl5z2vmyi[2] = c2g3f2ksqa_idx_2;
}
c2g3f2ksqa_idx_0 = rtB.a5kvjjzqcc[0] + rtB.ivl5z2vmyi[0];
rtB.pjxjfknbqz[0] = c2g3f2ksqa_idx_0;
rtB.k0esd4omu2[0] = c2g3f2ksqa_idx_0 / rtP.Constant_Value_i4rpol133v;
rtB.grafq4xnvz[0] = rtX.igfhqv0lvj[0];
c2g3f2ksqa_idx_0 = rtB.a5kvjjzqcc[1] + rtB.ivl5z2vmyi[1];
rtB.pjxjfknbqz[1] = c2g3f2ksqa_idx_0;
rtB.k0esd4omu2[1] = c2g3f2ksqa_idx_0 / rtP.Constant_Value_i4rpol133v;
rtB.grafq4xnvz[1] = rtX.igfhqv0lvj[1];
c2g3f2ksqa_idx_0 = rtB.a5kvjjzqcc[2] + rtB.ivl5z2vmyi[2];
rtB.pjxjfknbqz[2] = c2g3f2ksqa_idx_0;
rtB.k0esd4omu2[2] = c2g3f2ksqa_idx_0 / rtP.Constant_Value_i4rpol133v;
rtB.grafq4xnvz[2] = rtX.igfhqv0lvj[2];
rtB.czqbao5rcr = rtB.grafq4xnvz[1] * rtB.p1cjwgdban[2];
rtB.ds0u1ctsfa = rtB.p1cjwgdban[0] * rtB.grafq4xnvz[2];
rtB.mbnstg1xrg = rtB.grafq4xnvz[0] * rtB.p1cjwgdban[1];
rtB.jwmr4335zo = rtB.p1cjwgdban[1] * rtB.grafq4xnvz[2];
rtB.mgaxq1x2cb = rtB.grafq4xnvz[0] * rtB.p1cjwgdban[2];
rtB.cjk455jyf1 = rtB.p1cjwgdban[0] * rtB.grafq4xnvz[1];
rtB.lbvpk2cioa[0] = rtB.czqbao5rcr - rtB.jwmr4335zo;
rtB.lbvpk2cioa[1] = rtB.ds0u1ctsfa - rtB.mgaxq1x2cb;
rtB.lbvpk2cioa[2] = rtB.mbnstg1xrg - rtB.cjk455jyf1;
for (i = 0; i < 3; i++) {
    rtB.o3epcvura2[i] = rtB.k0esd4omu2[i] + rtB.lbvpk2cioa[i];
    rtB.oe1t3pfjur[3 * i] = rtB.nxlaprucin[i];
    rtB.oe1t3pfjur[3 * i + 1] = rtB.nxlaprucin[i + 3];
    rtB.oe1t3pfjur[3 * i + 2] = rtB.nxlaprucin[i + 6];
}
c2g3f2ksqa_idx_0 = rtB.grafq4xnvz[1];
c2g3f2ksqa_idx_1 = rtB.grafq4xnvz[0];
c2g3f2ksqa_idx_2 = rtB.grafq4xnvz[2];
for (i = 0; i < 3; i++) {
    rtB.nycpslghoj[i] = (rtB.oe1t3pfjur[i + 3] * c2g3f2ksqa_idx_0 + rtB.oe1t3pfjur[i] * c2g3f2ksqa_idx_1) + rtB.oe1t3pfjur[i + 6] * c2g3f2ksqa_idx_2;
}






    



                                                UNUSED_PARAMETER(tid);



    

        
                }
        





        


                    
            
                    

        


          void MdlOutputsTID3(int_T tid)
    {
    
                            
        
real_T dnnaxdcdma;
real_T ek2k14s413;
real_T j5ohr2e2zd;
real_T lxy1ok5bys;
int32_T i;

    


                

        
        
    



                                    
                                    rtB.czkarcoix3[0] = rtP.coefAdjust_Gain[0] * rtP.Constant6_Value[0];
rtB.czkarcoix3[1] = rtP.coefAdjust_Gain[1] * rtP.Constant6_Value[1];
rtB.czkarcoix3[2] = rtP.coefAdjust_Gain[2] * rtP.Constant6_Value[2];
if (muDoubleScalarAbs(rtP.FlatEarthtoLLA_LL0[0]) > rtP.CompareToConstant_const_abt4xuk4oi) {
    j5ohr2e2zd = muDoubleScalarMod(rtP.FlatEarthtoLLA_LL0[0] + rtP.Bias_Bias_dw3it2mgbt, rtP.Constant2_Value_njsj4azasy) + rtP.Bias1_Bias_jixhqnsnsh;
} else {
    j5ohr2e2zd = rtP.FlatEarthtoLLA_LL0[0];
}
lxy1ok5bys = muDoubleScalarAbs(j5ohr2e2zd);
if (lxy1ok5bys > rtP.CompareToConstant_const_nv04wgg20q) {
    rtB.idzov0xqov = ((lxy1ok5bys + rtP.Bias_Bias_dzgopcrirx) * rtP.Gain_Gain + rtP.Bias1_Bias_fmis1slqel) * muDoubleScalarSign(j5ohr2e2zd);
    j5ohr2e2zd = rtP.Constant_Value_gxkbwrysrc;
} else {
    rtB.idzov0xqov = j5ohr2e2zd;
    j5ohr2e2zd = rtP.Constant1_Value_dgld0ymnit;
}
j5ohr2e2zd += rtP.FlatEarthtoLLA_LL0[1];
if (muDoubleScalarAbs(j5ohr2e2zd) > rtP.CompareToConstant_const_cbnqt4m3vq) {
    rtB.kf3nkdp1sm = muDoubleScalarMod(j5ohr2e2zd + rtP.Bias_Bias_afrbxfkpq4, rtP.Constant2_Value_mbyiuuie40) + rtP.Bias1_Bias_jpxdd4e1oi;
} else {
    rtB.kf3nkdp1sm = j5ohr2e2zd;
}
/* Unit Conversion - from: deg to: rad
 Expression: output = (0.0174533*input) + (0) */
j5ohr2e2zd = 0.017453292519943295 * rtB.idzov0xqov;
lxy1ok5bys = rtP.f_Value - rtP.Constant_Value_pjdesp3rvm;
ek2k14s413 = rtP.Constant_Value_kdka53fglp - lxy1ok5bys * lxy1ok5bys;
if (ssIsMajorTimeStep(rtS)) {
    if (rtDW.n0rsg5tawa != 0) {
        ssSetBlockStateForSolverChangedAtMajorStep(rtS);
        ssSetContTimeOutputInconsistentWithStateAtMajorStep(rtS);
        rtDW.n0rsg5tawa = 0;
    }
    lxy1ok5bys = muDoubleScalarSqrt(ek2k14s413);
} else if (ek2k14s413 < 0.0) {
    lxy1ok5bys = -muDoubleScalarSqrt(muDoubleScalarAbs(ek2k14s413));
    rtDW.n0rsg5tawa = 1;
} else {
    lxy1ok5bys = muDoubleScalarSqrt(ek2k14s413);
}
ek2k14s413 = muDoubleScalarSin(j5ohr2e2zd);
ek2k14s413 = rtP.Constant_Value_k4mkjjrubk - lxy1ok5bys * lxy1ok5bys * ek2k14s413 * ek2k14s413;
if (ssIsMajorTimeStep(rtS)) {
    if (rtDW.lyamxhsgtb != 0) {
        ssSetBlockStateForSolverChangedAtMajorStep(rtS);
        ssSetContTimeOutputInconsistentWithStateAtMajorStep(rtS);
        rtDW.lyamxhsgtb = 0;
    }
    dnnaxdcdma = muDoubleScalarSqrt(ek2k14s413);
} else if (ek2k14s413 < 0.0) {
    dnnaxdcdma = -muDoubleScalarSqrt(muDoubleScalarAbs(ek2k14s413));
    rtDW.lyamxhsgtb = 1;
} else {
    dnnaxdcdma = muDoubleScalarSqrt(ek2k14s413);
}
dnnaxdcdma = rtP.Constant1_Value_f3g5vycunl / dnnaxdcdma;
rtB.o0lznmwy04 = muDoubleScalarAtan2(rtP.Constant2_Value_fmjdnwbdte, (rtP.Constant_Value_cg2fb4qko2 - lxy1ok5bys * lxy1ok5bys) * dnnaxdcdma / ek2k14s413);
rtB.frkjltmijt = muDoubleScalarAtan2(rtP.Constant3_Value_jtpisyudw2, dnnaxdcdma * muDoubleScalarCos(j5ohr2e2zd));
/* Unit Conversion - from: deg to: rad
 Expression: output = (0.0174533*input) + (0) */
muDoubleScalarSinCos(0.017453292519943295 * rtP.FlatEarthtoLLA_psi, &rtB.legy4gcyuq, &rtB.pq2n04xswi);
rtB.hcxyo5x1fp = rtP.Constant_Value_i4rpol133v * rtP.Constant5_Value;
for (i = 0; i < 3; i++) {
    ek2k14s413 = rtP.Constant4_Value[3 * i] * rtP.Constant_Value_i4rpol133v;
    rtB.mqmfqguhsp[3 * i] = ek2k14s413;
    rtB.i4ejkbvukm[3 * i] = 0.0;
    rtB.a2i2fdw0sz[3 * i] = ek2k14s413;
    ek2k14s413 = rtP.Constant4_Value[3 * i + 1] * rtP.Constant_Value_i4rpol133v;
    rtB.mqmfqguhsp[3 * i + 1] = ek2k14s413;
    rtB.i4ejkbvukm[3 * i + 1] = 0.0;
    rtB.a2i2fdw0sz[3 * i + 1] = ek2k14s413;
    ek2k14s413 = rtP.Constant4_Value[3 * i + 2] * rtP.Constant_Value_i4rpol133v;
    rtB.mqmfqguhsp[3 * i + 2] = ek2k14s413;
    rtB.i4ejkbvukm[3 * i + 2] = 0.0;
    rtB.a2i2fdw0sz[3 * i + 2] = ek2k14s413;
    rtB.k52s5q41hk[i] = 0.0;
}
/* Unit Conversion - from: deg to: rad
 Expression: output = (0.0174533*input) + (0) */
muDoubleScalarSinCos(0.017453292519943295 * rtP.WindShearModel_Wdeg, &j5ohr2e2zd, &lxy1ok5bys);
rtB.o2yo20byci[0] = -rtP.WindShearModel_W_20 * lxy1ok5bys;
rtB.o2yo20byci[1] = -rtP.WindShearModel_W_20 * j5ohr2e2zd;
rtB.o2yo20byci[2] = -rtP.WindShearModel_W_20 * rtP.Wdeg1_Value;
j5ohr2e2zd = rtP.ref_heightz0_Value;
if (ssIsMajorTimeStep(rtS)) {
    if (rtDW.iez3ymddrk != 0) {
        ssSetBlockStateForSolverChangedAtMajorStep(rtS);
        ssSetContTimeOutputInconsistentWithStateAtMajorStep(rtS);
        rtDW.iez3ymddrk = 0;
    }
} else if (rtP.ref_heightz0_Value < 0.0) {
    j5ohr2e2zd = 0.0;
    rtDW.iez3ymddrk = 1;
}
rtB.glou0tzny0 = muDoubleScalarLog(j5ohr2e2zd);





    


                                UNUSED_PARAMETER(tid);



    

        
                }
        







            
        


                    
            
                    

        


          void MdlUpdate(int_T tid)
    {
    
            
                
        
    




                                        
        
    




                                            




                                            UNUSED_PARAMETER(tid);



    

                        }
        





        


                    
            
                    

        


          void MdlUpdateTID3(int_T tid)
    {
    
            
                
        
    


                        
        
    


                            


                            UNUSED_PARAMETER(tid);



    

                        }
        







                            
                        

        


          void MdlDerivatives(void)
    {
    

            

            
    
XDot *_rtXdot;

    




                                
        
    




                                                
                                    _rtXdot = ((XDot *) ssGetdX(rtS));
_rtXdot->e23jdsrfeo[0] = rtB.nycpslghoj[0];
_rtXdot->n5z0itpfcl[0] = rtB.jrvb2m0kwj[0];
_rtXdot->ffm313ejt1[0] = rtB.hdpsy3sguu[0];
_rtXdot->igfhqv0lvj[0] = rtB.o3epcvura2[0];
_rtXdot->e23jdsrfeo[1] = rtB.nycpslghoj[1];
_rtXdot->n5z0itpfcl[1] = rtB.jrvb2m0kwj[1];
_rtXdot->ffm313ejt1[1] = rtB.hdpsy3sguu[1];
_rtXdot->igfhqv0lvj[1] = rtB.o3epcvura2[1];
_rtXdot->e23jdsrfeo[2] = rtB.nycpslghoj[2];
_rtXdot->n5z0itpfcl[2] = rtB.jrvb2m0kwj[2];
_rtXdot->ffm313ejt1[2] = rtB.hdpsy3sguu[2];
_rtXdot->igfhqv0lvj[2] = rtB.o3epcvura2[2];





    




                
        
                }
        



                            
                            

        


          void MdlProjection(void)
    {
    


                            
        
        




                                                




                                                




                                }
        


                            
                        

        


          void MdlZeroCrossings(void)
    {
    


                
    
ZCV *_rtZCSV;

    




                                    




                                                
                                    _rtZCSV = ((ZCV *) ssGetSolverZcSignalVector(rtS));
_rtZCSV->lu3c55ecxf[0] = rtB.eenfrxbcez[0] - rtP.uftinf_UpperSat;
_rtZCSV->axz4m0humc[0] = rtB.eenfrxbcez[0] - rtP.uftinf_LowerSat;
_rtZCSV->mwyudkm1dy[0] = rtB.p0shvkceq5[0] - rtP.Limitaltitudetotroposhere_UpperSat;
_rtZCSV->bt0q5oi2ra[0] = rtB.p0shvkceq5[0] - rtP.Limitaltitudetotroposhere_LowerSat;
_rtZCSV->aw0opacu4m[0] = rtB.gx2bnlk0lw[0] - rtP.LimitaltitudetoStratosphere_UpperSat;
_rtZCSV->ntoczab3l3[0] = rtB.gx2bnlk0lw[0] - rtP.LimitaltitudetoStratosphere_LowerSat;
_rtZCSV->lu3c55ecxf[1] = rtB.eenfrxbcez[1] - rtP.uftinf_UpperSat;
_rtZCSV->axz4m0humc[1] = rtB.eenfrxbcez[1] - rtP.uftinf_LowerSat;
_rtZCSV->mwyudkm1dy[1] = rtB.p0shvkceq5[1] - rtP.Limitaltitudetotroposhere_UpperSat;
_rtZCSV->bt0q5oi2ra[1] = rtB.p0shvkceq5[1] - rtP.Limitaltitudetotroposhere_LowerSat;
_rtZCSV->aw0opacu4m[1] = rtB.gx2bnlk0lw[1] - rtP.LimitaltitudetoStratosphere_UpperSat;
_rtZCSV->ntoczab3l3[1] = rtB.gx2bnlk0lw[1] - rtP.LimitaltitudetoStratosphere_LowerSat;
_rtZCSV->lu3c55ecxf[2] = rtB.eenfrxbcez[2] - rtP.uftinf_UpperSat;
_rtZCSV->axz4m0humc[2] = rtB.eenfrxbcez[2] - rtP.uftinf_LowerSat;
_rtZCSV->mwyudkm1dy[2] = rtB.p0shvkceq5[2] - rtP.Limitaltitudetotroposhere_UpperSat;
_rtZCSV->bt0q5oi2ra[2] = rtB.p0shvkceq5[2] - rtP.Limitaltitudetotroposhere_LowerSat;
_rtZCSV->aw0opacu4m[2] = rtB.gx2bnlk0lw[2] - rtP.LimitaltitudetoStratosphere_UpperSat;
_rtZCSV->ntoczab3l3[2] = rtB.gx2bnlk0lw[2] - rtP.LimitaltitudetoStratosphere_LowerSat;
_rtZCSV->em3amdgmbu = rtB.ltespdje45[0];
_rtZCSV->jvpprkpwgk = rtB.f3grp50dae - rtP.CompareToConstant_const_pwri3oqztp;
_rtZCSV->m0qienrh44 = rtB.a4vnpcfi1i;
_rtZCSV->nopzsnecq5 = rtB.cnuqgk0ctt - rtP.CompareToConstant_const;
_rtZCSV->hhidsenk2j = rtB.a4vnpcfi1i;
_rtZCSV->cle00v3zor = rtB.bzbu3yseb2;
_rtZCSV->h4g4pudpyw = rtB.dekfyvtcle - rtP.CompareToConstant_const_eds1jbkaw1;





    




                            }
        


                                    
                

        


          void MdlTerminate(void)
    {
    
                
            
    
    




                                    




                                        




                            }
        


        
            
    static void mr_rocketLIBRARY_cacheDataAsMxArray(mxArray * destArray, mwIndex i, int j, const void * srcData, size_t numBytes);
    static void mr_rocketLIBRARY_cacheDataAsMxArray(mxArray * destArray, mwIndex i, int j, const void * srcData, size_t numBytes)
    {
        mxArray * newArray = 
        mxCreateUninitNumericMatrix((size_t) 1, numBytes, mxUINT8_CLASS, mxREAL);
        memcpy((uint8_T *) mxGetData(newArray), (const uint8_T *) srcData, numBytes);
        mxSetFieldByNumber(destArray, i, j, newArray);
    }
    static void mr_rocketLIBRARY_restoreDataFromMxArray(void * destData, const mxArray * srcArray, mwIndex i, int j, size_t numBytes);
    static void mr_rocketLIBRARY_restoreDataFromMxArray(void * destData, const mxArray * srcArray, mwIndex i, int j, size_t numBytes)
    {
        memcpy((uint8_T *) destData,
        (const uint8_T *) mxGetData(mxGetFieldByNumber(srcArray, i, j)),
        numBytes);
    }
    static void mr_rocketLIBRARY_cacheBitFieldToMxArray(mxArray * destArray, mwIndex i, int j, uint_T bitVal);
    static void mr_rocketLIBRARY_cacheBitFieldToMxArray(mxArray * destArray, mwIndex i, int j, uint_T bitVal)
    {
        mxSetFieldByNumber(destArray, i, j, mxCreateDoubleScalar((real_T) bitVal));
    }
    static uint_T mr_rocketLIBRARY_extractBitFieldFromMxArray(const mxArray * srcArray, mwIndex i, int j, uint_T numBits);
    static uint_T mr_rocketLIBRARY_extractBitFieldFromMxArray(const mxArray * srcArray, mwIndex i, int j, uint_T numBits)
    {
        const uint_T varVal = (uint_T) mxGetScalar(mxGetFieldByNumber(srcArray, i, j));
        return varVal & ((1u<<numBits)-1u);
    }
    static void mr_rocketLIBRARY_cacheDataToMxArrayWithOffset(mxArray * destArray, mwIndex i, int j, mwIndex offset, const void * srcData, size_t numBytes);
    static void mr_rocketLIBRARY_cacheDataToMxArrayWithOffset(mxArray * destArray, mwIndex i, int j, mwIndex offset, const void * srcData, size_t numBytes)
    {
        uint8_T * varData =         (uint8_T *) mxGetData(mxGetFieldByNumber(destArray, i, j));

        memcpy(         (uint8_T *) &varData[offset*numBytes],         (const uint8_T *) srcData,         numBytes);
    }
    static void mr_rocketLIBRARY_restoreDataFromMxArrayWithOffset(void * destData, const mxArray * srcArray, mwIndex i, int j, mwIndex offset, size_t numBytes);
    static void mr_rocketLIBRARY_restoreDataFromMxArrayWithOffset(void * destData, const mxArray * srcArray, mwIndex i, int j, mwIndex offset, size_t numBytes)
    {
        const uint8_T * varData =         (const uint8_T *) mxGetData(mxGetFieldByNumber(srcArray, i, j));

        memcpy(         (uint8_T *) destData,         (const uint8_T *) &varData[offset*numBytes],         numBytes);
    }
    static void mr_rocketLIBRARY_cacheBitFieldToCellArrayWithOffset(mxArray * destArray, mwIndex i, int j, mwIndex offset, uint_T fieldVal);
    static void mr_rocketLIBRARY_cacheBitFieldToCellArrayWithOffset(mxArray * destArray, mwIndex i, int j, mwIndex offset, uint_T fieldVal)
    {
        mxSetCell(mxGetFieldByNumber(destArray, i, j), offset,         mxCreateDoubleScalar((real_T) fieldVal));
    }
    static uint_T mr_rocketLIBRARY_extractBitFieldFromCellArrayWithOffset(const mxArray * srcArray, mwIndex i, int j, mwIndex offset, uint_T numBits);
    static uint_T mr_rocketLIBRARY_extractBitFieldFromCellArrayWithOffset(const mxArray * srcArray, mwIndex i, int j, mwIndex offset, uint_T numBits)
    {
        const uint_T fieldVal =         (uint_T) mxGetScalar(mxGetCell(mxGetFieldByNumber(srcArray, i, j), offset));

        return fieldVal & ((1u << numBits) - 1u);
    }
            mxArray * mr_rocketLIBRARY_GetDWork() {

    static const char_T * ssDWFieldNames[3] = {
        "rtB",
        "rtDW",
        "NULL_PrevZCX",
    };
    mxArray * ssDW = mxCreateStructMatrix(1, 1, 3, ssDWFieldNames);


                                mr_rocketLIBRARY_cacheDataAsMxArray(
    ssDW, 0, 0, (const void*)&(rtB), sizeof(rtB));


    
    {
            static const char_T * rtdwDataFieldNames[15] = {
                    "rtDW.dyg4fa5n4f",
                    "rtDW.k3zlzo4rka",
                    "rtDW.eyovwuix3c",
                    "rtDW.ljats3taij",
                    "rtDW.kmks0kqlp2",
                    "rtDW.nentsm3ztg",
                    "rtDW.lzyi1v2xh5",
                    "rtDW.gbjv2wu0pg",
                    "rtDW.pyhu0x3txh",
                    "rtDW.n0rsg5tawa",
                    "rtDW.lyamxhsgtb",
                    "rtDW.iez3ymddrk",
                    "rtDW.k4tj0ddmtk",
                    "rtDW.i3cpbuohc4",
                    "rtDW.j0vp3pypgy",
            };
        mxArray * rtdwData = 
        mxCreateStructMatrix(1, 1, 15, rtdwDataFieldNames);


    
        mr_rocketLIBRARY_cacheDataAsMxArray(
    rtdwData, 0, 0, (const void*)&(rtDW.dyg4fa5n4f), sizeof(rtDW.dyg4fa5n4f));

    mr_rocketLIBRARY_cacheDataAsMxArray(
    rtdwData, 0, 1, (const void*)&(rtDW.k3zlzo4rka), sizeof(rtDW.k3zlzo4rka));

    mr_rocketLIBRARY_cacheDataAsMxArray(
    rtdwData, 0, 2, (const void*)&(rtDW.eyovwuix3c), sizeof(rtDW.eyovwuix3c));

    mr_rocketLIBRARY_cacheDataAsMxArray(
    rtdwData, 0, 3, (const void*)&(rtDW.ljats3taij), sizeof(rtDW.ljats3taij));

    mr_rocketLIBRARY_cacheDataAsMxArray(
    rtdwData, 0, 4, (const void*)&(rtDW.kmks0kqlp2), sizeof(rtDW.kmks0kqlp2));

    mr_rocketLIBRARY_cacheDataAsMxArray(
    rtdwData, 0, 5, (const void*)&(rtDW.nentsm3ztg), sizeof(rtDW.nentsm3ztg));

    mr_rocketLIBRARY_cacheDataAsMxArray(
    rtdwData, 0, 6, (const void*)&(rtDW.lzyi1v2xh5), sizeof(rtDW.lzyi1v2xh5));

    mr_rocketLIBRARY_cacheDataAsMxArray(
    rtdwData, 0, 7, (const void*)&(rtDW.gbjv2wu0pg), sizeof(rtDW.gbjv2wu0pg));

    mr_rocketLIBRARY_cacheDataAsMxArray(
    rtdwData, 0, 8, (const void*)&(rtDW.pyhu0x3txh), sizeof(rtDW.pyhu0x3txh));

    mr_rocketLIBRARY_cacheDataAsMxArray(
    rtdwData, 0, 9, (const void*)&(rtDW.n0rsg5tawa), sizeof(rtDW.n0rsg5tawa));

    mr_rocketLIBRARY_cacheDataAsMxArray(
    rtdwData, 0, 10, (const void*)&(rtDW.lyamxhsgtb), sizeof(rtDW.lyamxhsgtb));

    mr_rocketLIBRARY_cacheDataAsMxArray(
    rtdwData, 0, 11, (const void*)&(rtDW.iez3ymddrk), sizeof(rtDW.iez3ymddrk));

    mr_rocketLIBRARY_cacheDataAsMxArray(
    rtdwData, 0, 12, (const void*)&(rtDW.k4tj0ddmtk), sizeof(rtDW.k4tj0ddmtk));

    mr_rocketLIBRARY_cacheDataAsMxArray(
    rtdwData, 0, 13, (const void*)&(rtDW.i3cpbuohc4), sizeof(rtDW.i3cpbuohc4));

    mr_rocketLIBRARY_cacheDataAsMxArray(
    rtdwData, 0, 14, (const void*)&(rtDW.j0vp3pypgy), sizeof(rtDW.j0vp3pypgy));


    
    mxSetFieldByNumber(ssDW, 0, 1, rtdwData);
}



                        return ssDW;

                }
                void mr_rocketLIBRARY_SetDWork(const mxArray* ssDW) {



                        (void) ssDW;

                            mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtB), ssDW, 0, 0, sizeof(rtB));





                            



                            
    

        {
            const mxArray * rtdwData = 
            mxGetFieldByNumber(ssDW, 0, 1);



    
    

    
    mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtDW.dyg4fa5n4f), rtdwData, 0, 0, sizeof(rtDW.dyg4fa5n4f));





                    mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtDW.k3zlzo4rka), rtdwData, 0, 1, sizeof(rtDW.k3zlzo4rka));





                    mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtDW.eyovwuix3c), rtdwData, 0, 2, sizeof(rtDW.eyovwuix3c));





                    mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtDW.ljats3taij), rtdwData, 0, 3, sizeof(rtDW.ljats3taij));





                    mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtDW.kmks0kqlp2), rtdwData, 0, 4, sizeof(rtDW.kmks0kqlp2));





                    mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtDW.nentsm3ztg), rtdwData, 0, 5, sizeof(rtDW.nentsm3ztg));





                    mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtDW.lzyi1v2xh5), rtdwData, 0, 6, sizeof(rtDW.lzyi1v2xh5));





                    mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtDW.gbjv2wu0pg), rtdwData, 0, 7, sizeof(rtDW.gbjv2wu0pg));





                    mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtDW.pyhu0x3txh), rtdwData, 0, 8, sizeof(rtDW.pyhu0x3txh));





                    mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtDW.n0rsg5tawa), rtdwData, 0, 9, sizeof(rtDW.n0rsg5tawa));





                    mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtDW.lyamxhsgtb), rtdwData, 0, 10, sizeof(rtDW.lyamxhsgtb));





                    mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtDW.iez3ymddrk), rtdwData, 0, 11, sizeof(rtDW.iez3ymddrk));





                    mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtDW.k4tj0ddmtk), rtdwData, 0, 12, sizeof(rtDW.k4tj0ddmtk));





                    mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtDW.i3cpbuohc4), rtdwData, 0, 13, sizeof(rtDW.i3cpbuohc4));





                    mr_rocketLIBRARY_restoreDataFromMxArray(
    (void*)&(rtDW.j0vp3pypgy), rtdwData, 0, 14, sizeof(rtDW.j0vp3pypgy));









    
    

    
}











            }


        mxArray * mr_rocketLIBRARY_GetSimStateDisallowedBlocks()
        {


                    mxArray * data = mxCreateCellMatrix(1, 3);
                    mwIndex subs[2], offset;

                    

        {
            static const char_T * blockType[1] = {
                    "Scope",
            };

            static const char_T * blockPath[1] = {
                    "rocketLIBRARY/Scope",
            };

            static const int reason[1] = {
                    0,
            };

            for (subs[0] = 0; subs[0] < 1; ++(subs[0])) {
                subs[1] = 0;
                offset  = mxCalcSingleSubscript(data, 2, subs);

                mxSetCell(data, offset, mxCreateString(blockType[subs[0]]));

                subs[1] = 1;
                offset  = mxCalcSingleSubscript(data, 2, subs);

                mxSetCell(data, offset, mxCreateString(blockPath[subs[0]]));

                subs[1] = 2;
                offset  = mxCalcSingleSubscript(data, 2, subs);

                mxSetCell(data, offset, mxCreateDoubleScalar((real_T)reason[subs[0]]));
            }
        }




                    return data;



        }



 void MdlInitializeSizes(void)
{
        ssSetNumContStates(rtS, 12); /* Number of continuous states */
        ssSetNumPeriodicContStates(rtS, 3); /* Number of periodic continuous states */
    ssSetNumY(rtS, 0);  /* Number of model outputs */
    ssSetNumU(rtS, 0);    /* Number of model inputs */
        ssSetDirectFeedThrough(rtS, 0);  /* The model is not direct feedthrough */
    ssSetNumSampleTimes(rtS, 3);   /* Number of sample times */
    ssSetNumBlocks(rtS, 225); /* Number of blocks */
        ssSetNumBlockIO(rtS, 77); /* Number of block outputs */
        ssSetNumBlockParams(rtS, 95);  /* Sum of parameter "widths" */
}


 void MdlInitializeSampleTimes(void)
{
            /* task periods */
            ssSetSampleTime(rtS, 0, 0.0);
            ssSetSampleTime(rtS, 1, 0.0);
            ssSetSampleTime(rtS, 2, 0.1);

        /* task offsets */
            ssSetOffsetTime(rtS, 0, 0.0);
            ssSetOffsetTime(rtS, 1, 1.0);
            ssSetOffsetTime(rtS, 2, 0.0);
}




    
     void raccel_set_checksum()
    {
            ssSetChecksumVal(rtS, 0, 3658516348U);
    ssSetChecksumVal(rtS, 1, 1159428955U);
    ssSetChecksumVal(rtS, 2, 3784968166U);
    ssSetChecksumVal(rtS, 3, 3035424888U);

    }


    
    
    
    

    
    
    
    

    


/* Turns off all optimizations on Windows because of issues with VC 2015 compiler.
This function is not performance-critical, hence this is not a problem.
*/
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
 SimStruct * raccel_register_model(ssExecutionInfo* executionInfo)
{
            static struct _ssMdlInfo mdlInfo;
        static struct _ssBlkInfo2 blkInfo2;
        static struct _ssBlkInfoSLSize blkInfoSLSize;


    

    


        (void) memset((char_T *)rtS, 0,
sizeof(SimStruct));

            (void) memset((char_T *)&mdlInfo, 0,
sizeof(struct _ssMdlInfo));
            (void) memset((char_T *)&blkInfo2, 0,
sizeof(struct _ssBlkInfo2));
            (void) memset((char_T *)&blkInfoSLSize, 0,
sizeof(struct _ssBlkInfoSLSize));
        ssSetBlkInfo2Ptr(rtS, &blkInfo2);
        ssSetBlkInfoSLSizePtr(rtS, &blkInfoSLSize);
        ssSetMdlInfoPtr(rtS, &mdlInfo);
            ssSetExecutionInfo(rtS, executionInfo);
            slsaAllocOPModelData(rtS);

    
    
        /* timing info */
    {
        static time_T mdlPeriod[NSAMPLE_TIMES];
        static time_T mdlOffset[NSAMPLE_TIMES];
        static time_T mdlTaskTimes[NSAMPLE_TIMES];
        static int_T  mdlTsMap[NSAMPLE_TIMES];
        static int_T  mdlSampleHits[NSAMPLE_TIMES];
            static boolean_T  mdlTNextWasAdjustedPtr[NSAMPLE_TIMES];
            static int_T mdlPerTaskSampleHits[NSAMPLE_TIMES * NSAMPLE_TIMES];
            static time_T mdlTimeOfNextSampleHit[NSAMPLE_TIMES];

        {
            int_T i;

            for (i = 0; i < NSAMPLE_TIMES; i++) {
                mdlPeriod[i] = 0.0;
                mdlOffset[i] = 0.0;
                mdlTaskTimes[i] = 0.0;
                mdlTsMap[i] = i;
                    mdlSampleHits[i] = 1;
            }
        }

        ssSetSampleTimePtr(rtS, &mdlPeriod[0]);
        ssSetOffsetTimePtr(rtS, &mdlOffset[0]);
        ssSetSampleTimeTaskIDPtr(rtS, &mdlTsMap[0]);
        ssSetTPtr(rtS, &mdlTaskTimes[0]);
        ssSetSampleHitPtr(rtS, &mdlSampleHits[0]);
            ssSetTNextWasAdjustedPtr(rtS, &mdlTNextWasAdjustedPtr[0]);
            ssSetPerTaskSampleHitsPtr(rtS, &mdlPerTaskSampleHits[0]);
            ssSetTimeOfNextSampleHitPtr(rtS, &mdlTimeOfNextSampleHit[0]);
    }
        ssSetSolverMode(rtS, SOLVER_MODE_SINGLETASKING);
        /*
    * initialize model vectors and cache them in SimStruct
    */

        /* block I/O */
        {
                        ssSetBlockIO(rtS, ((void *) &rtB));




                
                (void) memset(((void *) &rtB), 0,
sizeof(B));
                

                


                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                

        }



        /* states (continuous)*/
        {
            real_T *x = (real_T *) &rtX;

            ssSetContStates(rtS, x);
            (void) memset((void *)x, 0,
sizeof(X));
        }

        /* states (dwork) */
        {
            void *dwork = (void *) &rtDW;

            ssSetRootDWork(rtS, dwork);
                (void) memset(dwork,  0,
 sizeof(DW));
                
        }



            /* data type transition information */
        {
                static DataTypeTransInfo dtInfo;

                    (void) memset((char_T *) &dtInfo, 0,
sizeof(dtInfo));
                ssSetModelMappingInfo(rtS, &dtInfo);

                dtInfo.numDataTypes  = 23;
                    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
                    dtInfo.dataTypeNames = &rtDataTypeNames[0];

                    /* Block I/O transition table */
                    dtInfo.BTransTable = &rtBTransTable;

                    /* Parameters transition table */
                    dtInfo.PTransTable = &rtPTransTable;
                    dtInfo.dataTypeInfoTable = rtDataTypeInfoTable;
        }
        /* Initialize DataMapInfo substructure containing ModelMap for C API */
            rocketLIBRARY_InitializeDataMapInfo();

        ssSetIsRapidAcceleratorActive(rtS, true);


    /* Model specific registration */
        ssSetRootSS(rtS, rtS);

        ssSetVersion(rtS, SIMSTRUCT_VERSION_LEVEL2);
    ssSetModelName(rtS, "rocketLIBRARY");
    ssSetPath(rtS, "rocketLIBRARY");

    ssSetTStart(rtS, 0.0);

    ssSetTFinal(rtS, 43.0);


        
    


        
        
        

        

    


        




        



        
        /* Setup for data logging */
        {
                static RTWLogInfo rt_DataLoggingInfo;
                rt_DataLoggingInfo.loggingInterval = (NULL);

                        ssSetRTWLogInfo(rtS, &rt_DataLoggingInfo);

        }


    /* Setup for data logging */
    {
            /*
            * Set pointers to the data and signal info each state
            */
                











    {
            static  int_T rt_LoggedStateWidths[] =             {
                
3,


3,


3,


3


            };

            static  int_T rt_LoggedStateNumDimensions[] =             {
                
1,


1,


1,


1


            };

            static  int_T rt_LoggedStateDimensions[] =             {
                
3,


3,


3,


3


            };

            static  boolean_T rt_LoggedStateIsVarDims[] =             {
                
0,


0,


0,


0


            };

            static  BuiltInDTypeId rt_LoggedStateDataTypeIds[] =             {
                
SS_DOUBLE,


SS_DOUBLE,


SS_DOUBLE,


SS_DOUBLE


            };

            static  int_T rt_LoggedStateComplexSignals[] =             {
                
0,


0,


0,


0


            };

            static  RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs[] =             {
                
(NULL),


(NULL),


(NULL),


(NULL)


            };

            static  const char_T  *rt_LoggedStateLabels[] = {
                
"CSTATE",


"CSTATE",


"CSTATE",


"CSTATE"

};

                static  const char_T *rt_LoggedStateBlockNames[] = {
                    
"rocketLIBRARY/Rocket Body Motions/xe,ye,ze",


"rocketLIBRARY/Rocket Body Motions/Calculate DCM &\nEuler Angles/phi\ntheta\npsi",


"rocketLIBRARY/Rocket Body Motions/p,q,r ",


"rocketLIBRARY/Rocket Body Motions/ub,vb,wb"

};

                    static  const char_T *rt_LoggedStateNames[] = {
                        
"",


"",


"",


""

};

                        static  boolean_T rt_LoggedStateCrossMdlRef[] =                         {
                            
0,


0,


0,


0


                        };

                        static  RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] =                         {
                            
{ 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0},


{ 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0},


{ 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0},


{ 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0}


                        };

                            static  int_T rt_LoggedStateIdxList[] =                            {
                                    
0,


1,


2,


3


                            };

                        static  RTWLogSignalInfo rt_LoggedStateSignalInfo =                         {
                                4,
                            rt_LoggedStateWidths,
                            rt_LoggedStateNumDimensions,
                            rt_LoggedStateDimensions,
                            rt_LoggedStateIsVarDims, 
                            (NULL), 
                            (NULL), 
                            rt_LoggedStateDataTypeIds,
                            rt_LoggedStateComplexSignals,
                            (NULL), 
                            rt_LoggingStatePreprocessingFcnPtrs,
                            {rt_LoggedStateLabels},
                            (NULL),
                            (NULL),
                            (NULL),
                            {rt_LoggedStateBlockNames},
                            {rt_LoggedStateNames},
                            rt_LoggedStateCrossMdlRef,
                            rt_RTWLogDataTypeConvert
                                ,rt_LoggedStateIdxList
                        };

                static void * rt_LoggedStateSignalPtrs[4];

                    rtliSetLogXSignalPtrs(ssGetRTWLogInfo(rtS), (LogSignalPtrsType) rt_LoggedStateSignalPtrs);


                    rtliSetLogXSignalInfo(ssGetRTWLogInfo(rtS), &rt_LoggedStateSignalInfo);

            
rt_LoggedStateSignalPtrs[0] = (void*)&rtX.e23jdsrfeo[0];


rt_LoggedStateSignalPtrs[1] = (void*)&rtX.n5z0itpfcl[0];


rt_LoggedStateSignalPtrs[2] = (void*)&rtX.ffm313ejt1[0];


rt_LoggedStateSignalPtrs[3] = (void*)&rtX.igfhqv0lvj[0];

    }

                    rtliSetLogT(ssGetRTWLogInfo(rtS), "tout");

                    rtliSetLogX(ssGetRTWLogInfo(rtS), "");

                    rtliSetLogXFinal(ssGetRTWLogInfo(rtS), "xFinal");

                    rtliSetLogVarNameModifier(ssGetRTWLogInfo(rtS), "none");

                    rtliSetLogFormat(ssGetRTWLogInfo(rtS), 4);

                    rtliSetLogMaxRows(ssGetRTWLogInfo(rtS), 0);

                    rtliSetLogDecimation(ssGetRTWLogInfo(rtS), 1);





                        rtliSetLogY(ssGetRTWLogInfo(rtS), "");


                        rtliSetLogYSignalInfo(ssGetRTWLogInfo(rtS), (NULL));

                        rtliSetLogYSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));

    }



        {
            static struct _ssStatesInfo2 statesInfo2;
            ssSetStatesInfo2(rtS, &statesInfo2);
        }

        {
            static ssPeriodicStatesInfo periodicStatesInfo;
            ssSetPeriodicStatesInfo(rtS, &periodicStatesInfo);


                ssSetPeriodicContStateIndices(rtS, rtPeriodicIndX);
                (void) memset((void*) rtPeriodicIndX, 0,
3*sizeof(int_T));
                ssSetPeriodicContStateRanges(rtS, rtPeriodicRngX);
                (void) memset((void*) rtPeriodicRngX, 0,
6*sizeof(real_T));

        }

        {
            static ssJacobianPerturbationBounds jacobianPerturbationBounds;
            ssSetJacobianPerturbationBounds(rtS, &jacobianPerturbationBounds);
        }

            {
        static ssSolverInfo slvrInfo;

            static boolean_T contStatesDisabled[12];



                static real_T absTol[12] = {                        1.0E-6                        , 1.0E-6                        , 1.0E-6                        , 1.0E-6                        , 1.0E-6                        , 1.0E-6                        , 1.0E-6                        , 1.0E-6                        , 1.0E-6                        , 1.0E-6                        , 1.0E-6                        , 1.0E-6                };

                static uint8_T absTolControl[12] = { 0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U };

                    static real_T contStateJacPerturbBoundMinVec[12];
                    static real_T contStateJacPerturbBoundMaxVec[12];


                static uint8_T zcAttributes[25] = {                (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)                , (ZC_EVENT_ALL)    };




            static ssNonContDerivSigInfo nonContDerivSigInfo[1] = {
                        { 3*sizeof(real_T), (char*)(&rtB.ivl5z2vmyi[0]), (NULL) }
            };

            



                /* Initialize cont state perturbation bound */
                {
                    int i;
                    for (i = 0; i < 12; ++i){
                        contStateJacPerturbBoundMinVec[i] = 0;
                        contStateJacPerturbBoundMaxVec[i] = rtGetInf();
                    }
                }

                ssSetSolverRelTol(rtS, 0.001);
            ssSetStepSize(rtS, 0.0);
            ssSetMinStepSize(rtS, 0.0);
            ssSetMaxNumMinSteps(rtS, -1);
            ssSetMinStepViolatedError(rtS, 0);
            ssSetMaxStepSize(rtS, 0.1);
            ssSetSolverMaxOrder(rtS, -1);

            ssSetSolverRefineFactor(rtS, 1);
            ssSetOutputTimes(rtS, (NULL));
            ssSetNumOutputTimes(rtS, 0);
                ssSetOutputTimesOnly(rtS, 0);
            ssSetOutputTimesIndex(rtS, 0);
            ssSetZCCacheNeedsReset(rtS, 1);
            ssSetDerivCacheNeedsReset(rtS, 0);
        ssSetNumNonContDerivSigInfos(rtS, 1);
        ssSetNonContDerivSigInfos(rtS, nonContDerivSigInfo);
        ssSetSolverInfo(rtS, &slvrInfo);
        ssSetSolverName(rtS, "VariableStepAuto");
        ssSetVariableStepSolver(rtS, 1);
        ssSetSolverConsistencyChecking(rtS, 0);
        ssSetSolverAdaptiveZcDetection(rtS, 0);
        ssSetSolverRobustResetMethod(rtS, 0);
            ssSetAbsTolVector(rtS, absTol);
            ssSetAbsTolControlVector(rtS, absTolControl);
            ssSetSolverAbsTol_Obsolete(rtS, absTol);
            ssSetSolverAbsTolControl_Obsolete(rtS, absTolControl);

            ssSetJacobianPerturbationBoundsMinVec(rtS, contStateJacPerturbBoundMinVec);
            ssSetJacobianPerturbationBoundsMaxVec(rtS, contStateJacPerturbBoundMaxVec);

        ssSetSolverStateProjection(rtS, 0);
        ssSetSolverMassMatrixType(rtS, (ssMatrixType)0);
        ssSetSolverMassMatrixNzMax(rtS, 0);
        ssSetModelOutputs(rtS, MdlOutputs);
        ssSetModelUpdate(rtS, MdlUpdate);
            ssSetModelDerivatives(rtS, MdlDerivatives);
            ssSetSolverZcSignalAttrib(rtS, zcAttributes);
            ssSetSolverNumZcSignals(rtS, 25);
            ssSetModelZeroCrossings(rtS, MdlZeroCrossings);
                ssSetSolverConsecutiveZCsStepRelTol(rtS, 2.8421709430404007E-13);
                ssSetSolverMaxConsecutiveZCs(rtS, 1000);
                ssSetSolverConsecutiveZCsError(rtS, 2);
                ssSetSolverMaskedZcDiagnostic(rtS, 1);
                ssSetSolverIgnoredZcDiagnostic(rtS, 1);

            ssSetSolverMaxConsecutiveMinStep(rtS, 1);
            ssSetSolverShapePreserveControl(rtS, 2);

        ssSetTNextTid(rtS, INT_MIN);
        ssSetTNext(rtS, rtMinusInf);
        ssSetSolverNeedsReset(rtS);
        ssSetNumNonsampledZCs(rtS, 25);
            ssSetContStateDisabled(rtS, contStatesDisabled);


            ssSetSolverMaxConsecutiveMinStep(rtS, 1);

    }




        ssSetChecksumVal(rtS, 0, 3658516348U);
    ssSetChecksumVal(rtS, 1, 1159428955U);
    ssSetChecksumVal(rtS, 2, 3784968166U);
    ssSetChecksumVal(rtS, 3, 3035424888U);

            {
                    static const sysRanDType  rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
                    static RTWExtModeInfo rt_ExtModeInfo;
                    static const sysRanDType *systemRan[5];


                    gblRTWExtModeInfo = &rt_ExtModeInfo;

                ssSetRTWExtModeInfo(rtS, &rt_ExtModeInfo);
                rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
                
                systemRan[0] = &rtAlwaysEnabled;
                systemRan[1] = &rtAlwaysEnabled;
                systemRan[2] = &rtAlwaysEnabled;
                systemRan[3] = &rtAlwaysEnabled;
                systemRan[4] = &rtAlwaysEnabled;


                rteiSetModelMappingInfoPtr(ssGetRTWExtModeInfo(rtS), &ssGetModelMappingInfo(rtS));

                rteiSetChecksumsPtr(ssGetRTWExtModeInfo(rtS), ssGetChecksums(rtS));

                    rteiSetTPtr(ssGetRTWExtModeInfo(rtS), ssGetTPtr(rtS));

        }


        
        slsaDisallowedBlocksForSimTargetOP(rtS, mr_rocketLIBRARY_GetSimStateDisallowedBlocks);
        slsaGetWorkFcnForSimTargetOP(rtS, mr_rocketLIBRARY_GetDWork);
        slsaSetWorkFcnForSimTargetOP(rtS, mr_rocketLIBRARY_SetDWork);
    
        /* non-finite (run-time) assignments */
        
rtP.uftinf_UpperSat = rtInf;



        
                /* We don't have GOTO_EXIT_IF_ERROR here as engine is not initialized
    via rsimInitializeEngine */
    rt_RapidReadMatFileAndUpdateParams(rtS);
    if(ssGetErrorStatus(rtS)) {
        return rtS;
    }
                
        
        



    return rtS;
}
/* When you use the on parameter, it resets the optimizations to those that you
specified with the /O compiler option. */
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif



    

    

    

            const int_T gblParameterTuningTid = 3;
        void MdlOutputsParameterSampleTime(int_T tid) {
            
            
                MdlOutputsTID3(tid);
        }

