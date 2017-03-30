//
// Created by mat on 29.03.17.
//
#include <iostream>
#include <cstdint>
#include <algorithm>
#include "MemoryChunk.h"

namespace mc {
    MemoryChunk::MemoryChunk(size_t sz) {
        howbig_ = sz;
        mem_ = new int8_t[sz];
    }

    MemoryChunk::~MemoryChunk() {
        delete mem_;
    }

    int8_t *MemoryChunk::MemoryAt(size_t offset) const {
        if (offset<howbig_)
            return &mem_[offset];
        else
            return 0;
    }

    size_t MemoryChunk::ChunkSize() const {
        return howbig_;
    }

    //kostruktor przenoszenia- potwierdzony przez testy
    //mm to jest to co posiada wartości, kßóre trzeba przenieść
    MemoryChunk::MemoryChunk(MemoryChunk &&mm) {
        mem_ = nullptr;
        //tak nie zadziała: mm.howbig_=howbig_
        auto &tmp=mm;
        howbig_=0;
        std::swap(howbig_, tmp.howbig_);
        std::swap(mem_, mm.mem_);
    }

    //kostruktor kopiujący- niewiem czy działa
    MemoryChunk::MemoryChunk(const MemoryChunk &mm) {
//        size_t sz = mm.ChunkSize();
        this->howbig_ = mm.howbig_;
        mem_ = new int8_t[howbig_];
        std::copy(mm.mem_, mm.mem_ + howbig_, mem_);
    }

    //operator kopiujący- niewiem czy działa
    MemoryChunk &MemoryChunk::operator=(MemoryChunk &&mm) {
        if (this == &mm)
            return mm;
        delete[] mem_;
        mem_ = nullptr;
        auto &tmp=mm;
        howbig_=0;
        std::swap(howbig_, tmp.howbig_);
        std::swap(mem_, mm.mem_);
    }

    //operator przenoszący- niewiem czy działa
    MemoryChunk &MemoryChunk::operator=(const MemoryChunk &mm) {
        if (this == &mm)
            return *this;
        delete[] mem_;
//        size_t sz = mm.ChunkSize();
        howbig_ = mm.howbig_;
        mem_ = new int8_t[howbig_];
        std::copy(mm.mem_, mm.mem_ + howbig_, mem_);
    }

}