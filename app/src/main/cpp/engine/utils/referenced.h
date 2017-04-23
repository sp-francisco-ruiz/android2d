//
//  Referenced.h
//
//  Created by Francisco Ruiz.
//
//

#ifndef REFERENCED_H
#define REFERENCED_H

#include <cassert>
#include <memory>

namespace engine
{
    namespace utils
    {
        class Referenced
        {
        public:

            void ref()
            {
                _refCount++;
            }

            void unref()
            {
                assert("unref referenced with no references" && _refCount);
                _refCount--;
                if (_refCount == 0)
                {
                    delete this;
                }
            }

            unsigned int getRefCounter() const
            {
                return _refCount;
            }

        protected:

            Referenced() : _refCount(0)
            {
            }

            virtual ~Referenced()
            {
            }

        private:

            unsigned int _refCount;

            Referenced(const Referenced&);
            Referenced& operator=(const Referenced&) = delete;
        };

        template<class T>
        class ref_ptr
        {
        public:

            typedef T element_type;

            ref_ptr() : _ptr(nullptr)
            {
            }

            ref_ptr(T* ptr) : _ptr(ptr)
            {
                if (_ptr)
                {
                    _ptr->ref();
                }
            }

            ref_ptr(const ref_ptr& rp) : _ptr(rp._ptr)
            {
                if (_ptr)
                {
                    _ptr->ref();
                }
            }

            ~ref_ptr()
            {
                if (_ptr)
                {
                    _ptr->unref();
                }
                _ptr = nullptr;
            }

            ref_ptr& operator = (const ref_ptr& rp)
            {
                if (_ptr == rp._ptr)
                {
                    return *this;
                }
                T* tmp_ptr = _ptr;
                _ptr = rp._ptr;
                if (_ptr)
                {
                    _ptr->ref();
                }
                if (tmp_ptr)
                {
                    tmp_ptr->unref();
                }
                return *this;
            }

            inline ref_ptr& operator = (T* ptr)
            {
                if (_ptr == ptr)
                {
                    return *this;
                }
                T* tmp_ptr = _ptr;
                _ptr = ptr;
                if (_ptr)
                {
                    _ptr->ref();
                }
                if (tmp_ptr)
                {
                    tmp_ptr->unref();
                }
                return *this;
            }

            bool operator == (const ref_ptr& rp) const
            {
                return (_ptr == rp._ptr);
            }

            bool operator == (const T* ptr) const
            {
                return (_ptr == ptr);
            }

            friend bool operator == (const T* ptr, const ref_ptr& rp)
            {
                return (ptr == rp._ptr);
            }

            bool operator != (const ref_ptr& rp) const
            {
                return (_ptr != rp._ptr);
            }

            bool operator != (const T* ptr) const
            {
                return (_ptr != ptr);
            }

            friend bool operator != (const T* ptr, const ref_ptr& rp)
            {
                return (ptr != rp._ptr);
            }

            bool operator < (const ref_ptr& rp) const
            {
                return (_ptr < rp._ptr);
            }

            const T& operator*() const
            {
                return *_ptr;
            }

            const T* operator->() const
            {
                return _ptr;
            }

            const T* get() const
            {
                return _ptr;
            }

            T& operator*()
            {
                return *_ptr;
            }

            T* operator->()
            {
                return _ptr;
            }

            T* get()
            {
                return _ptr;
            }

            bool operator!() const
            {
                return _ptr == nullptr;
            }

            bool valid() const
            {
                return _ptr != nullptr;
            }

        private:

            T* _ptr;

        };
    }
}

#endif // REFERENCED_H
