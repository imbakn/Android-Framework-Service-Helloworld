#define LOG_TAG "main_helloworldservice"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include <include/HelloWorldService.h>

using namespace android;

int main(int argc,char ** argv)
{
	HelloWorldService::instantiate();
	ProcessState::self()->startThreadPool();

	IPCThreadState::self()->joinThreadPool();
	return 0;
}
