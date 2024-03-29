template<typename T>
struct AddLValueReferenceT {
    using Type = T&;
};

template<typename T>
struct AddRValueReferenceT {
    using Type = T&&;
};

template<>
struct AddLValueReferenceT<void> {
    using Type = void;
};

template<>
struct AddLValueReferenceT<void const> {
    using Type = void const;
};

template<>
struct AddLValueReferenceT<void volatile> {
    using Type = void volatile;
};

template<>
struct AddLValueReferenceT<void const volatile> {
    using Type = void const volatile;
};

template<typename T>
using AddLValueReference = typename AddLValueReferenceT<T>::Type;

template<typename T>
using AddRValueReference = typename AddRValueReferenceT<T>::Type;