#ifndef TUPLE0_HPP_
#define TUPLE0_HPP_

#include <type_traits>

template<typename... Types>
class Tuple;

template<typename Head, typename... Tail>
class Tuple<Head, Tail...> {
private:
    Head head;
    Tuple<Tail...> tail;

public:
// constructors:
    Tuple() {
    }

    Tuple(Head const& head, Tuple<Tail...> const& tail)
      : head(head), tail(tail) {
    }

    template<typename VHead, typename... VTail, 
            typename = std::enable_if_t<sizeof...(VTail) == sizeof...(Tail)>>
    Tuple(VHead&& vhead, VTail&&... vtail) :
        head(std::forward<VHead>(vhead)),
        tail(std::forward<VTail>(vtail)...) {
    }

    template<typename VHead, typename... VTail,
            typename = std::enable_if_t<sizeof...(VTail) == sizeof...(Tail)>>
    Tuple(Tuple<VHead, VTail...> const& other) : 
        head(other.getHead()), tail(other.getTail()) { }

    Head& getHead() { return head; }
    Head const& getHead() const { return head; }
    Tuple<Tail...>& getTail() { return tail; }
    Tuple<Tail...> const& getTail() const { return tail; }
};

template<>
class Tuple<> {
    // no storage required
};


#endif