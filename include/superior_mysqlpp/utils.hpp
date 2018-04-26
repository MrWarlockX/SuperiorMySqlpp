/*
 * Author: Tomas Nozicka
 */

#pragma once


#include <string>
#include <tuple>
#include <utility>


namespace SuperiorMySqlpp
{
    template<typename T, template <typename, typename=std::allocator<T>> class Container>
    inline std::string toString(Container<T> container)
    {
        std::string result{};
        std::size_t i= 0;
        for (auto&& item: container)
        {
            result += std::to_string(item);
            if (++i != container.size())
            {
                result += ", ";
            }
        }

        return result;
    }

<<<<<<< HEAD
    template<class P, class M>
    size_t offsetOf(const M P::*member)
    {
        return (size_t) &(reinterpret_cast<P *>(0)->*member);
    }

    template<class P, class M>
    P *containerOf(M *ptr, const M P::*member)
    {
        return (P *)((char*)ptr - offsetOf(member));
=======
    namespace detail
    {
        /**
         * @brief Invokes function via unpacked tuple
         * @param f Functor to be invoked
         * @param t Tuple of arguments to be unpacked
         */
        template<typename Function, typename Tuple, std::size_t... I>
        auto invokeViaTupleImpl(Function f, const Tuple &t, std::index_sequence<I...>)
        {
            return f(std::get<I>(t)...);
        }
    }

    /**
     * @brief Invokes function via unpacked tuple
     * @param f Functor to be invoked
     * @param t Tuple of arguments to be unpacked
     */
    template<typename Function, typename Tuple>
    auto invokeViaTuple(Function f, const Tuple &t)
    {
        constexpr std::size_t tuple_size = std::tuple_size<Tuple>::value;
        return detail::invokeViaTupleImpl(f, t, std::make_index_sequence<tuple_size>{});
>>>>>>> b82d00f483775a4caf2bdae5aeabb3f8de6c092f
    }
}
