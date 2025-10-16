# The CMake command include_guard is compatible with CMake version 3.10 and greater.
if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.10.0")
# Preventing this file to be included more than once.
   include_guard(GLOBAL)
endif()

# Complete list of header (.h) files inside the Anybus Protocol. This is
# only used to arrange the files correctly for display in IDEs. 
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
# (The header files are added only to keep the file and directory tree structure.)
if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.19")
    add_library(abcc_abp INTERFACE ${abcc_abp_INCS})
else()
    # CMake versions prior to v3.19 do not allow Interface Library targets with
    # source files. Please note that abcc-abp will not be displayed as its own
    # target in IDE's if cmake version < 3.19 is used.
    add_library(abcc_abp INTERFACE)
    # Fallback to target_sources.
    target_sources(abcc_abp INTERFACE ${abcc_abp_INCS})
endif()

# Keeping the file and directory tree structure of the Anybus Protocol when 
# generating IDE projects.
source_group(TREE ${ABCC_ABP_DIR} PREFIX "abcc-abp" FILES ${abcc_abp_INCS})

# Directories inside the Anybus Protocol containing header (.h) files to be 
# externally accessible created.
set(ABCC_ABP_INCLUDE_DIRS ${ABCC_ABP_DIR}/inc)

# Adding all the Anybus Protocol related header (.h) files to the user host 
# Anybus Protocol library target.
target_include_directories(abcc_abp INTERFACE ${ABCC_ABP_INCLUDE_DIRS})