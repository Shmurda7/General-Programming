

    /*
* rocketLIBRARY_private.h
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


    #ifndef RTW_HEADER_rocketLIBRARY_private_h_
    #define RTW_HEADER_rocketLIBRARY_private_h_



                #include "rtwtypes.h"
            #include "builtin_typeid_types.h"
            #include "multiword_types.h"


#include "rocketLIBRARY_types.h"


    

    

    

    
                #if !defined(rt_VALIDATE_MEMORY)
                #define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
    ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
    }
    #endif

    #if !defined(rt_FREE)
        #if !defined(_WIN32)
    #define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((ptr));\
    (ptr) = (NULL);\
    }
    #else
    /* Visual and other windows compilers declare free without const */
    #define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((void *)(ptr));\
    (ptr) = (NULL);\
    }
    #endif
    #endif




    

    

    

    

    

    

    

    

    

                

                                 extern void rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf(const real_T u0[3], const real_T u1[9], real_T y[3]);
                




    

    

    

        
        #if defined(MULTITASKING)
        #  error Models using the variable step solvers cannot define MULTITASKING
        #endif


    

    

    

    #endif /* RTW_HEADER_rocketLIBRARY_private_h_ */
