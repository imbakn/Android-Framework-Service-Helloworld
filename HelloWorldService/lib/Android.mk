LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	IHelloWorldService.cpp \
	HelloWorldService.cpp


LOCAL_SHARED_LIBRARIES:= \
	libcutils \
	libutils \
	libbinder

LOCAL_C_INCLUDES += \
	$(LOCAL_PATH)/../

LOCAL_MODULE:=libhelloworld

include $(BUILD_SHARED_LIBRARY)
