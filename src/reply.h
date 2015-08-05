// Copyright 2012, Camilo Aguilar. Cloudescape, LLC.
#ifndef SRC_REPLY_H_
#define SRC_REPLY_H_
#include "node_fuse.h"

namespace NodeFuse {
    class Reply : public ObjectWrap {
        friend class FileSystem;

        public:
            static void Initialize(Handle<Object> target);

            Reply();
            virtual ~Reply();
            static NAN_METHOD(New);

        protected:
            static NAN_METHOD(Entry);
            static NAN_METHOD(Attributes);
            static NAN_METHOD(ReadLink);
            static NAN_METHOD(Error);
            static NAN_METHOD(Open);
            static NAN_METHOD(Buffer);
            static NAN_METHOD(Write);
            static NAN_METHOD(StatFs);
            static NAN_METHOD(Create);
            static NAN_METHOD(XAttributes);
            static NAN_METHOD(Lock);
            static NAN_METHOD(BMap);
            static NAN_METHOD(AddDirEntry);

        private:
            fuse_req_t request;
            size_t dentry_acc_size;
            size_t dentry_cur_length;
            size_t dentry_offset;
            size_t dentry_size;
            char* dentry_buffer;
            static Nan::Persistent<Function> constructor;
    };
} //namespace NodeFuse

#endif  // SRC_REPLY_H
