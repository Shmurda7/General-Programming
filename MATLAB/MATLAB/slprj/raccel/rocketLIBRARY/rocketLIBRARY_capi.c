        /*
        * rocketLIBRARY_capi.c
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

            
    #include "rtw_capi.h"

    #ifdef HOST_CAPI_BUILD
    #include "rocketLIBRARY_capi_host.h"

    #define sizeof(s) ((size_t)(0xFFFF))
    #undef rt_offsetof
    #define rt_offsetof(s,el) ((uint16_T)(0xFFFF))

    #define TARGET_CONST
    #define TARGET_STRING(s) (s)

    
    #ifndef SS_UINT64
    #define SS_UINT64 17
    #endif
    #ifndef SS_INT64
    #define SS_INT64 18
    #endif


    #else /* HOST_CAPI_BUILD */

    #include "builtin_typeid_types.h"
    #include "rocketLIBRARY.h"
    #include "rocketLIBRARY_capi.h"

                #include "rocketLIBRARY_private.h"



    #ifdef LIGHT_WEIGHT_CAPI
    #define TARGET_CONST
    #define TARGET_STRING(s)               ((NULL))
    #else
    #define TARGET_CONST                   const
    #define TARGET_STRING(s)               (s)
    #endif

    #endif /* HOST_CAPI_BUILD */


        















                    /* Block output signal information */
                    static const rtwCAPI_Signals rtBlockSignals[] = {

                        /* addrMapIndex, sysNum, blockPath,
                        * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
                        */


































































































                                                        




                                                            



                                                                
                                                        
                                                        {0, 0, TARGET_STRING("rocketLIBRARY/Product"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 0},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {1, 0, TARGET_STRING("rocketLIBRARY/Product1"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        










                                                        




                                                            



                                                                
                                                        
                                                        {2, 0, TARGET_STRING("rocketLIBRARY/Sum"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {3, 0, TARGET_STRING("rocketLIBRARY/Sum1"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {4, 0, TARGET_STRING("rocketLIBRARY/Switch"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





















                                                        




                                                            



                                                                
                                                        
                                                        {5, 0, TARGET_STRING("rocketLIBRARY/Aerodynamic Forces and Moments /coefAdjust"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 0},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {6, 0, TARGET_STRING("rocketLIBRARY/Aerodynamic Forces and Moments /reference area"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {7, 0, TARGET_STRING("rocketLIBRARY/Aerodynamic Forces and Moments /Product"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        



























                                                        




                                                            



                                                                
                                                        
                                                        {8, 0, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/Sum"),
                                                        TARGET_STRING(""), 0, 0,                                                         2, 0, 1},
                                                        




















                                                        




                                                            



                                                                
                                                        
                                                        {9, 0, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/1//T0"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {10, 0, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Lapse Rate"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        






                                                        




                                                            



                                                                
                                                        
                                                        {11, 0, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/g//R"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        






                                                        




                                                            



                                                                
                                                        
                                                        {12, 0, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/rho0"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        















                                                        




                                                            



                                                                
                                                        
                                                        {13, 0, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Product"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {14, 0, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Product1"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {15, 0, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Product3"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {16, 0, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Limit  altitude  to Stratosphere"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {17, 0, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Limit  altitude  to troposhere"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {18, 0, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Sum"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {19, 0, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Sum1"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





































                                                        




                                                            



                                                                
                                                        
                                                        {20, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/p,q,r "),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {21, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/ub,vb,wb"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {22, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/xe,ye,ze"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {23, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Transpose"),
                                                        TARGET_STRING(""), 0, 0,                                                         3, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {24, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Product"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {25, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Sum"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        


























                                                        




                                                            



                                                                
                                                        
                                                        {26, 0, TARGET_STRING("rocketLIBRARY/Wind Shear Model/Wind speed at reference height"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 0},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {27, 0, TARGET_STRING("rocketLIBRARY/Wind Shear Model/h//z0"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        










                                                        




                                                            



                                                                
                                                        
                                                        {28, 0, TARGET_STRING("rocketLIBRARY/Wind Shear Model/ln(ref_height//z0)"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 0},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {29, 0, TARGET_STRING("rocketLIBRARY/Wind Shear Model/Product"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {30, 0, TARGET_STRING("rocketLIBRARY/Wind Shear Model/Product1"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {31, 0, TARGET_STRING("rocketLIBRARY/Wind Shear Model/Transform from Inertial to Body axes"),
                                                        TARGET_STRING(""), 0, 0,                                                         4, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {32, 0, TARGET_STRING("rocketLIBRARY/Wind Shear Model/3ft-->inf"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        
















































                                                        




                                                            



                                                                
                                                        
                                                        {33, 0, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap/Sum"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {34, 0, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap/Switch1"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 2},
                                                        

















































































                                                        




                                                            



                                                                
                                                        
                                                        {35, 0, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LongLat_offset/SinCos"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 0},
                                                        




                                                        




                                                            



                                                                
                                                        
                                                        {36, 0, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LongLat_offset/SinCos"),
                                                        TARGET_STRING(""), 1, 0,                                                         0, 0, 0},
                                                        
















                                                        




                                                            



                                                                
                                                        
                                                        {37, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate DCM & Euler Angles/phi theta psi"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        














                                                        




                                                            



                                                                
                                                        
                                                        {38, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate omega_dot/Product2"),
                                                        TARGET_STRING(""), 0, 0,                                                         5, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {39, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate omega_dot/Selector"),
                                                        TARGET_STRING(""), 0, 0,                                                         3, 0, 0},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {40, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate omega_dot/Selector1"),
                                                        TARGET_STRING(""), 0, 0,                                                         3, 0, 0},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {41, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate omega_dot/Selector2"),
                                                        TARGET_STRING(""), 0, 0,                                                         3, 0, 0},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {42, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate omega_dot/Sum2"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        













                                                        




                                                            



                                                                
                                                        
                                                        {43, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Determine Force,  Mass & Inertia/Sum"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        











                                                        




                                                            



                                                                
                                                        
                                                        {44, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Vbxw/Sum"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {45, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/transform to Inertial axes /Product"),
                                                        TARGET_STRING(""), 0, 0,                                                         4, 0, 1},
                                                        










                                                        




                                                            



                                                                
                                                        
                                                        {46, 0, TARGET_STRING("rocketLIBRARY/Wind Shear Model/Length Conversion/Unit Conversion"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        
















































































                                                        




                                                            



                                                                
                                                        
                                                        {47, 0, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Abs1"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        
















                                                        




                                                            



                                                                
                                                        
                                                        {48, 0, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Abs"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        












































                                                        




                                                            



                                                                
                                                        
                                                        {49, 0, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Switch"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 0},
                                                        

































                                                        




                                                            



                                                                
                                                        
                                                        {50, 0, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Switch"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 0},
                                                        



































































                                                        




                                                            



                                                                
                                                        
                                                        {51, 0, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Trigonometric Function1"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 0},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {52, 0, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Trigonometric Function2"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 0},
                                                        


















                                                        




                                                            

                                                        
                                                        {53, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn11"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            

                                                        
                                                        {54, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn12"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            

                                                        
                                                        {55, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn13"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            

                                                        
                                                        {56, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn21"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            

                                                        
                                                        {57, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn22"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            

                                                        
                                                        {58, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn23"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            

                                                        
                                                        {59, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn31"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            

                                                        
                                                        {60, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn32"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            

                                                        
                                                        {61, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Fcn33"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        












































                                                        




                                                            



                                                                
                                                        
                                                        {62, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate omega_dot/3x3 Cross Product/Sum"),
                                                        TARGET_STRING(""), 0, 0,                                                         1, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {63, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate omega_dot/I x w/Product"),
                                                        TARGET_STRING(""), 0, 0,                                                         4, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {64, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate omega_dot/I x w1/Product"),
                                                        TARGET_STRING(""), 0, 0,                                                         4, 0, 1},
                                                        










                                                        




                                                            



                                                                
                                                        
                                                        {65, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Determine Force,  Mass & Inertia/Mass input//output  momentum/Sum of Elements"),
                                                        TARGET_STRING(""), 0, 0,                                                         4, 0, 2},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {66, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Vbxw/Subsystem/i x j"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {67, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Vbxw/Subsystem/j x k"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {68, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Vbxw/Subsystem/k x i"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {69, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Vbxw/Subsystem1/i x k"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {70, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Vbxw/Subsystem1/j x i"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {71, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Vbxw/Subsystem1/k x j"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        































































                                                        




                                                            



                                                                
                                                        
                                                        {72, 0, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Abs"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        

























                                                        




                                                            



                                                                
                                                        
                                                        {73, 0, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Switch"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        
































































































































                                                        




                                                            



                                                                
                                                        
                                                        {74, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix/Vector Concatenate"),
                                                        TARGET_STRING(""), 0, 0,                                                         6, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {75, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate omega_dot/3x3 Cross Product/Subsystem/i x j"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {76, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate omega_dot/3x3 Cross Product/Subsystem/j x k"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {77, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate omega_dot/3x3 Cross Product/Subsystem/k x i"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {78, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate omega_dot/3x3 Cross Product/Subsystem1/i x k"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {79, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate omega_dot/3x3 Cross Product/Subsystem1/j x i"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        





                                                        




                                                            



                                                                
                                                        
                                                        {80, 0, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate omega_dot/3x3 Cross Product/Subsystem1/k x j"),
                                                        TARGET_STRING(""), 0, 0,                                                         0, 0, 1},
                                                        
















                                                        




                                                            



                                                                
                                                        
                                                        {81, 0, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant/Compare"),
                                                        TARGET_STRING(""), 0, 1,                                                         0, 0, 2},
                                                        










                        {
                            0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
                        }
                    };







                    static const rtwCAPI_BlockParameters rtBlockParameters[] = {

                        /* addrMapIndex, blockPath,
                        * paramName, dataTypeIndex, dimIndex, fixPtIdx
                        */

                                                        
                                                    
                                                    {82, TARGET_STRING("rocketLIBRARY/Aerodynamic Forces and Moments "),
                                                    TARGET_STRING("S"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {83, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA"),
                                                    TARGET_STRING("LL0"), 0, 7, 0},
                                                    
                                                        
                                                    
                                                    {84, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA"),
                                                    TARGET_STRING("psi"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {85, TARGET_STRING("rocketLIBRARY/Rocket Body Motions"),
                                                    TARGET_STRING("xme_0"), 0, 8, 0},
                                                    
                                                        
                                                    
                                                    {86, TARGET_STRING("rocketLIBRARY/Rocket Body Motions"),
                                                    TARGET_STRING("Vm_0"), 0, 8, 0},
                                                    
                                                        
                                                    
                                                    {87, TARGET_STRING("rocketLIBRARY/Rocket Body Motions"),
                                                    TARGET_STRING("eul_0"), 0, 8, 0},
                                                    
                                                        
                                                    
                                                    {88, TARGET_STRING("rocketLIBRARY/Rocket Body Motions"),
                                                    TARGET_STRING("pm_0"), 0, 8, 0},
                                                    
                                                        
                                                    
                                                    {89, TARGET_STRING("rocketLIBRARY/Wind Shear Model"),
                                                    TARGET_STRING("W_20"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {90, TARGET_STRING("rocketLIBRARY/Wind Shear Model"),
                                                    TARGET_STRING("Wdeg"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {91, TARGET_STRING("rocketLIBRARY/Constant"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {92, TARGET_STRING("rocketLIBRARY/Constant3"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {93, TARGET_STRING("rocketLIBRARY/Constant4"),
                                                    TARGET_STRING("Value"), 0, 3, 0},
                                                    
                                                        
                                                    
                                                    {94, TARGET_STRING("rocketLIBRARY/Constant5"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {95, TARGET_STRING("rocketLIBRARY/Constant6"),
                                                    TARGET_STRING("Value"), 0, 9, 0},
                                                    
                                                        
                                                    
                                                    {96, TARGET_STRING("rocketLIBRARY/Thrust"),
                                                    TARGET_STRING("Value"), 0, 8, 0},
                                                    
                                                        
                                                    
                                                    {97, TARGET_STRING("rocketLIBRARY/Thrust1"),
                                                    TARGET_STRING("Value"), 0, 8, 0},
                                                    
                                                        
                                                    
                                                    {98, TARGET_STRING("rocketLIBRARY/Switch"),
                                                    TARGET_STRING("Threshold"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {99, TARGET_STRING("rocketLIBRARY/Aerodynamic Forces and Moments /coefAdjust"),
                                                    TARGET_STRING("Gain"), 0, 8, 0},
                                                    
                                                        
                                                    
                                                    {100, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Altitude of Troposphere"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {101, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Constant"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {102, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Sea Level  Temperature"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {103, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/1//T0"),
                                                    TARGET_STRING("Gain"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {104, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Lapse Rate"),
                                                    TARGET_STRING("Gain"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {105, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/g//R"),
                                                    TARGET_STRING("Gain"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {106, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/rho0"),
                                                    TARGET_STRING("Gain"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {107, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Limit  altitude  to Stratosphere"),
                                                    TARGET_STRING("UpperLimit"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {108, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Limit  altitude  to Stratosphere"),
                                                    TARGET_STRING("LowerLimit"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {109, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Limit  altitude  to troposhere"),
                                                    TARGET_STRING("UpperLimit"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {110, TARGET_STRING("rocketLIBRARY/ISA Atmosphere Model/Limit  altitude  to troposhere"),
                                                    TARGET_STRING("LowerLimit"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {111, TARGET_STRING("rocketLIBRARY/Wind Shear Model/Wdeg1"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {112, TARGET_STRING("rocketLIBRARY/Wind Shear Model/ref_height//z0"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {113, TARGET_STRING("rocketLIBRARY/Wind Shear Model/h//z0"),
                                                    TARGET_STRING("Gain"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {114, TARGET_STRING("rocketLIBRARY/Wind Shear Model/3ft-->inf"),
                                                    TARGET_STRING("UpperLimit"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {115, TARGET_STRING("rocketLIBRARY/Wind Shear Model/3ft-->inf"),
                                                    TARGET_STRING("LowerLimit"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {116, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap/Constant"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {117, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap/Constant1"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {118, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Constant"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {119, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Constant1"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {120, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate DCM & Euler Angles/phi theta psi"),
                                                    TARGET_STRING("WrappedStateUpperValue"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {121, TARGET_STRING("rocketLIBRARY/Rocket Body Motions/Calculate DCM & Euler Angles/phi theta psi"),
                                                    TARGET_STRING("WrappedStateLowerValue"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {122, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant"),
                                                    TARGET_STRING("const"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {123, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant"),
                                                    TARGET_STRING("const"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {124, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant"),
                                                    TARGET_STRING("const"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {125, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Bias"),
                                                    TARGET_STRING("Bias"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {126, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Bias1"),
                                                    TARGET_STRING("Bias"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {127, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Gain"),
                                                    TARGET_STRING("Gain"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {128, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant"),
                                                    TARGET_STRING("const"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {129, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Bias"),
                                                    TARGET_STRING("Bias"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {130, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Bias1"),
                                                    TARGET_STRING("Bias"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {131, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Constant2"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {132, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {133, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant1"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {134, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant2"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {135, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant3"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {136, TARGET_STRING("rocketLIBRARY/Aerodynamic Forces and Moments /Moment Transformation/Direction Cosine Matrix Body to Wind/A32/Constant"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {137, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant"),
                                                    TARGET_STRING("const"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {138, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Bias"),
                                                    TARGET_STRING("Bias"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {139, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Bias1"),
                                                    TARGET_STRING("Bias"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {140, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Constant2"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {141, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant"),
                                                    TARGET_STRING("const"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {142, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Bias"),
                                                    TARGET_STRING("Bias"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {143, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Bias1"),
                                                    TARGET_STRING("Bias"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {144, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Constant2"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {145, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom/Constant"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {146, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e/Constant"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {147, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e/f"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                                                        
                                                    
                                                    {148, TARGET_STRING("rocketLIBRARY/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4/Constant"),
                                                    TARGET_STRING("Value"), 0, 0, 0},
                                                    
                        {
                            0, (NULL), (NULL), 0, 0, 0
                        }
                    };



                    static int_T rt_LoggedStateIdxList[] =                    {
                            -1
                    };

                    /* Root Inputs information */
                    static const rtwCAPI_Signals rtRootInputs[] = {

                        /* addrMapIndex, sysNum, blockPath,
                        * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
                        */




                        {
                            0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
                        }
                    };

                    /* Root Outputs information */
                    static const rtwCAPI_Signals rtRootOutputs[] = {

                        /* addrMapIndex, sysNum, blockPath,
                        * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
                        */



                        {
                            0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
                        }
                    };




                /* Tunable variable parameters */
                static const rtwCAPI_ModelParameters rtModelParameters[] = {

                    /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */

                    {0, (NULL), 0, 0, 0 }
                };





        








                    #ifndef HOST_CAPI_BUILD
                    /* Declare Data Addresses statically */
                    static void*  rtDataAddrMap[] = {
                            
                            &rtB.hcxyo5x1fp,                             /* 0: Signal */
                            
                            
                            &rtB.eweodspclo[0],                             /* 1: Signal */
                            
                            
                            &rtB.a5kvjjzqcc[0],                             /* 2: Signal */
                            
                            
                            &rtB.gsdo2pjwzd,                             /* 3: Signal */
                            
                            
                            &rtB.ntqzzqi1dc[0],                             /* 4: Signal */
                            
                            
                            &rtB.czkarcoix3[0],                             /* 5: Signal */
                            
                            
                            &rtB.beqzc5bw0r[0],                             /* 6: Signal */
                            
                            
                            &rtB.ppbw2ujmty[0],                             /* 7: Signal */
                            
                            
                            &rtB.ltespdje45[0],                             /* 8: Signal */
                            
                            
                            &rtB.efsisy4fdx[0],                             /* 9: Signal */
                            
                            
                            &rtB.az30op0bz1[0],                             /* 10: Signal */
                            
                            
                            &rtB.gus0dwpmta[0],                             /* 11: Signal */
                            
                            
                            &rtB.frtaiwzqi5[0],                             /* 12: Signal */
                            
                            
                            &rtB.pocvhehxoq[0],                             /* 13: Signal */
                            
                            
                            &rtB.ons4nt2sr3[0],                             /* 14: Signal */
                            
                            
                            &rtB.cs1icxkpbk[0],                             /* 15: Signal */
                            
                            
                            &rtB.bbyymkm3vn[0],                             /* 16: Signal */
                            
                            
                            &rtB.pzpb0aaq1i[0],                             /* 17: Signal */
                            
                            
                            &rtB.gx2bnlk0lw[0],                             /* 18: Signal */
                            
                            
                            &rtB.djlhbobpcq[0],                             /* 19: Signal */
                            
                            
                            &rtB.p1cjwgdban[0],                             /* 20: Signal */
                            
                            
                            &rtB.grafq4xnvz[0],                             /* 21: Signal */
                            
                            
                            &rtB.p0shvkceq5[0],                             /* 22: Signal */
                            
                            
                            &rtB.oe1t3pfjur[0],                             /* 23: Signal */
                            
                            
                            &rtB.k0esd4omu2[0],                             /* 24: Signal */
                            
                            
                            &rtB.o3epcvura2[0],                             /* 25: Signal */
                            
                            
                            &rtB.o2yo20byci[0],                             /* 26: Signal */
                            
                            
                            &rtB.hndudxkdvr[0],                             /* 27: Signal */
                            
                            
                            &rtB.glou0tzny0,                             /* 28: Signal */
                            
                            
                            &rtB.fvn3vgbif3[0],                             /* 29: Signal */
                            
                            
                            &rtB.jes3bzaku0[0],                             /* 30: Signal */
                            
                            
                            &rtB.nz4yxh1qfq[0],                             /* 31: Signal */
                            
                            
                            &rtB.kzzs5lii4k[0],                             /* 32: Signal */
                            
                            
                            &rtB.bzbu3yseb2,                             /* 33: Signal */
                            
                            
                            &rtB.apnu1iub5y,                             /* 34: Signal */
                            
                            
                            &rtB.legy4gcyuq,                             /* 35: Signal */
                            
                            
                            &rtB.pq2n04xswi,                             /* 36: Signal */
                            
                            
                            &rtB.gmtjwxhcc4[0],                             /* 37: Signal */
                            
                            
                            &rtB.hdpsy3sguu[0],                             /* 38: Signal */
                            
                            
                            &rtB.mqmfqguhsp[0],                             /* 39: Signal */
                            
                            
                            &rtB.i4ejkbvukm[0],                             /* 40: Signal */
                            
                            
                            &rtB.a2i2fdw0sz[0],                             /* 41: Signal */
                            
                            
                            &rtB.fpj41u20a1[0],                             /* 42: Signal */
                            
                            
                            &rtB.pjxjfknbqz[0],                             /* 43: Signal */
                            
                            
                            &rtB.lbvpk2cioa[0],                             /* 44: Signal */
                            
                            
                            &rtB.nycpslghoj[0],                             /* 45: Signal */
                            
                            
                            &rtB.eenfrxbcez[0],                             /* 46: Signal */
                            
                            
                            &rtB.cnuqgk0ctt,                             /* 47: Signal */
                            
                            
                            &rtB.dekfyvtcle,                             /* 48: Signal */
                            
                            
                            &rtB.idzov0xqov,                             /* 49: Signal */
                            
                            
                            &rtB.kf3nkdp1sm,                             /* 50: Signal */
                            
                            
                            &rtB.o0lznmwy04,                             /* 51: Signal */
                            
                            
                            &rtB.frkjltmijt,                             /* 52: Signal */
                            
                            
                            &rtB.nxlaprucin[0],                             /* 53: Signal */
                            
                            
                            ( &rtB.nxlaprucin[0] + 3),                             /* 54: Signal */
                            
                            
                            ( &rtB.nxlaprucin[0] + 6),                             /* 55: Signal */
                            
                            
                            ( &rtB.nxlaprucin[0] + 1),                             /* 56: Signal */
                            
                            
                            ( &rtB.nxlaprucin[0] + 4),                             /* 57: Signal */
                            
                            
                            ( &rtB.nxlaprucin[0] + 7),                             /* 58: Signal */
                            
                            
                            ( &rtB.nxlaprucin[0] + 2),                             /* 59: Signal */
                            
                            
                            ( &rtB.nxlaprucin[0] + 5),                             /* 60: Signal */
                            
                            
                            ( &rtB.nxlaprucin[0] + 8),                             /* 61: Signal */
                            
                            
                            &rtB.h4mpthrjzj[0],                             /* 62: Signal */
                            
                            
                            &rtB.mplveaosnc[0],                             /* 63: Signal */
                            
                            
                            &rtB.gaqfxcn5mu[0],                             /* 64: Signal */
                            
                            
                            &rtB.ivl5z2vmyi[0],                             /* 65: Signal */
                            
                            
                            &rtB.mbnstg1xrg,                             /* 66: Signal */
                            
                            
                            &rtB.czqbao5rcr,                             /* 67: Signal */
                            
                            
                            &rtB.ds0u1ctsfa,                             /* 68: Signal */
                            
                            
                            &rtB.mgaxq1x2cb,                             /* 69: Signal */
                            
                            
                            &rtB.cjk455jyf1,                             /* 70: Signal */
                            
                            
                            &rtB.jwmr4335zo,                             /* 71: Signal */
                            
                            
                            &rtB.f3grp50dae,                             /* 72: Signal */
                            
                            
                            &rtB.a4vnpcfi1i,                             /* 73: Signal */
                            
                            
                            &rtB.nxlaprucin[0],                             /* 74: Signal */
                            
                            
                            &rtB.fq0udmcr0d,                             /* 75: Signal */
                            
                            
                            &rtB.i25dx5gfjj,                             /* 76: Signal */
                            
                            
                            &rtB.azigzyu2ua,                             /* 77: Signal */
                            
                            
                            &rtB.osmqo5ipx2,                             /* 78: Signal */
                            
                            
                            &rtB.mxurwdq3rp,                             /* 79: Signal */
                            
                            
                            &rtB.n5my3rkxnx,                             /* 80: Signal */
                            
                            
                            &rtB.kjw21vg1pk,                             /* 81: Signal */
                            
                            
                            &rtP.AerodynamicForcesandMoments_S,                             /* 82: Mask Parameter */
                            
                            
                            &rtP.FlatEarthtoLLA_LL0[0],                             /* 83: Mask Parameter */
                            
                            
                            &rtP.FlatEarthtoLLA_psi,                             /* 84: Mask Parameter */
                            
                            
                            &rtP.RocketBodyMotions_xme_0[0],                             /* 85: Mask Parameter */
                            
                            
                            &rtP.RocketBodyMotions_Vm_0[0],                             /* 86: Mask Parameter */
                            
                            
                            &rtP.RocketBodyMotions_eul_0[0],                             /* 87: Mask Parameter */
                            
                            
                            &rtP.RocketBodyMotions_pm_0[0],                             /* 88: Mask Parameter */
                            
                            
                            &rtP.WindShearModel_W_20,                             /* 89: Mask Parameter */
                            
                            
                            &rtP.WindShearModel_Wdeg,                             /* 90: Mask Parameter */
                            
                            
                            &rtP.Constant_Value_i4rpol133v,                             /* 91: Block Parameter */
                            
                            
                            &rtP.Constant3_Value,                             /* 92: Block Parameter */
                            
                            
                            &rtP.Constant4_Value[0],                             /* 93: Block Parameter */
                            
                            
                            &rtP.Constant5_Value,                             /* 94: Block Parameter */
                            
                            
                            &rtP.Constant6_Value[0],                             /* 95: Block Parameter */
                            
                            
                            &rtP.Thrust_Value[0],                             /* 96: Block Parameter */
                            
                            
                            &rtP.Thrust1_Value[0],                             /* 97: Block Parameter */
                            
                            
                            &rtP.Switch_Threshold,                             /* 98: Block Parameter */
                            
                            
                            &rtP.coefAdjust_Gain[0],                             /* 99: Block Parameter */
                            
                            
                            &rtP.AltitudeofTroposphere_Value,                             /* 100: Block Parameter */
                            
                            
                            &rtP.Constant_Value_f1hpxzhsax,                             /* 101: Block Parameter */
                            
                            
                            &rtP.SeaLevelTemperature_Value,                             /* 102: Block Parameter */
                            
                            
                            &rtP.uT0_Gain,                             /* 103: Block Parameter */
                            
                            
                            &rtP.LapseRate_Gain,                             /* 104: Block Parameter */
                            
                            
                            &rtP.gR_Gain,                             /* 105: Block Parameter */
                            
                            
                            &rtP.rho0_Gain,                             /* 106: Block Parameter */
                            
                            
                            &rtP.LimitaltitudetoStratosphere_UpperSat,                             /* 107: Block Parameter */
                            
                            
                            &rtP.LimitaltitudetoStratosphere_LowerSat,                             /* 108: Block Parameter */
                            
                            
                            &rtP.Limitaltitudetotroposhere_UpperSat,                             /* 109: Block Parameter */
                            
                            
                            &rtP.Limitaltitudetotroposhere_LowerSat,                             /* 110: Block Parameter */
                            
                            
                            &rtP.Wdeg1_Value,                             /* 111: Block Parameter */
                            
                            
                            &rtP.ref_heightz0_Value,                             /* 112: Block Parameter */
                            
                            
                            &rtP.hz0_Gain,                             /* 113: Block Parameter */
                            
                            
                            &rtP.uftinf_UpperSat,                             /* 114: Block Parameter */
                            
                            
                            &rtP.uftinf_LowerSat,                             /* 115: Block Parameter */
                            
                            
                            &rtP.Constant_Value_ky3avngojs,                             /* 116: Block Parameter */
                            
                            
                            &rtP.Constant1_Value,                             /* 117: Block Parameter */
                            
                            
                            &rtP.Constant_Value_gxkbwrysrc,                             /* 118: Block Parameter */
                            
                            
                            &rtP.Constant1_Value_dgld0ymnit,                             /* 119: Block Parameter */
                            
                            
                            &rtP.phithetapsi_WrappedStateUpperValue,                             /* 120: Block Parameter */
                            
                            
                            &rtP.phithetapsi_WrappedStateLowerValue,                             /* 121: Block Parameter */
                            
                            
                            &rtP.CompareToConstant_const,                             /* 122: Mask Parameter */
                            
                            
                            &rtP.CompareToConstant_const_eds1jbkaw1,                             /* 123: Mask Parameter */
                            
                            
                            &rtP.CompareToConstant_const_nv04wgg20q,                             /* 124: Mask Parameter */
                            
                            
                            &rtP.Bias_Bias_dzgopcrirx,                             /* 125: Block Parameter */
                            
                            
                            &rtP.Bias1_Bias_fmis1slqel,                             /* 126: Block Parameter */
                            
                            
                            &rtP.Gain_Gain,                             /* 127: Block Parameter */
                            
                            
                            &rtP.CompareToConstant_const_cbnqt4m3vq,                             /* 128: Mask Parameter */
                            
                            
                            &rtP.Bias_Bias_afrbxfkpq4,                             /* 129: Block Parameter */
                            
                            
                            &rtP.Bias1_Bias_jpxdd4e1oi,                             /* 130: Block Parameter */
                            
                            
                            &rtP.Constant2_Value_mbyiuuie40,                             /* 131: Block Parameter */
                            
                            
                            &rtP.Constant_Value_cg2fb4qko2,                             /* 132: Block Parameter */
                            
                            
                            &rtP.Constant1_Value_f3g5vycunl,                             /* 133: Block Parameter */
                            
                            
                            &rtP.Constant2_Value_fmjdnwbdte,                             /* 134: Block Parameter */
                            
                            
                            &rtP.Constant3_Value_jtpisyudw2,                             /* 135: Block Parameter */
                            
                            
                            &rtP.Constant_Value,                             /* 136: Block Parameter */
                            
                            
                            &rtP.CompareToConstant_const_pwri3oqztp,                             /* 137: Mask Parameter */
                            
                            
                            &rtP.Bias_Bias,                             /* 138: Block Parameter */
                            
                            
                            &rtP.Bias1_Bias,                             /* 139: Block Parameter */
                            
                            
                            &rtP.Constant2_Value,                             /* 140: Block Parameter */
                            
                            
                            &rtP.CompareToConstant_const_abt4xuk4oi,                             /* 141: Mask Parameter */
                            
                            
                            &rtP.Bias_Bias_dw3it2mgbt,                             /* 142: Block Parameter */
                            
                            
                            &rtP.Bias1_Bias_jixhqnsnsh,                             /* 143: Block Parameter */
                            
                            
                            &rtP.Constant2_Value_njsj4azasy,                             /* 144: Block Parameter */
                            
                            
                            &rtP.Constant_Value_k4mkjjrubk,                             /* 145: Block Parameter */
                            
                            
                            &rtP.Constant_Value_pjdesp3rvm,                             /* 146: Block Parameter */
                            
                            
                            &rtP.f_Value,                             /* 147: Block Parameter */
                            
                            
                            &rtP.Constant_Value_kdka53fglp,                             /* 148: Block Parameter */
                            
                    };

                    /* Declare Data Run-Time Dimension Buffer Addresses statically */
                    static int32_T*  rtVarDimsAddrMap[] = {
                        (NULL)
                    };
                    #endif



        /* Data Type Map - use dataTypeMapIndex to access this structure */
        static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {

            /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
            * isComplex, isPointer, enumStorageType */

                    {"double", "real_T", 0, 0, sizeof(real_T), (uint8_T)SS_DOUBLE, 0, 0, 0},
                {"unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), (uint8_T)SS_BOOLEAN, 0, 0, 0}
        };

        #ifdef HOST_CAPI_BUILD
        #undef sizeof
        #endif

        /* Structure Element Map - use elemMapIndex to access this structure */
        static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {

            /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */

            {(NULL), 0, 0, 0, 0},
        };

        /* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
        static const rtwCAPI_DimensionMap rtDimensionMap[] = {

            /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */

                    {rtwCAPI_SCALAR, 0, 2, 0},
                    {rtwCAPI_VECTOR, 2, 2, 0},
                    {rtwCAPI_VECTOR, 4, 2, 0},
                    {rtwCAPI_MATRIX_COL_MAJOR, 6, 2, 0},
                    {rtwCAPI_MATRIX_COL_MAJOR, 2, 2, 0},
                    {rtwCAPI_MATRIX_COL_MAJOR, 8, 2, 0},
                    {rtwCAPI_VECTOR, 10, 2, 0},
                    {rtwCAPI_VECTOR, 12, 2, 0},
                    {rtwCAPI_VECTOR, 8, 2, 0},
                {rtwCAPI_VECTOR, 14, 2, 0}
        };

        /* Dimension Array- use dimArrayIndex to access elements of this array */
            static const uint_T rtDimensionArray[] = {
                    1,                    /* 0 */
                    1,                    /* 1 */
                    3,                    /* 2 */
                    1,                    /* 3 */
                    2,                    /* 4 */
                    1,                    /* 5 */
                    3,                    /* 6 */
                    3,                    /* 7 */
                    1,                    /* 8 */
                    3,                    /* 9 */
                    9,                    /* 10 */
                    1,                    /* 11 */
                    1,                    /* 12 */
                    2,                    /* 13 */
                    1,                    /* 14 */
                6                 /* 15 */
            };

            /* C-API stores floating point values in an array. The elements of this  *
            * are unique. This ensures that values which are shared across the model*
            * are stored in the most efficient way. These values are referenced by  *
            *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
            *           - rtwCAPI_FixPtMap.biasPtr,                                 *
            *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
            *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */


            static const real_T rtcapiStoredFloats[] = {
                    0.0,                1.0
            };
        /* Fixed Point Map */
        static const rtwCAPI_FixPtMap rtFixPtMap[] = {

            /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */

            {(NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, (boolean_T)0 },
        };

        /* Sample Time Map - use sTimeIndex to access elements of ths structure */
        static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {

            /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */

                    {(NULL),(NULL), 3, 0},
                    {(const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[0], (int8_T)0, (uint8_T)0},
                {(const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1], (int8_T)1, (uint8_T)0}
        };












        static rtwCAPI_ModelMappingStaticInfo mmiStatic = {

            /* Signals:{signals, numSignals,
            *           rootInputs, numRootInputs,
            *           rootOutputs, numRootOutputs},
            * Params: {blockParameters, numBlockParameters,
            *          modelParameters, numModelParameters},
            * States: {states, numStates},
            * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
            *          elementMap, sampleTimeMap, dimensionArray},
            * TargetType: targetType
            */

                {rtBlockSignals, 82,
                rtRootInputs, 0,
                rtRootOutputs, 0},
                {rtBlockParameters, 67,
                rtModelParameters, 0},
                {(NULL), 0},
            {rtDataTypeMap, rtDimensionMap, rtFixPtMap,
            rtElementMap, rtSampleTimeMap, rtDimensionArray},
            "float",
            {3658516348U,
            1159428955U,
            3784968166U,
            3035424888U},
            (NULL), 0,
            (boolean_T)0
                ,rt_LoggedStateIdxList
        };

        /* Function to get C API Model Mapping Static Info */
        const rtwCAPI_ModelMappingStaticInfo*
        rocketLIBRARY_GetCAPIStaticMap(void) {
            return &mmiStatic;
        }



    






        
    #ifndef HOST_CAPI_BUILD
    void rocketLIBRARY_InitializeDataMapInfo(void) {





        /* Set C-API version */
        rtwCAPI_SetVersion((*rt_dataMapInfoPtr).mmi, 1);

        /* Cache static C-API data into the Real-time Model Data structure */
        rtwCAPI_SetStaticMap((*rt_dataMapInfoPtr).mmi, &mmiStatic);

        /* Cache static C-API logging data into the Real-time Model Data structure */
        rtwCAPI_SetLoggingStaticMap((*rt_dataMapInfoPtr).mmi, (NULL));

            /* Cache C-API Data Addresses into the Real-Time Model Data structure */
            rtwCAPI_SetDataAddressMap((*rt_dataMapInfoPtr).mmi, rtDataAddrMap);

            /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
            rtwCAPI_SetVarDimsAddressMap((*rt_dataMapInfoPtr).mmi, rtVarDimsAddrMap);


        /* Cache the instance C-API logging pointer */
            rtwCAPI_SetInstanceLoggingInfo((*rt_dataMapInfoPtr).mmi, (NULL));

        /* Set reference to submodels */
            rtwCAPI_SetChildMMIArray((*rt_dataMapInfoPtr).mmi, (NULL));
            rtwCAPI_SetChildMMIArrayLen((*rt_dataMapInfoPtr).mmi, 0);



    }
    #else /* HOST_CAPI_BUILD */

    #ifdef __cplusplus
    extern "C" {
        #endif

        void rocketLIBRARY_host_InitializeDataMapInfo(rocketLIBRARY_host_DataMapInfo_T *dataMap, const char *path) {

            /* Set C-API version */
            rtwCAPI_SetVersion(dataMap->mmi, 1);

            /* Cache static C-API data into the Real-time Model Data structure */
            rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

            /* host data address map is NULL */
            rtwCAPI_SetDataAddressMap(dataMap->mmi, (NULL));

            /* host vardims address map is NULL */
            rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, (NULL));

            /* Set Instance specific path */
            rtwCAPI_SetPath(dataMap->mmi, path);

            rtwCAPI_SetFullPath(dataMap->mmi, (NULL));

            /* Set reference to submodels */

                rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
                rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);

        }

        #ifdef __cplusplus
    }
    #endif

    #endif /* HOST_CAPI_BUILD */

        


        /* EOF: rocketLIBRARY_capi.c */
