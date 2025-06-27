#include "rna_transcription.h"

namespace rna_transcription {

	char to_rna(char c) {
		switch (c) {
			case 'G': return 'C';
			case 'C': return 'G';
			case 'T': return 'A';
			case 'A': return 'U';
		}
	}

	std::string to_rna(std::string s) {
		for (auto& c : s) c = to_rna(c);
		return s;
	}

}  // namespace rna_transcription
