#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H
#include <algorithm>
#include <vector>
#include <string>

namespace protein_translation {

	static std::vector<std::pair<std::string, std::vector<std::string>>> strands = {
		{ "Methionine",    { "AUG" } },
		{ "Phenylalanine", { "UUU", "UUC" } },
		{ "Leucine",       { "UUA", "UUG" } },
		{ "Serine",        { "UCU", "UCC", "UCA", "UCG" } },
		{ "Tyrosine",      { "UAU", "UAC" } },
		{ "Cysteine",      { "UGU", "UGC" } },
		{ "Tryptophan",    { "UGG" } },
		{ "ABORT",         { "UAA", "UAG", "UGA" } }
	};

	std::vector<std::string> proteins(std::string);

}  // namespace protein_translation

#endif // PROTEIN_TRANSLATION_H
