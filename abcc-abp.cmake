# The CMake command include_guard is compatible with CMake version 3.10 and greater.
if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.10.0")
# Preventing this file to be included more than once.
   include_guard(GLOBAL)
endif()

# Complete list of source (.h) files inside the Anybus Protocol. 
set(abcc_abp_INCS
   ${ABCC_ABP_DIR}/inc/abp.h
   ${ABCC_ABP_DIR}/inc/abp_add.h
   ${ABCC_ABP_DIR}/inc/abp_asm.h
   ${ABCC_ABP_DIR}/inc/abp_bac.h
   ${ABCC_ABP_DIR}/inc/abp_ccl.h
   ${ABCC_ABP_DIR}/inc/abp_cfn.h
   ${ABCC_ABP_DIR}/inc/abp_ciet.h
   ${ABCC_ABP_DIR}/inc/abp_cipid.h
   ${ABCC_ABP_DIR}/inc/abp_cnt.h
   ${ABCC_ABP_DIR}/inc/abp_cop.h
   ${ABCC_ABP_DIR}/inc/abp_cpc.h
   ${ABCC_ABP_DIR}/inc/abp_cpn.h
   ${ABCC_ABP_DIR}/inc/abp_dev.h
   ${ABCC_ABP_DIR}/inc/abp_dpv0di.h
   ${ABCC_ABP_DIR}/inc/abp_dpv1.h
   ${ABCC_ABP_DIR}/inc/abp_eco.h
   ${ABCC_ABP_DIR}/inc/abp_ect.h
   ${ABCC_ABP_DIR}/inc/abp_eip.h
   ${ABCC_ABP_DIR}/inc/abp_eme.h
   ${ABCC_ABP_DIR}/inc/abp_epl.h
   ${ABCC_ABP_DIR}/inc/abp_er.h
   ${ABCC_ABP_DIR}/inc/abp_etn.h
   ${ABCC_ABP_DIR}/inc/abp_fsi.h
   ${ABCC_ABP_DIR}/inc/abp_fusm.h
   ${ABCC_ABP_DIR}/inc/abp_mdd.h
   ${ABCC_ABP_DIR}/inc/abp_mod.h
   ${ABCC_ABP_DIR}/inc/abp_mqtt.h
   ${ABCC_ABP_DIR}/inc/abp_nwccl.h
   ${ABCC_ABP_DIR}/inc/abp_nwcfn.h
   ${ABCC_ABP_DIR}/inc/abp_nwdpv1.h
   ${ABCC_ABP_DIR}/inc/abp_nwetn.h
   ${ABCC_ABP_DIR}/inc/abp_nwpnio.h
   ${ABCC_ABP_DIR}/inc/abp_opcua.h
   ${ABCC_ABP_DIR}/inc/abp_pnam.h
   ${ABCC_ABP_DIR}/inc/abp_pnio.h
   ${ABCC_ABP_DIR}/inc/abp_safe.h
   ${ABCC_ABP_DIR}/inc/abp_smtp.h
   ${ABCC_ABP_DIR}/inc/abp_soc.h
   ${ABCC_ABP_DIR}/inc/abp_src3.h
   ${ABCC_ABP_DIR}/inc/abp_sync.h
   ${ABCC_ABP_DIR}/inc/abp_time.h
)

# Creating a library target containing the Anybus Protocol.
add_library(abcc_abp EXCLUDE_FROM_ALL ${abcc_abp_INCS})

# Keeping the file and directory tree structure of the Anybus Protocol when 
# generating IDE projects.
source_group(TREE ${ABCC_ABP_DIR} PREFIX "abcc-abp" FILES ${abcc_abp_INCS})

# Directories inside the Anybus Protocol containing include (.h) files to be 
# externally accessible created.
set(ABCC_ABP_INCLUDE_DIRS 
   ${ABCC_ABP_DIR}/inc
   ${ABCC_ABP_DIR}/src
)

# Adding all the Anybus Protocol related include (.h) files to the user host 
# Anybus Protocol library target.
target_include_directories(abcc_abp PRIVATE ${ABCC_ABP_INCLUDE_DIRS})