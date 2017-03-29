//
// Created by mat on 29.03.17.
//
#include <cstdint>
#include <algorithm>
#include "MemoryChunk.h"

namespace memorychunk {
    MemoryChunk::MemoryChunk(size_t sz) {
        memsize_=sz;
        chunksize_=sizeof(int);
    }

    int8_t *MemoryAt(size_t offset) const {
        int8_t *mem=new(offset);
        return mem;
    }

    size_t ChunkSize() const {

    }

}