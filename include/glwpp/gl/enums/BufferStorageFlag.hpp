#pragma once

#include "glwpp/gl/api/types.hpp"

namespace glwpp::gl {

enum class BufferStorageFlag : gl::Enum {    
    Dynamic = 0x0100,       // GL_DYNAMIC_STORAGE_BIT The contents of the data store may be updated after creation through calls to glBufferSubData. If this bit is not set, the buffer content may not be directly updated by the client. The data argument may be used to specify the initial content of the buffer's data store regardless of the presence of the GL_DYNAMIC_STORAGE_BIT. Regardless of the presence of this bit, buffers may always be updated with server-side calls such as glCopyBufferSubData and glClearBufferSubData.
    Read = 0x0001,          // GL_MAP_READ_BIT The data store may be mapped by the client for read access and a pointer in the client's address space obtained that may be read from.
    Write = 0x0002,         // GL_MAP_WRITE_BIT The data store may be mapped by the client for write access and a pointer in the client's address space obtained that may be written through.
    Persistent = 0x0040,    // GL_MAP_PERSISTENT_BIT The client may request that the server read from or write to the buffer while it is mapped. The client's pointer to the data store remains valid so long as the data store is mapped, even during execution of drawing or dispatch commands.
    Coherent = 0x0080,      // GL_MAP_COHERENT_BIT Shared access to buffers that are simultaneously mapped for client access and are used by the server will be coherent, so long as that mapping is performed using glMapBufferRange. That is, data written to the store by either the client or server will be immediately visible to the other with no further action taken by the application. In particular,
    ClientStorage = 0x0200  // GL_CLIENT_STORAGE_BIT When all other criteria for the buffer storage allocation are met, this bit may be used by an implementation to determine whether to use storage that is local to the server or to the client to serve as the backing store for the buffer.
};

struct BufferStorageFlagBitfield {
    gl::BitField fields;

    BufferStorageFlagBitfield() : fields(0){};
    BufferStorageFlagBitfield(const BufferStorageFlag& access) : fields(static_cast<gl::BitField>(access)){};
    BufferStorageFlagBitfield(const BufferStorageFlagBitfield& access) : fields(access.fields){};

    BufferStorageFlagBitfield operator|(BufferStorageFlag rhs){
        BufferStorageFlagBitfield res;
        res.fields = static_cast<gl::BitField>(fields) | static_cast<gl::Enum>(rhs);
        return res;
    }

    friend BufferStorageFlagBitfield operator|(BufferStorageFlag lhs, BufferStorageFlag rhs){
        BufferStorageFlagBitfield res;
        res.fields = static_cast<gl::Enum>(lhs) | static_cast<gl::Enum>(rhs);
        return res;
    }

    friend BufferStorageFlagBitfield operator|(BufferStorageFlag lhs, BufferStorageFlagBitfield rhs){
        BufferStorageFlagBitfield res;
        res.fields = static_cast<gl::Enum>(lhs) | static_cast<gl::BitField>(rhs.fields);
        return res;
    }
};

}