#ifndef GAME_UTILITY_TUPLE_H_
#define GAME_UTILITY_TUPLE_H_

#include <tuple>

class Tuple {
public:
    template<typename Tuple, typename F>
    static constexpr decltype(auto) forEach(Tuple&& tuple, F&& f) {
        using TupleSize = std::tuple_size<std::remove_reference_t<Tuple>>;
        return []<std::size_t... I>(Tuple&& tuple, F&& f, std::index_sequence<I...>) {
            (f(std::get<I>(tuple)), ...);
            return f;
        }(std::forward<Tuple>(tuple), std::forward<F>(f),
          std::make_index_sequence<TupleSize::value>{});
    }
};

#endif //GAME_UTILITY_TUPLE_H_