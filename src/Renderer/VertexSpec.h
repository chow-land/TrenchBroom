/*
 Copyright (C) 2010-2013 Kristian Duske
 
 This file is part of TrenchBroom.
 
 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with TrenchBroom.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __TrenchBroom__VertexSpec__
#define __TrenchBroom__VertexSpec__

#include "Vec.h"
#include "GL/GL.h"
#include "Renderer/AttributeSpec.h"
#include "Renderer/Vertex.h"

#include <vector>

namespace TrenchBroom {
    namespace Renderer {
        template <typename A1>
        class VertexSpec1 {
        public:
            typedef Vertex1<A1> Vertex;
            static const size_t Size;
        public:
            static void setup(const size_t baseOffset) {
                A1::setup(0, Size, baseOffset);
            }
            
            static void cleanup() {
                A1::cleanup(0);
            }
        private:
            VertexSpec1();
        };
        
        template <typename A1>
        const size_t VertexSpec1<A1>::Size = A1::Size;

        template <typename A1, typename A2>
        class VertexSpec2 {
        public:
            typedef Vertex2<A1, A2> Vertex;
            static const size_t Size;
        public:
            static void setup(const size_t baseOffset) {
                size_t offset = baseOffset;
                A1::setup(0, Size, offset);
                offset += A1::Size;
                A2::setup(1, Size, offset);
                offset += A2::Size;
            }
            
            static void cleanup() {
                A2::cleanup(1);
                A1::cleanup(0);
            }
        private:
            VertexSpec2();
        };
        
        template <typename A1, typename A2>
        const size_t VertexSpec2<A1, A2>::Size = A1::Size + A2::Size;

        template <typename A1, typename A2, typename A3>
        class VertexSpec3 {
        public:
            typedef Vertex3<A1, A2, A3> Vertex;
            static const size_t Size;
        public:
            static void setup(const size_t baseOffset) {
                size_t offset = baseOffset;
                A1::setup(0, Size, offset);
                offset += A1::Size;
                A2::setup(1, Size, offset);
                offset += A2::Size;
                A3::setup(2, Size, offset);
                offset += A3::Size;
            }
            
            static void cleanup() {
                A3::cleanup(2);
                A2::cleanup(1);
                A1::cleanup(0);
            }
        private:
            VertexSpec3();
        };
        
        template <typename A1, typename A2, typename A3>
        const size_t VertexSpec3<A1, A2, A3>::Size = A1::Size + A2::Size + A3::Size;

        template <typename A1, typename A2, typename A3, typename A4>
        class VertexSpec4 {
        public:
            typedef Vertex4<A1, A2, A3, A4> Vertex;
            static const size_t Size;
        public:
            static void setup(const size_t baseOffset) {
                size_t offset = baseOffset;
                A1::setup(0, Size, offset);
                offset += A1::Size;
                A2::setup(1, Size, offset);
                offset += A2::Size;
                A3::setup(2, Size, offset);
                offset += A3::Size;
                A4::setup(3, Size, offset);
                offset += A4::Size;
            }
            
            static void cleanup() {
                A4::cleanup(3);
                A3::cleanup(2);
                A2::cleanup(1);
                A1::cleanup(0);
            }
        private:
            VertexSpec4();
        };
        
        template <typename A1, typename A2, typename A3, typename A4>
        const size_t VertexSpec4<A1, A2, A3, A4>::Size = A1::Size + A2::Size + A3::Size + A4::Size;

        template <typename A1, typename A2, typename A3, typename A4, typename A5>
        class VertexSpec5 {
        public:
            typedef Vertex5<A1, A2, A3, A4, A5> Vertex;
            static const size_t Size;
        public:
            static void setup(const size_t baseOffset) {
                size_t offset = baseOffset;
                A1::setup(0, Size, offset);
                offset += A1::Size;
                A2::setup(1, Size, offset);
                offset += A2::Size;
                A3::setup(2, Size, offset);
                offset += A3::Size;
                A4::setup(3, Size, offset);
                offset += A4::Size;
                A5::setup(4, Size, offset);
                offset += A5::Size;
            }
            
            static void cleanup() {
                A5::cleanup(4);
                A4::cleanup(3);
                A3::cleanup(2);
                A2::cleanup(1);
                A1::cleanup(0);
            }
        private:
            VertexSpec5();
        };
        
        template <typename A1, typename A2, typename A3, typename A4, typename A5>
        const size_t VertexSpec5<A1, A2, A3, A4, A5>::Size = A1::Size + A2::Size + A3::Size + A4::Size + A5::Size;

        namespace VertexSpecs {
            typedef VertexSpec1<AttributeSpecs::P3> P3;
            typedef VertexSpec2<AttributeSpecs::P3, AttributeSpecs::C4> P3C4;
            typedef VertexSpec3<AttributeSpecs::P3, AttributeSpecs::N, AttributeSpecs::T02> P3NT2;
        }
    }
}

#endif /* defined(__TrenchBroom__VertexSpec__) */
