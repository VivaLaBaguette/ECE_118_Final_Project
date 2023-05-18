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
SOURCEFILES_QUOTED_IF_SPACED=C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/AD.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/LED.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/BOARD.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/main.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/serial.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_CheckEvents.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Framework.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_KeyboardInput.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_PostList.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Queue.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_TattleTale.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Timers.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/IO_Ports.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/pwm.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/78702576/AD.o ${OBJECTDIR}/_ext/78702576/LED.o ${OBJECTDIR}/_ext/78702576/BOARD.o ${OBJECTDIR}/_ext/78702576/main.o ${OBJECTDIR}/_ext/78702576/serial.o ${OBJECTDIR}/_ext/78702576/ES_CheckEvents.o ${OBJECTDIR}/_ext/78702576/ES_Framework.o ${OBJECTDIR}/_ext/78702576/ES_KeyboardInput.o ${OBJECTDIR}/_ext/78702576/ES_PostList.o ${OBJECTDIR}/_ext/78702576/ES_Queue.o ${OBJECTDIR}/_ext/78702576/ES_TattleTale.o ${OBJECTDIR}/_ext/78702576/ES_Timers.o ${OBJECTDIR}/_ext/78702576/IO_Ports.o ${OBJECTDIR}/_ext/78702576/pwm.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/78702576/AD.o.d ${OBJECTDIR}/_ext/78702576/LED.o.d ${OBJECTDIR}/_ext/78702576/BOARD.o.d ${OBJECTDIR}/_ext/78702576/main.o.d ${OBJECTDIR}/_ext/78702576/serial.o.d ${OBJECTDIR}/_ext/78702576/ES_CheckEvents.o.d ${OBJECTDIR}/_ext/78702576/ES_Framework.o.d ${OBJECTDIR}/_ext/78702576/ES_KeyboardInput.o.d ${OBJECTDIR}/_ext/78702576/ES_PostList.o.d ${OBJECTDIR}/_ext/78702576/ES_Queue.o.d ${OBJECTDIR}/_ext/78702576/ES_TattleTale.o.d ${OBJECTDIR}/_ext/78702576/ES_Timers.o.d ${OBJECTDIR}/_ext/78702576/IO_Ports.o.d ${OBJECTDIR}/_ext/78702576/pwm.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/78702576/AD.o ${OBJECTDIR}/_ext/78702576/LED.o ${OBJECTDIR}/_ext/78702576/BOARD.o ${OBJECTDIR}/_ext/78702576/main.o ${OBJECTDIR}/_ext/78702576/serial.o ${OBJECTDIR}/_ext/78702576/ES_CheckEvents.o ${OBJECTDIR}/_ext/78702576/ES_Framework.o ${OBJECTDIR}/_ext/78702576/ES_KeyboardInput.o ${OBJECTDIR}/_ext/78702576/ES_PostList.o ${OBJECTDIR}/_ext/78702576/ES_Queue.o ${OBJECTDIR}/_ext/78702576/ES_TattleTale.o ${OBJECTDIR}/_ext/78702576/ES_Timers.o ${OBJECTDIR}/_ext/78702576/IO_Ports.o ${OBJECTDIR}/_ext/78702576/pwm.o

# Source Files
SOURCEFILES=C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/AD.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/LED.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/BOARD.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/main.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/serial.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_CheckEvents.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Framework.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_KeyboardInput.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_PostList.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Queue.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_TattleTale.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Timers.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/IO_Ports.c C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/pwm.c



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
	
${OBJECTDIR}/_ext/78702576/ES_CheckEvents.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_CheckEvents.c  .generated_files/flags/default/8063ce41d0278dcea3414f5b80779d552c3203b5 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_CheckEvents.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/ES_CheckEvents.o.d" -o ${OBJECTDIR}/_ext/78702576/ES_CheckEvents.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_CheckEvents.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/ES_Framework.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Framework.c  .generated_files/flags/default/f5fd9dd7baf6c23f68e64a9ce318224163220207 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_Framework.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/ES_Framework.o.d" -o ${OBJECTDIR}/_ext/78702576/ES_Framework.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Framework.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/ES_KeyboardInput.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_KeyboardInput.c  .generated_files/flags/default/bacc49342e1537f3af3d731aa080be7ee9a295c3 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_KeyboardInput.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/_ext/78702576/ES_KeyboardInput.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_KeyboardInput.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/ES_PostList.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_PostList.c  .generated_files/flags/default/40d377f37dd4d7bd4e5ddcdee1a871edcc608353 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_PostList.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/ES_PostList.o.d" -o ${OBJECTDIR}/_ext/78702576/ES_PostList.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_PostList.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/ES_Queue.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Queue.c  .generated_files/flags/default/bfb6bf9f6b3400eda6f215454e66a6f1fd72fc9a .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_Queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/ES_Queue.o.d" -o ${OBJECTDIR}/_ext/78702576/ES_Queue.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Queue.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/ES_TattleTale.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_TattleTale.c  .generated_files/flags/default/5e1be83d7e5439d89fb086a3e9bc7df5bed0ce05 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_TattleTale.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/ES_TattleTale.o.d" -o ${OBJECTDIR}/_ext/78702576/ES_TattleTale.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_TattleTale.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/ES_Timers.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Timers.c  .generated_files/flags/default/c5c2995fafca5cfbbb2acbf022d9abe72c462f15 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/ES_Timers.o.d" -o ${OBJECTDIR}/_ext/78702576/ES_Timers.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Timers.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/IO_Ports.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/IO_Ports.c  .generated_files/flags/default/5eb20117be4426b9d2d8938c1dbe7935b1e5e0cc .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/78702576/IO_Ports.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/IO_Ports.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/pwm.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/pwm.c  .generated_files/flags/default/d84caac1fea3d26c30761f9a1c22d9a5184d2ef6 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/pwm.o.d" -o ${OBJECTDIR}/_ext/78702576/pwm.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/pwm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
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
	
${OBJECTDIR}/_ext/78702576/ES_CheckEvents.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_CheckEvents.c  .generated_files/flags/default/eec753c5ea5c16c7a1c2d637a535131baa0eb76d .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_CheckEvents.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/ES_CheckEvents.o.d" -o ${OBJECTDIR}/_ext/78702576/ES_CheckEvents.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_CheckEvents.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/ES_Framework.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Framework.c  .generated_files/flags/default/c5d83935053661881a354b5cb3d482e424a549d9 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_Framework.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/ES_Framework.o.d" -o ${OBJECTDIR}/_ext/78702576/ES_Framework.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Framework.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/ES_KeyboardInput.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_KeyboardInput.c  .generated_files/flags/default/d8fbf488b5fec9996a0d721a8fb5f9ea8cacdfda .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_KeyboardInput.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/_ext/78702576/ES_KeyboardInput.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_KeyboardInput.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/ES_PostList.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_PostList.c  .generated_files/flags/default/8d3425d1f18ce3c90fecde5847bfae2c94eb8eee .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_PostList.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/ES_PostList.o.d" -o ${OBJECTDIR}/_ext/78702576/ES_PostList.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_PostList.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/ES_Queue.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Queue.c  .generated_files/flags/default/1c00998860f798ab4a742e21866cc1ef7ba07de0 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_Queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/ES_Queue.o.d" -o ${OBJECTDIR}/_ext/78702576/ES_Queue.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Queue.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/ES_TattleTale.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_TattleTale.c  .generated_files/flags/default/ea25d2ca3f27acc5c348670df9ae41ab30621bf7 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_TattleTale.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/ES_TattleTale.o.d" -o ${OBJECTDIR}/_ext/78702576/ES_TattleTale.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_TattleTale.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/ES_Timers.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Timers.c  .generated_files/flags/default/8e2eda6b2f8e84d86c7b979998fa8235e2e910d3 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/ES_Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/ES_Timers.o.d" -o ${OBJECTDIR}/_ext/78702576/ES_Timers.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/ES_Timers.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/IO_Ports.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/IO_Ports.c  .generated_files/flags/default/5b4e2e980e413fd03a40d33fc6507d48bd5fef59 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/78702576/IO_Ports.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/IO_Ports.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/78702576/pwm.o: C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/pwm.c  .generated_files/flags/default/596c58ad39fcdf3e804a9ce62e9826c60978833 .generated_files/flags/default/25cf332145e109ecc94cb8c88ed46e464b66686
	@${MKDIR} "${OBJECTDIR}/_ext/78702576" 
	@${RM} ${OBJECTDIR}/_ext/78702576/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/78702576/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X" -MP -MMD -MF "${OBJECTDIR}/_ext/78702576/pwm.o.d" -o ${OBJECTDIR}/_ext/78702576/pwm.o C:/Users/seens/OneDrive/Desktop/ECE_118_Final_Project/Final_Project_Bot.X/pwm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
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