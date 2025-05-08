LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CPP_EXTENSION := .cpp .cc
ifeq ($(TARGET_ARCH_ABI), armeabi-v7a)
    LOCAL_MODULE    := GtaSdk
else
    LOCAL_MODULE    := GtaSdk64
endif
LOCAL_SRC_FILES := main.cpp mod/logger.cpp mod/config.cpp include/Events.cpp
ifeq ($(TARGET_ARCH_ABI), armeabi-v7a)
    LOCAL_CFLAGS += -O2 -mfloat-abi=softfp -DNDEBUG -std=c++17
else
    LOCAL_CFLAGS += -O2 -DNDEBUG -std=c++17
endif
LOCAL_LDLIBS += -llog
include $(BUILD_SHARED_LIBRARY)
