#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Final_Project_Bot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Final_Project_Bot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/AD.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/LED.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/BOARD.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/main.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/serial.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/pwm.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/bot_Movement.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/bot_Sensor.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/78702576/AD.o ${OBJECTDIR}/_ext/78702576/LED.o ${OBJECTDIR}/_ext/78702576/BOARD.o ${OBJECTDIR}/_ext/78702576/main.o ${OBJECTDIR}/_ext/78702576/serial.o ${OBJECTDIR}/_ext/78702576/pwm.o ${OBJECTDIR}/_ext/78702576/bot_Movement.o ${OBJECTDIR}/_ext/78702576/bot_Sensor.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/78702576/AD.o.d ${OBJECTDIR}/_ext/78702576/LED.o.d ${OBJECTDIR}/_ext/78702576/BOARD.o.d ${OBJECTDIR}/_ext/78702576/main.o.d ${OBJECTDIR}/_ext/78702576/serial.o.d ${OBJECTDIR}/_ext/78702576/pwm.o.d ${OBJECTDIR}/_ext/78702576/bot_Movement.o.d ${OBJECTDIR}/_ext/78702576/bot_Sensor.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/78702576/AD.o ${OBJECTDIR}/_ext/78702576/LED.o ${OBJECTDIR}/_ext/78702576/BOARD.o ${OBJECTDIR}/_ext/78702576/main.o ${OBJECTDIR}/_ext/78702576/serial.o ${OBJECTDIR}/_ext/78702576/pwm.o ${OBJECTDIR}/_ext/78702576/bot_Movement.o ${OBJECTDIR}/_ext/78702576/bot_Sensor.o

# Source Files
SOURCEFILES=C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/AD.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/LED.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/BOARD.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/main.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/serial.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/pwm.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/bot_Movement.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/bot_Sensor.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Final_Project_Bot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX320F128H
MP_LINKER_FILE_OPTION=,--script="C:\Users\seens\OneDrive\Desktop\ECE_118_Final_Project\Final_Project_Bot.X\bootloader320.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/78702576/AD.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/AD.c  .generated_files/flags/default/e5738de77a92cd75c4b998ba720e70172195b9dc .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/AD.o.d" -o ${OBJECTDIR}/_ext/78702576/AD.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/AD.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/LED.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/LED.c  .generated_files/flags/default/a0767cb3f30a270494cbdf79a18a0d690afb3741 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/LED.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/LED.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/LED.o.d" -o ${OBJECTDIR}/_ext/78702576/LED.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/LED.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/BOARD.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/BOARD.c  .generated_files/flags/default/a0c876a81d84cfe5a93adf4a5ec4953aaedc03c8 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/BOARD.o.d" -o ${OBJECTDIR}/_ext/78702576/BOARD.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/BOARD.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/main.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/main.c  .generated_files/flags/default/d0364456c99058f02d5826a170009d199240553a .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/main.o.d" -o ${OBJECTDIR}/_ext/78702576/main.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/serial.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/serial.c  .generated_files/flags/default/29ac7d8323b27db21adcbe20d93011f982147fb .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/serial.o.d" -o ${OBJECTDIR}/_ext/78702576/serial.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/serial.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/pwm.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/pwm.c  .generated_files/flags/default/d84caac1fea3d26c30761f9a1c22d9a5184d2ef6 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/pwm.o.d" -o ${OBJECTDIR}/_ext/78702576/pwm.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/pwm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/bot_Movement.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/bot_Movement.c  .generated_files/flags/default/42d7db4288221cf4dc28d3166fdc540b09315cfb .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/bot_Movement.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/bot_Movement.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/bot_Movement.o.d" -o ${OBJECTDIR}/_ext/78702576/bot_Movement.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/bot_Movement.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/bot_Sensor.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/bot_Sensor.c  .generated_files/flags/default/7c4dd25ea8da8443526a0c18ff74342cd406979d .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/bot_Sensor.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/bot_Sensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/bot_Sensor.o.d" -o ${OBJECTDIR}/_ext/78702576/bot_Sensor.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/bot_Sensor.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/78702576/AD.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/AD.c  .generated_files/flags/default/732c35f8defb5303730abb43d4cc7e60966f0012 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/AD.o.d" -o ${OBJECTDIR}/_ext/78702576/AD.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/AD.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/LED.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/LED.c  .generated_files/flags/default/fbd5d1efe08bac8ccb78bc4c6c16284f515a99a .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/LED.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/LED.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/LED.o.d" -o ${OBJECTDIR}/_ext/78702576/LED.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/LED.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/BOARD.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/BOARD.c  .generated_files/flags/default/97b5505fbfed222f526c79f9290ffc5a8fd6029c .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/BOARD.o.d" -o ${OBJECTDIR}/_ext/78702576/BOARD.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/BOARD.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/main.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/main.c  .generated_files/flags/default/8bbe558f1e7381f97f490a71b6836a5bf235601 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/main.o.d" -o ${OBJECTDIR}/_ext/78702576/main.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/serial.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/serial.c  .generated_files/flags/default/4a78bfae8dd7fdc748d78c8a1ce76782e1615a .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/serial.o.d" -o ${OBJECTDIR}/_ext/78702576/serial.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/serial.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/pwm.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/pwm.c  .generated_files/flags/default/596c58ad39fcdf3e804a9ce62e9826c60978833 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/pwm.o.d" -o ${OBJECTDIR}/_ext/78702576/pwm.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/pwm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/bot_Movement.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/bot_Movement.c  .generated_files/flags/default/7bf56c1dd4d4e78499a0f1b6e15fd5e4a9d18425 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/bot_Movement.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/bot_Movement.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/bot_Movement.o.d" -o ${OBJECTDIR}/_ext/78702576/bot_Movement.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/bot_Movement.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/bot_Sensor.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/bot_Sensor.c  .generated_files/flags/default/d35a60eced1ff1757299f76ad6cabc1841c055e6 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/bot_Sensor.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/bot_Sensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/bot_Sensor.o.d" -o ${OBJECTDIR}/_ext/78702576/bot_Sensor.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/bot_Sensor.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Final_Project_Bot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/bootloader320.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Final_Project_Bot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Final_Project_Bot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/bootloader320.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Final_Project_Bot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Final_Project_Bot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
