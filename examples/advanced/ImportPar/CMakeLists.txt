 ################################################################################
 #    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    #
 #                                                                              #
 #              This software is distributed under the terms of the             # 
 #         GNU Lesser General Public Licence version 3 (LGPL) version 3,        #  
 #                  copied verbatim in the file "LICENSE"                       #
 ################################################################################
# Create a library called "libMbsTutorial" 

set(INCLUDE_DIRECTORIES
${BASE_INCLUDE_DIRECTORIES}
${CMAKE_SOURCE_DIR}/base/steer
${CMAKE_SOURCE_DIR}/parbase
${CMAKE_SOURCE_DIR}/fairtools
${CMAKE_SOURCE_DIR}/examples/advanced/ImportPar
${CMAKE_SOURCE_DIR}/examples/advanced/ImportPar/source
)

Set(SYSTEM_INCLUDE_DIRECTORIES
${SYSTEM_INCLUDE_DIRECTORIES}
)

include_directories(${INCLUDE_DIRECTORIES})
include_directories(SYSTEM ${SYSTEM_INCLUDE_DIRECTORIES})

set(LINK_DIRECTORIES
${ROOT_LIBRARY_DIR}
) 

link_directories(${LINK_DIRECTORIES})

Set(SRCS
source/FairExtPar.cxx
source/FairInputContainer.cxx
source/FairOutputContainer.cxx
source/FairTestFactory.cxx
source/FairReadParTask.cxx
source/FairDrawTask.cxx
)

CHANGE_FILE_EXTENSION(*.cxx *.h HEADERS "${SRCS}")

Set(LINKDEF source/ImportParLinkDef.h)
Set(LIBRARY_NAME ImportPar)

Set(DEPENDENCIES
Base ParBase FairTools
)

GENERATE_LIBRARY()

#add_subdirectory(macro)

