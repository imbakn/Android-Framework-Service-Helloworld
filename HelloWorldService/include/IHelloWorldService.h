#ifndef IHELLO_WORLD_SERVICE_H
#define IHELLO_WORLD_SERVICE_H

#include <stdint.h>
#include <sys/types.h>

#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android {

	class IHelloWorldService: public IInterface {

		public:
		//服务接口宏
		DECLARE_META_INTERFACE(HelloWorldService);
		//服务函数
		virtual status_t helloWorld(const char *str) = 0;

	};


	class BnHelloWorldService : public BnInterface<IHelloWorldService>
	{
		public:
			virtual status_t onTransact(uint32_t code,const Parcel& data, Parcel * reply, uint32_t flags = 0);
	};
} ;//namespace android
#endif //IHELLO_WORLD_SERVICE_H
