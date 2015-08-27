LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	main_HelloWorldClient.cpp

LOCAL_SHARED_LIBRARIES:= \
	libhelloworld \
	libutils \
	libbinder \
	liblog

LOCAL_C_INCLUDES += \
	$(LOCAL_PATH)/../

LOCAL_MODULE:=helloworlclient

LOCAL_REQUIRED_MODULES := libhelloworld

include $(BUILD_EXECUTABLE)
