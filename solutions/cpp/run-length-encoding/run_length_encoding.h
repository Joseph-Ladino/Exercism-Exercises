#pragma once

#include <string>
using std::string;

namespace run_length_encoding {
	string encode(string raw);
	string decode(string encoded);
}  // namespace run_length_encoding
