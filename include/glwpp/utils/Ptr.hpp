#include <memory>

namespace glwpp {

template<class T>
using sptr = std::shared_ptr<T>;

template<class T>
using wptr = std::weak_ptr<T>;

template<class T>
using uptr = std::unique_ptr<T>;

}