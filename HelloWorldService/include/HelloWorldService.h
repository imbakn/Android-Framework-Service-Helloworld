#ifndef HELLO_WORLD_SERVICE_H
#define HELLO_WORLD_SERVICE_H

#include <binder/Parcel.h>
#include <utils/Log.h>
#include <include/IHelloWorldService.h>

namespace android {

	class HelloWorldService : public BnHelloWorldService
	{
		public:
			static void instantiate();
			virtual status_t helloWorld(const char* str);
			virtual status_t onTransact(uint32_t code,const Parcel& data, Parcel * reply, uint32_t flags );
		private:
			HelloWorldService();
			virtual ~HelloWorldService();
	};
};

#endif //HELLO_WORLD_SERVICE_H
