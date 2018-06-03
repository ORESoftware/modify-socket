
#include <nan.h>
#include <node.h>
#include <string>
#include <regex.h>
#include <sys/socket.h>
//#include <linux/tcp.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>


//using namespace v8;
using namespace std;


void run(const v8::FunctionCallbackInfo<v8::Value>& args) {

    if (args.Length() < 1) {
        Nan::ThrowTypeError("Wrong number of arguments (too few)");
        return;
    }

    if (args.Length() > 1) {
        Nan::ThrowTypeError("Wrong number of arguments (too many)");
        return;
    }

    if (args[0]->IsString()) {
        Nan::ThrowTypeError("First argument to 'modify-socket' must be a file descriptor.");
        return;
    }

    int socket_fd = (int)(args[0]->Int32Value());

//    v8::Int socket_fd(args[0]->ToInt());
//    int socket_fd = args[0];
    int i = 1;

    if(setsockopt(socket_fd, IPPROTO_TCP, TCP_QUICKACK,  (void *)&i, sizeof(i)) < 0){
        printf("setsockopt failed\n");
        args.GetReturnValue().Set(false);
    }
    else{
        args.GetReturnValue().Set(true);
    }


   close(socket_fd);

}

void init(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "run", run);
}

NODE_MODULE(run, init)