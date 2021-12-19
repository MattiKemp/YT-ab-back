cmake_minimum_required(VERSION 3.1)

set(project_name dserver) ## rename your project here

project(${project_name})

set(CMAKE_CXX_STANDARD 11)


#include_directories(src)
#include_directories(/usr/include/mysql/)
#include_directories(/usr/include/postgresql/)
#include_directories(/usr/lib/x86_64-linux-gnu)

add_library(${project_name}-lib
	#/usr/lib/x86_64-linux-gnu
	#data-server/AppComponent.hpp
        data-server/controller/MyController.hpp
        data-server/controller/MyController.cpp
        data-server/db/nb_db.cpp
        data-server/db/nb_db.h
        data-server/db/poolInit.c/
        data-server/db/poolInit.h/
        data-server/clients/GraphApiClient.hpp
        data-server/clients/CCApiClient.hpp
        data-server/dto/MyDTOs.hpp
        data-server/security/salting.cpp
        data-server/security/salting.h
)

target_include_directories(${project_name}-lib PUBLIC data-server)
link_directories("$${CMAKE_CURRENT_LIST_DIR}/dataserver/db")

## link libs

find_package(oatpp              1.3.0 REQUIRED)
#find_package(oatpp-websocket    1.2.5 REQUIRED)
find_package(oatpp-libressl 1.3.0 REQUIRED)
find_package(oatpp-swagger 1.3.0 REQUIRED)
FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

include(FindPkgConfig)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(LibreSSL 3.0.0 REQUIRED)

include(FetchContent)

FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.7.3)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        #PUBLIC oatpp::oatpp-websocket
        PUBLIC oatpp::oatpp-libressl
        PUBLIC oatpp::oatpp-swagger
	#PUBLIC oatpp::oatpp-postgresql
	#PUBLIC mysqlcppconn
	#PUBLIC mysqlclient

        PUBLIC LibreSSL::TLS
        PUBLIC LibreSSL::SSL
        PUBLIC LibreSSL::Crypto
        
        # might not need this anymore
        PUBLIC nlohmann_json::nlohmann_json

        PUBLIC ssl
        PUBLIC crypto

)


# ssl cert
add_definitions(
        -DCERT_PEM_PATH="${CMAKE_CURRENT_LIST_DIR}/cert/temp_key.key"
        -DCERT_CRT_PATH="${CMAKE_CURRENT_LIST_DIR}/cert/temp_cert.crt"
)


add_executable(${project_name}-exe
        data-server/App.cpp
)

target_link_libraries(${project_name}-exe pqnb-lib)
target_link_libraries(${project_name}-exe ${project_name}-lib)
#target_link_libraries(${project_name}-exe pqnb)
add_dependencies(${project_name}-exe ${project_name}-lib)

