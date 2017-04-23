//
//  Color.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef COLOR_H
#define COLOR_H

namespace engine
{
    namespace utils
    {
        class Color
        {

        private:
            float content_[4];

        public:

            Color();
            Color(const Color& o);
            Color(float r, float g, float b, float a);
            Color& operator=(const Color& o);

            float r() const;
            float g() const;
            float b() const;
            float a() const;

            void setR(float value);
            void setG(float value);
            void setB(float value);
            void setA(float value);
            void set(float r, float g, float b);
            void set(float r, float g, float b, float a);

            Color& operator+=(const Color& o);
            Color& operator-=(const Color& o);
            Color& operator*=(const Color& o);
            Color& operator*=(const float o);
            Color& operator/=(const float o);

            const Color operator+(const Color& o) const;
            const Color operator-(const Color& o) const;
            const Color operator*(const Color& o) const;
            const Color operator*(const float o) const;
            const Color operator/(const float o) const;

            Color& AddEq(const Color& o);
            Color& SubEq(const Color& o);
            Color& MultEq(const Color& o);
            Color& MultEq(const float o);
            Color& DivEq(const float o);
            const Color Add(const Color& o) const;
            const Color Sub(const Color& o) const;
            const Color Mult(const Color& o) const;
            const Color Mult(const float o) const;
            const Color Div(const float o) const;
        };
    }
}
#endif // COLOR_H
