cmake_minimum_required(VERSION 3.6)
project(DnD)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/main/controller/interactable/godmode/GodmodeChestController.cpp
    src/main/controller/interactable/godmode/GodmodeChestController.h
    src/main/controller/interactable/godmode/GodmodeFighterController.cpp
    src/main/controller/interactable/godmode/GodmodeFighterController.h
    src/main/controller/interactable/godmode/GodmodeFriendlyNpcController.cpp
    src/main/controller/interactable/godmode/GodmodeFriendlyNpcController.h
    src/main/controller/interactable/godmode/GodmodeHostileNpcController.cpp
    src/main/controller/interactable/godmode/GodmodeHostileNpcController.h
    src/main/controller/interactable/godmode/GodmodeInteractableController.cpp
    src/main/controller/interactable/godmode/GodmodeInteractableController.h
    src/main/controller/map/godmode/GodmodeMapMainViewController.h
    src/main/helper/ViewHelper.cpp
    src/main/helper/ViewHelper.h
    src/main/model/interactable/header/Active.h
    src/main/model/interactable/header/ActiveBuilder.h
    src/main/model/interactable/header/Chest.h
    src/main/model/interactable/header/Fighter.h
    src/main/model/interactable/header/FriendlyNpc.h
    src/main/model/interactable/header/HostileNpc.h
    src/main/model/interactable/header/Interactable.h
    src/main/model/interactable/header/Passive.h
    src/main/model/interactable/source/Active.cpp
    src/main/model/interactable/source/ActiveBuilder.cpp
    src/main/model/interactable/source/Chest.cpp
    src/main/model/interactable/source/Fighter.cpp
    src/main/model/interactable/source/FriendlyNpc.cpp
    src/main/model/interactable/source/HostileNpc.cpp
    src/main/model/interactable/source/Interactable.cpp
    src/main/model/interactable/source/Passive.cpp
    src/main/model/Location.cpp
    src/main/model/Location.h
    src/main/view/interactable/godmode/GodmodeChestView.cpp
    src/main/view/interactable/godmode/GodmodeChestView.h
    src/main/view/interactable/godmode/GodmodeFighterView.cpp
    src/main/view/interactable/godmode/GodmodeFighterView.h
    src/main/view/interactable/godmode/GodmodeFriendlyNpcView.cpp
    src/main/view/interactable/godmode/GodmodeFriendlyNpcView.h
    src/main/view/interactable/godmode/GodmodeHostileNpcView.cpp
    src/main/view/interactable/godmode/GodmodeHostileNpcView.h
    src/main/view/interactable/godmode/GodmodeInteractableView.cpp
    src/main/view/interactable/godmode/GodmodeInteractableView.h
    src/main/view/map/godmode/GodmodeMapMainView.h
    src/main/Main.cpp)

add_executable(DnD ${SOURCE_FILES})