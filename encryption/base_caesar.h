#pragma once

namespace encryption {
    class BaseCaesar {
    protected:
        static constexpr int shift = 5;
        static constexpr int ascii_offset = 32;
        static constexpr int ascii_modulo = 96;
    };
}