    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 67;
            section.data(67)  = dumData; %prealloc

                    ;% rtP.FlatEarthtoLLA_LL0
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.AerodynamicForcesandMoments_S
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% rtP.RocketBodyMotions_Vm_0
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 3;

                    ;% rtP.WindShearModel_W_20
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 6;

                    ;% rtP.WindShearModel_Wdeg
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 7;

                    ;% rtP.CompareToConstant_const
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 8;

                    ;% rtP.CompareToConstant_const_pwri3oqztp
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 9;

                    ;% rtP.CompareToConstant_const_eds1jbkaw1
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 10;

                    ;% rtP.CompareToConstant_const_abt4xuk4oi
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 11;

                    ;% rtP.CompareToConstant_const_nv04wgg20q
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 12;

                    ;% rtP.CompareToConstant_const_cbnqt4m3vq
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 13;

                    ;% rtP.RocketBodyMotions_eul_0
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 14;

                    ;% rtP.RocketBodyMotions_pm_0
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 17;

                    ;% rtP.FlatEarthtoLLA_psi
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 20;

                    ;% rtP.RocketBodyMotions_xme_0
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 21;

                    ;% rtP.Bias_Bias
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 24;

                    ;% rtP.Bias1_Bias
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 25;

                    ;% rtP.phithetapsi_WrappedStateUpperValue
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 26;

                    ;% rtP.phithetapsi_WrappedStateLowerValue
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 27;

                    ;% rtP.Switch_Threshold
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 28;

                    ;% rtP.uftinf_UpperSat
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 29;

                    ;% rtP.uftinf_LowerSat
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 30;

                    ;% rtP.hz0_Gain
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 31;

                    ;% rtP.Limitaltitudetotroposhere_UpperSat
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 32;

                    ;% rtP.Limitaltitudetotroposhere_LowerSat
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 33;

                    ;% rtP.LapseRate_Gain
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 34;

                    ;% rtP.uT0_Gain
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 35;

                    ;% rtP.rho0_Gain
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 36;

                    ;% rtP.LimitaltitudetoStratosphere_UpperSat
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 37;

                    ;% rtP.LimitaltitudetoStratosphere_LowerSat
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 38;

                    ;% rtP.gR_Gain
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 39;

                    ;% rtP.Constant_Value
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 40;

                    ;% rtP.Constant6_Value
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 41;

                    ;% rtP.coefAdjust_Gain
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 47;

                    ;% rtP.Constant_Value_i4rpol133v
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 50;

                    ;% rtP.Constant3_Value
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 51;

                    ;% rtP.Constant4_Value
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 52;

                    ;% rtP.Constant5_Value
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 61;

                    ;% rtP.Constant_Value_ky3avngojs
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 62;

                    ;% rtP.Constant1_Value
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 63;

                    ;% rtP.Constant2_Value
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 64;

                    ;% rtP.Constant_Value_gxkbwrysrc
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 65;

                    ;% rtP.Constant1_Value_dgld0ymnit
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 66;

                    ;% rtP.Bias_Bias_dw3it2mgbt
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 67;

                    ;% rtP.Constant2_Value_njsj4azasy
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 68;

                    ;% rtP.Bias1_Bias_jixhqnsnsh
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 69;

                    ;% rtP.Bias_Bias_dzgopcrirx
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 70;

                    ;% rtP.Gain_Gain
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 71;

                    ;% rtP.Bias1_Bias_fmis1slqel
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 72;

                    ;% rtP.Bias_Bias_afrbxfkpq4
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 73;

                    ;% rtP.Constant2_Value_mbyiuuie40
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 74;

                    ;% rtP.Bias1_Bias_jpxdd4e1oi
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 75;

                    ;% rtP.Constant_Value_cg2fb4qko2
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 76;

                    ;% rtP.Constant1_Value_f3g5vycunl
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 77;

                    ;% rtP.Constant2_Value_fmjdnwbdte
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 78;

                    ;% rtP.Constant3_Value_jtpisyudw2
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 79;

                    ;% rtP.Constant_Value_k4mkjjrubk
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 80;

                    ;% rtP.Constant_Value_kdka53fglp
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 81;

                    ;% rtP.Constant_Value_pjdesp3rvm
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 82;

                    ;% rtP.f_Value
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 83;

                    ;% rtP.AltitudeofTroposphere_Value
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 84;

                    ;% rtP.Constant_Value_f1hpxzhsax
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 85;

                    ;% rtP.SeaLevelTemperature_Value
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 86;

                    ;% rtP.Thrust_Value
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 87;

                    ;% rtP.Thrust1_Value
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 90;

                    ;% rtP.Wdeg1_Value
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 93;

                    ;% rtP.ref_heightz0_Value
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 94;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 76;
            section.data(76)  = dumData; %prealloc

                    ;% rtB.p0shvkceq5
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.gmtjwxhcc4
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% rtB.ntqzzqi1dc
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 6;

                    ;% rtB.gsdo2pjwzd
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 9;

                    ;% rtB.bvik5bxnsw
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 10;

                    ;% rtB.nxlaprucin
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 13;

                    ;% rtB.eenfrxbcez
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 22;

                    ;% rtB.kzzs5lii4k
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 25;

                    ;% rtB.hndudxkdvr
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 28;

                    ;% rtB.fvn3vgbif3
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 31;

                    ;% rtB.jes3bzaku0
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 34;

                    ;% rtB.nz4yxh1qfq
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 37;

                    ;% rtB.pzpb0aaq1i
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 40;

                    ;% rtB.az30op0bz1
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 43;

                    ;% rtB.djlhbobpcq
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 46;

                    ;% rtB.efsisy4fdx
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 49;

                    ;% rtB.pocvhehxoq
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 52;

                    ;% rtB.frtaiwzqi5
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 55;

                    ;% rtB.gx2bnlk0lw
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 58;

                    ;% rtB.bbyymkm3vn
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 61;

                    ;% rtB.gus0dwpmta
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 64;

                    ;% rtB.ons4nt2sr3
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 67;

                    ;% rtB.cs1icxkpbk
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 70;

                    ;% rtB.eweodspclo
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 73;

                    ;% rtB.beqzc5bw0r
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 76;

                    ;% rtB.ppbw2ujmty
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 79;

                    ;% rtB.a5kvjjzqcc
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 82;

                    ;% rtB.ltespdje45
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 85;

                    ;% rtB.f3grp50dae
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 87;

                    ;% rtB.a4vnpcfi1i
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 88;

                    ;% rtB.cnuqgk0ctt
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 89;

                    ;% rtB.apnu1iub5y
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 90;

                    ;% rtB.bzbu3yseb2
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 91;

                    ;% rtB.dekfyvtcle
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 92;

                    ;% rtB.p1cjwgdban
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 93;

                    ;% rtB.jrvb2m0kwj
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 96;

                    ;% rtB.mplveaosnc
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 99;

                    ;% rtB.fq0udmcr0d
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 102;

                    ;% rtB.i25dx5gfjj
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 103;

                    ;% rtB.azigzyu2ua
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 104;

                    ;% rtB.osmqo5ipx2
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 105;

                    ;% rtB.mxurwdq3rp
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 106;

                    ;% rtB.n5my3rkxnx
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 107;

                    ;% rtB.h4mpthrjzj
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 108;

                    ;% rtB.gaqfxcn5mu
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 111;

                    ;% rtB.fpj41u20a1
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 114;

                    ;% rtB.hdpsy3sguu
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 117;

                    ;% rtB.ivl5z2vmyi
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 120;

                    ;% rtB.pjxjfknbqz
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 123;

                    ;% rtB.k0esd4omu2
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 126;

                    ;% rtB.grafq4xnvz
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 129;

                    ;% rtB.czqbao5rcr
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 132;

                    ;% rtB.ds0u1ctsfa
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 133;

                    ;% rtB.mbnstg1xrg
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 134;

                    ;% rtB.jwmr4335zo
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 135;

                    ;% rtB.mgaxq1x2cb
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 136;

                    ;% rtB.cjk455jyf1
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 137;

                    ;% rtB.lbvpk2cioa
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 138;

                    ;% rtB.o3epcvura2
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 141;

                    ;% rtB.oe1t3pfjur
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 144;

                    ;% rtB.nycpslghoj
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 153;

                    ;% rtB.czkarcoix3
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 156;

                    ;% rtB.idzov0xqov
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 159;

                    ;% rtB.kf3nkdp1sm
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 160;

                    ;% rtB.o0lznmwy04
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 161;

                    ;% rtB.frkjltmijt
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 162;

                    ;% rtB.legy4gcyuq
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 163;

                    ;% rtB.pq2n04xswi
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 164;

                    ;% rtB.hcxyo5x1fp
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 165;

                    ;% rtB.mqmfqguhsp
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 166;

                    ;% rtB.i4ejkbvukm
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 175;

                    ;% rtB.a2i2fdw0sz
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 184;

                    ;% rtB.k52s5q41hk
                    section.data(73).logicalSrcIdx = 72;
                    section.data(73).dtTransOffset = 193;

                    ;% rtB.o2yo20byci
                    section.data(74).logicalSrcIdx = 73;
                    section.data(74).dtTransOffset = 196;

                    ;% rtB.glou0tzny0
                    section.data(75).logicalSrcIdx = 74;
                    section.data(75).dtTransOffset = 199;

                    ;% rtB.jellcacuop
                    section.data(76).logicalSrcIdx = 75;
                    section.data(76).dtTransOffset = 200;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.kjw21vg1pk
                    section.data(1).logicalSrcIdx = 76;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 5;
        sectIdxOffset = 2;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.dyg4fa5n4f
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.awyzpux4va.LoggedData
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% rtDW.k3zlzo4rka
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.eyovwuix3c
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 3;

                    ;% rtDW.ljats3taij
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 6;

                    ;% rtDW.kmks0kqlp2
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 9;

                    ;% rtDW.nentsm3ztg
                    section.data(5).logicalSrcIdx = 6;
                    section.data(5).dtTransOffset = 10;

                    ;% rtDW.lzyi1v2xh5
                    section.data(6).logicalSrcIdx = 7;
                    section.data(6).dtTransOffset = 11;

                    ;% rtDW.gbjv2wu0pg
                    section.data(7).logicalSrcIdx = 8;
                    section.data(7).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtDW.pyhu0x3txh
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.n0rsg5tawa
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.lyamxhsgtb
                    section.data(3).logicalSrcIdx = 11;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.iez3ymddrk
                    section.data(4).logicalSrcIdx = 12;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.k4tj0ddmtk
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.i3cpbuohc4
                    section.data(2).logicalSrcIdx = 14;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.j0vp3pypgy
                    section.data(3).logicalSrcIdx = 15;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 3658516348;
    targMap.checksum1 = 1159428955;
    targMap.checksum2 = 3784968166;
    targMap.checksum3 = 3035424888;

