#pragma once

namespace dina {
    class Dummy {
    public:
        inline Dummy() = default;
        virtual ~Dummy() = default;

        void print();
    };
}