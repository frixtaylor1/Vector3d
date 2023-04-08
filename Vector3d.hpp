//	Copyright 2023 Kevin Daniel Taylor (frixtaylor1)
//	Contact: kevinmusic123@gmail.com
//	for more information about the license, see the end of the file.

#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <math.h>
#include <sstream>

template <typename ItemType>
float powSqr(ItemType value)
{
    return value * value;
}

template <typename ItemType>
class Vector3d
{
public:
    Vector3d() noexcept = default;
    Vector3d(ItemType ax, ItemType ay, ItemType az) noexcept
        : m_ax(ax), m_ay(ay), m_az(az)
    {}

    std::string toString() const noexcept
    {
        std::stringstream stream;
        stream << getAx() << " " << getAy() << " " << getAz();
        return stream.str();
    }

    constexpr const float dotProduct(Vector3d const& rhs) const noexcept
    {
        return { m_ax * rhs.m_ax + m_ay * rhs.m_ay + m_az * rhs.m_az };
    }

    constexpr const Vector3d crossProduct(Vector3d const& rhs) const noexcept
    {
        return {
            m_ay * rhs.m_az - m_az * rhs.m_ay,
            m_az * rhs.m_ax - m_ax * rhs.m_az,
            m_ax * rhs.m_ay - m_ay * rhs.m_ax
        };
    }

    constexpr const Vector3d unit() const noexcept
    {
        float magn = magnitude();
        return {
            m_ax / magn, 
            m_ay / magn, 
            m_az / magn
        };
    }

    constexpr float magnitude() const noexcept
    {
        return { (float)sqrt( powSqr(m_ax) + powSqr(m_ay) + powSqr(m_az) ) };
    }

    // Space-Ship operator <CXX 20>
    constexpr auto operator <=> ( const Vector3d& rhs) const noexcept = default;

    constexpr const Vector3d operator + (Vector3d const& rhs) const noexcept
    {
        return { 
            m_ax + rhs.m_ax, 
            m_ay + rhs.m_ay,
            m_az + rhs.m_az 
        };
    }

    constexpr const Vector3d operator - (Vector3d const& rhs) const noexcept
    {
        return { 
            m_ax - rhs.m_ax, 
            m_ay - rhs.m_ay,
            m_az - rhs.m_az 
        };
    }

    constexpr const Vector3d operator * (ItemType scalar) const noexcept
    {
        return {
            scalar * m_ax,
            scalar * m_ay,
            scalar * m_az
        };
    }

    constexpr const float getAx() const noexcept
    {
        return m_ax;
    }

    constexpr const float getAy() const noexcept
    {
        return m_ay;
    }

    constexpr const float getAz() const noexcept
    {
        return m_az;
    }
    
private:
    ItemType m_ax, m_ay, m_az;
};

template <typename ItemType>
std::ostream& operator << (std::ostream& stream, const Vector3d<ItemType>& vec)
{
    stream << vec.toString();
    return stream;
}

#endif // VECTOR3D_HPP

// MIT License
// 
// Copyright (c) 2023 Kevin Daniel Taylor (frixtaylor1)
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
