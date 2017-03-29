//
// Created by mat on 29.03.17.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <cstdint>
#include <algorithm>

namespace memorychunk {
    class MemoryChunk {
//        Rule ofFive
    public:
        MemoryChunk(size_t sz);

        int8_t *MemoryAt(size_t offset) const;

        size_t ChunkSize() const;

    private:
        size_t memsize_;
        size_t chunksize_;
    };

}
#endif //JIMP_EXERCISES_MEMORYCHUNK_H
