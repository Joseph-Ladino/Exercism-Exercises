#if !defined(ISBN_VERIFIER_H)
#define ISBN_VERIFIER_H

#include <string>
#include <sstream>

#define EXERCISM_RUN_ALL_TESTS

namespace isbn_verifier {

    bool is_valid(std::string s);

} // namespace isbn_verifier

#endif // ISBN_VERIFIER_H