#include <stdint.h>
#include <sys/types.h>

#include <include/IHelloWorldService.h>

namespace android {

enum {
	HW_HELLOWORLD = IBinder::FIRST_CALL_TRANSACTION,
};

class BpHelloWorldService : public BpInterface<IHelloWorldService>
{
	public:
	BpHelloWorldService(const sp<IBinder>& impl)
		:BpInterface<IHelloWorldService>(impl) {}

	status_t helloWorld(const char *str)
	{
		Parcel data,reply;
		data.writeInterfaceToken(IHelloWorldService::getInterfaceDescriptor());
		data.writeCString(str);
		status_t status = remote()->transact(HW_HELLOWORLD,data,&reply);
		if(status != NO_ERROR)
		{
			ALOGE("print helloworld error %s",strerror(-status));
		}
		else
			status = reply.readInt32();
		return status;
	}
};

IMPLEMENT_META_INTERFACE(HelloWorldService,"android.apps.IHelloWorldService");

status_t BnHelloWorldService::onTransact(uint32_t code,const Parcel& data, Parcel * reply, uint32_t flags )
{
	switch(code)
	{
		case HW_HELLOWORLD:{
			//确认为正确的服务请求
			CHECK_INTERFACE(IHelloWorldService,data,reply);
			const char *str;
			//读取来自服务端的字符串
			str = data.readCString();
			//调用输出方法
			reply->writeInt32(helloWorld(str));
			return NO_ERROR;
			
		}break;
		default:
			return BBinder::onTransact(code,data,reply,flags);

	}
}
};
